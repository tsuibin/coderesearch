/*
 * =====================================================================================
 *
 *       Filename:  up_file.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/08/2010 03:34:12 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ZhangGuoDong (gdbdzgd), gdbdzgd@gmail.com
 *        Company:  akae
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <fcntl.h>
#include "header.h"
#include "wrap.h"

int my_readline(const char * playlist, char *buf, int line)
{

    FILE * fp;
    int count = 1;       /*从文件的第一行开始读取 */
    char str[258];
    char vchar;
    int i = 0;
	 int k = 0;
 
    if ((fp = fopen(playlist, "r") ) == NULL)
    {
       // printf("cannot open file\n");
        exit(0);
    }

    while (!feof(fp))
    {
        vchar = getc(fp);
        if ((count == line) && (vchar != '\n'))
        {
        str[i] = vchar;
        i++;
        str[i] = '\0';
        }
        if (vchar == '\n')
        {
            count++;
        }
        if (count > line)
            break;
    }
    if (line >= count)
    {
       // printf("the line is overflow");
	   return -1;
    }
    for ( ; str[i] != '/'; i--)
        ;
    i++;
    while( str[i] != '\0')
    {
        buf[k] = str[i];
        k++;
        i++;
    }
	
	return 1;

}

int up_file(char *clipath, char *serpath, char *serip, char *port)
{
	struct sockaddr_in seraddr;
	char buf[FD_SETSIZE];
	int n;
	int ofd,sfd;
	sfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&seraddr, sizeof(seraddr));
	seraddr.sin_family = AF_INET;
	inet_pton(AF_INET, serip, &seraddr.sin_addr);	//PF_INET
	seraddr.sin_port = htons(atoi(port));
	connect(sfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
	//trans file to server
	write(sfd, "tans", 5);
	read(sfd, buf, FD_SETSIZE);
	if (0 == strncmp(buf, "path", strlen("path"))) {
	//	printf("server request: %s\n now send filepath:%s\nserpath len is %d\n", buf,serpath,strlen(serpath));
		Write(sfd, serpath, strlen(serpath));
	} else {
		printf("un known cmd\n");
		exit(1);
	}

	printf("will begin get file \n");
	read(sfd, buf, FD_SETSIZE);
	if (0 == strncmp("OK", buf, strlen("OK"))) {
		printf("recive %s will trans file\n", buf);
		ofd = open(clipath, O_RDONLY);
		if (ofd < 0)
			perr_exit("open clipath");
		while ((n = read(ofd, buf, FD_SETSIZE)))
			write(sfd, buf, n);
		printf("tranfer end\n");
	}
        else
                printf("unknow cmd!");


	close(ofd);
	close(sfd);
	return 1;

}

int get_file(char *clipath, char *serpath, char *serip, char *port)
{
	struct sockaddr_in seraddr;
	char buf[FD_SETSIZE];
	int n;
	int ofd, sfd;
	sfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&seraddr, sizeof(seraddr));
	seraddr.sin_family = AF_INET;
	inet_pton(AF_INET, serip, &seraddr.sin_addr);	//PF_INET
	seraddr.sin_port = htons(atoi(port));
	connect(sfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
	//get file from server
	Write(sfd, "get", 4);
	Read(sfd, buf, FD_SETSIZE);
        if(0 == strncmp(buf,"path",strlen("path")));
//	printf("server request: %s\n now send filepath:%s\n", buf, serpath);
	write(sfd, serpath, strlen(serpath));
	ofd = open(clipath, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (ofd < 0)
		perr_exit("open clipath");
//	printf("will begin trans\n");
	while ((n = read(sfd, buf, FD_SETSIZE))){
		write(ofd, buf, n);
        }
//	printf("trasnfer end\n");

	close(ofd);

	close(sfd);

	return 1;
}

int rm_file(char *serpath, char *serip, char *port)
{
	struct sockaddr_in seraddr;
	char buf[FD_SETSIZE];
	int sfd;
	sfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&seraddr, sizeof(seraddr));
	seraddr.sin_family = AF_INET;
	inet_pton(AF_INET, serip, &seraddr.sin_addr);	//PF_INET
	seraddr.sin_port = htons(atoi(port));
	Connect(sfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
	//rm  file on ser
	Write(sfd, "del", 4);
	Read(sfd, buf, FD_SETSIZE);
	if (0 == strncmp(buf, "path", strlen("path"))) {
		printf("server request del \n whill send path: %s\n", serpath);
		Write(sfd, serpath, strlen(serpath));
	}
	close(sfd);
	return 1;
}


		/* ----------  end of function main  ---------- */
