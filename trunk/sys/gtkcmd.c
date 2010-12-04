#include<stdio.h>
#include<glib.h>

int
main(void)
{
	gchar buf[1][2];
	gchar **stout;
	stout = buf;
	if(g_spawn_command_line_sync("iwconfig eth1 | grep Signal |awk -F" " '{print $4}' | awk -F":" '{print $2}'",stout,NULL,NULL,NULL))
	{
		g_printf("ok\n");
	}else{
		g_printf("has an error\n");
	}
	
	//for( i = 0 ; i < 11 ; i++ ){
	//	g_printf("%s \n" , sout[i]);
	//}
		g_printf("当前的信号 %s \n" ,*stout);


	return 0;
}
