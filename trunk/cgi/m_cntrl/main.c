/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/04/2010 02:14:35 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ZhangGuoDong (gdbdzgd), gdbdzgd@gmail.com
 *        Company:  akae
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "wrap.h"
#include "cli.h"

int main ( int argc, char *argv[] )
{
        char serip[] = "192.168.0.100";
        char sendbuf [100] = "getstat";
        sprintf(sendbuf,"%s%c",argv[1],'\0');
        printf("send buf %s\n",argv[1]);
        printf("send buf %s\n",sendbuf);

        if(m_cntrl(sendbuf,serip)){
                if(0 == strncmp(sendbuf,"playing",strlen("playing")))
                        printf("mplayer is playing");
                if(0 == strncmp(sendbuf,"pause",strlen("pause")))
                        printf("mplayer is pause ");
        }



        return 0;
}				/* ----------  end of function main  ---------- */
