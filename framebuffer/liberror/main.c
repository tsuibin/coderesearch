#include "comm.h"

 
void print_pic()
{
	link_img p;
	
	for(p = l_img_head; p != NULL; p = p->next)
	{
		

	}
}


int main()
{
	//draw_picture dp[10] = {sircle, leftup_to_rightdown, sircle_district, show_curton };
	//link_img p;
	//screen_info_t screen_inf;
	//init_framebuf(&screen_inf);
//    printdir(DIRPATH,0);

	decode_jpeg("3.jpg", &width, &height); 
//	get_picture_info();		
//	for(p = l_img_head; p != NULL; p = p->next)
//	{
//		dp[rand()%3]( screen_inf, p->img_name);		
//	}
//	sircle(screen_inf);
//	leftup_to_rightdown(screen_inf);
//	sircle_district(screen_inf);
//	 show_curton(screen_inf);
//	print_pic();
 //   printf("done.\n");
	return 0;
}
