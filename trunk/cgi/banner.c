/*
 * =====================================================================================
 *
 *       Filename:  banner.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/07/2010 06:19:07 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ZhangGuoDong (gdbdzgd), gdbdzgd@gmail.com
 *        Company:  akae
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "cgi.h"
#define DEBUG 0

int main(void)
{
	cgi_init();
	cgi_init_headers();
	cgi_process_form();
	printf("<html><head><title>banner</title>\
                <meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">\
                <style type=\"text/css\">\
                .style1 {\
                        color: #FFFFFF;\
                        font-size: 36px;\
                        font-weight: bold;\
                        letter-spacing: 4px;\
                }\
                </style>\
                </head><body leftmargin=\"0\" topmargin=\"0\" bgcolor=\"#0052a4\">\
                <table cellpadding=\"0\" cellspacing=\"0\" height=\"94\" width=\"100%\" border=\"0\">\
                  <tbody><tr> \
                    <td height=\"74\" width=\"100%\">\
                      <table cellpadding=\"0\" cellspacing=\"0\" height=\"100%\" width=\"100%\" border=\"0\">\
                        <tbody><tr align=\"center\">\
                         <td nowrap=\"nowrap\" align=\"center\"><span class=\"style1\">");
	printf("cgi banner");

	printf(" </span></td>\
                        </tr>\
                      </tbody></table> </td>\
                  </tr>\
                  <tr bgcolor=\"#ffffff\"> \
                    <td colspan=\"2\" height=\"5\"> </td>\
                  </tr>\
                  <tr bgcolor=\"#0052a4\"> \
                    <td colspan=\"2\" height=\"15\">&nbsp;</td>\
                  </tr>\
                </tbody></table>\
                </body></html>");
	cgi_end();

	return 0;

}
