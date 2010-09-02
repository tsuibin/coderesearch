#include "five.h"

struct fb_var_screeninfo vinfo;
struct fb_fix_screeninfo finfo;
long screensize;
int mx = 0;
int my = 0;
short * fbp = 0;

int main (void)
{
	int fp = 0;
	
	//printf ("%d\n", vinfo.);
	fbp = init_fb (fp);
	draw_background ();
	draw_chessboard ();
	mx = vinfo.xres / 2;
	my = vinfo.yres / 2;
	//printf ("mx = %d my = %d\n", mx, my);
	init_mouse ();
	//draw_background ();
	//draw_chessboard ();
	show_mouse ();
	while (1)
	{
		get_mouse_position ();
		//printf ("mx = %d my = %d\n", mx, my);
		show_mouse ();
		
		//draw_chesspiece ();
	}
	//draw_chesspiece (fbp);
	munmap (fbp, screensize);
	close_mouse ();
	close (fp);

	return 0;
}



			
