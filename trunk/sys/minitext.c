#include <gtk/gtk.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <wchar.h>

#define HZ(text) (buf = g_locale_to_utf8(text, -1, NULL, NULL, NULL))
/* gcc `pkg-config --cflags --libs gtk+-2.0` text.c -o minitext */
void MessageWindow (gchar * message);
void OnFileSelected (GtkWidget * w, GtkFileSelection * fs);
static void SaveTxtToFile (GtkWidget * button, gpointer func_data);
static int OnOverWrite (void);
void SaveToFile (const gchar * selected_save_path);

gint delete_event (GtkWidget * widget, GdkEvent * event, gpointer data);

/* 全局性Widget */

GtkWidget *FileChooser;
GtkTextBuffer *TextBuffer;
gchar *buf;
/****************/

	void
MessageWindow (gchar * message)
{
	GtkWidget *dialog;
	dialog = gtk_message_dialog_new (NULL,
			GTK_DIALOG_DESTROY_WITH_PARENT,
			GTK_MESSAGE_INFO,
			GTK_BUTTONS_OK, message, NULL);
	gtk_dialog_run (GTK_DIALOG (dialog));
	gtk_widget_destroy (dialog);
}

	static void
SaveTxtToFile (GtkWidget * button, gpointer func_data)
{


	FileChooser = gtk_file_selection_new (HZ ("选择文件"));
	g_free (buf);

	gtk_widget_show (FileChooser);
	g_signal_connect (G_OBJECT (GTK_FILE_SELECTION (FileChooser)->ok_button),
			"clicked",
			G_CALLBACK (OnFileSelected), (gpointer) FileChooser);

	g_signal_connect_swapped (G_OBJECT
			(GTK_FILE_SELECTION (FileChooser)->cancel_button),
			"clicked", G_CALLBACK (gtk_widget_destroy),
			G_OBJECT (FileChooser));
}

	void
OnFileSelected (GtkWidget * w, GtkFileSelection * fs)
{
	const char *selected_save_path;

	gint result;

	selected_save_path =
		gtk_file_selection_get_filename (GTK_FILE_SELECTION (FileChooser));

	if (g_file_test (selected_save_path, G_FILE_TEST_EXISTS) == TRUE)
	{
		gtk_widget_destroy (GTK_WIDGET (FileChooser));
		result = OnOverWrite ();
		switch (result)
		{
			case 1:
				SaveToFile (selected_save_path);
				return;
			case 0:
				return;
		}
	}

	gtk_widget_destroy (GTK_WIDGET (FileChooser));
	SaveToFile (selected_save_path);
	return;
}

	static int
OnOverWrite (void)
{
	GtkWidget *Messager;

	gint Ok;

	Messager = gtk_message_dialog_new (NULL,
			GTK_DIALOG_MODAL,
			GTK_MESSAGE_QUESTION,
			GTK_BUTTONS_YES_NO,
			HZ ("文件已存在,是否替换?"));
	g_free (buf);

	Ok = gtk_dialog_run (GTK_DIALOG (Messager));
	switch (Ok)
	{
		case GTK_RESPONSE_YES:
			gtk_widget_destroy (Messager);
			return 1;
		default:
			gtk_widget_destroy (Messager);
			return 0;
	}
}

	void
SaveToFile (const gchar * selected_save_path)
{
	FILE *fp;
	GtkTextIter start, end;
	gchar *Data, *Data2;

	gtk_text_buffer_get_start_iter (TextBuffer, &start);
	gtk_text_buffer_get_end_iter (TextBuffer, &end);

	fp = fopen (selected_save_path, "w");

	/* 从TextBuffer中得到文本 */
	Data = gtk_text_buffer_get_text (TextBuffer, &start, &end, FALSE);

	/* 将它转换成当地字符串 */
	Data2 = g_locale_from_utf8 (Data, -1, NULL, NULL, NULL);
	fwrite (Data2, strlen (Data2), 1, fp);

	g_free (Data2);
	g_free (Data);

	fclose (fp);
}


	gint
delete_event (GtkWidget * widget, GdkEvent * event, gpointer data)
{
	gtk_main_quit ();
	return FALSE;
}

	int
main (int argc, char *argv[])
{
	GtkWidget *window;
	GtkWidget *view;
	GtkWidget *box;
	GtkWidget *hbox;
	GtkWidget *vscroll;
	GtkWidget *savebutton;
	GtkWidget *align;


	pid_t pid;

#ifndef DEBUG
	/* 后台运行 */
	pid = fork ();
	if (pid > 0)
		exit (0);
#endif

	gtk_init (&argc, &argv);

	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

	gtk_window_set_title (GTK_WINDOW (window), HZ ("迷你记事本"));
	g_free (buf);


	gtk_window_set_position (GTK_WINDOW (window), GTK_WIN_POS_MOUSE);

	/* 窗口缺省大小 400 x 300 */
	gtk_window_set_default_size (GTK_WINDOW (window), 400, 300);
	gtk_window_set_keep_above (GTK_WINDOW (window), 1);
	gtk_container_set_border_width (GTK_CONTAINER (window), 10);
	g_signal_connect (G_OBJECT (window), "delete_event",
			G_CALLBACK (delete_event), NULL);
	/* 新垂直箱子 */
	box = gtk_vbox_new (FALSE, 0);
	gtk_container_add (GTK_CONTAINER (window), box);

	/* 新水平箱子 */
	hbox = gtk_hbox_new (FALSE, 0);

	vscroll = gtk_scrolled_window_new (NULL, NULL);
	/* 自动滚动 */
	gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (vscroll),
			GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

	/* 滚动条需要自行扩大 */
	gtk_box_pack_start (GTK_BOX (box), vscroll, TRUE, TRUE, 1);

	/* 新文本框 */
	view = gtk_text_view_new ();
	gtk_container_add (GTK_CONTAINER (vscroll), view);

	TextBuffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (view));
	/* 字符级回绕 */
	gtk_text_view_set_wrap_mode (GTK_TEXT_VIEW (view), GTK_WRAP_WORD_CHAR);

	/* 保存按钮 */
	savebutton = gtk_button_new_with_label (HZ ("保存"));
	g_free (buf);

	align = gtk_alignment_new(0.5, 0.5, 0.0, 0.0);
	gtk_box_pack_start (GTK_BOX (box), align, FALSE, FALSE, 1);
	gtk_container_add (GTK_CONTAINER (align), savebutton);

	gtk_signal_connect (GTK_OBJECT (savebutton), "clicked",
			GTK_SIGNAL_FUNC (SaveTxtToFile), NULL);

	gtk_widget_show_all (window);

	gtk_main ();
	return 0;
}
