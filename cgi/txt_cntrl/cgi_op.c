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

int rmplayer( char *serip, char *port)
{
	struct sockaddr_in seraddr;
	char buf[FD_SETSIZE];
	int sfd;
	sfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&seraddr, sizeof(seraddr));
	seraddr.sin_family = AF_INET;
	inet_pton(AF_INET, serip, &seraddr.sin_addr);	//PF_INET
	seraddr.sin_port = htons(atoi(port));
	connect(sfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
	//trans file to server
	write(sfd, "rmplayer", 8);
	read(sfd, buf, FD_SETSIZE);
        if(0 == strncmp("ok",buf,2))
                printf("restart  mplayer qt ok");
        return 0;

}
int restartqt(char *serip, char *port)
{
	struct sockaddr_in seraddr;
	char buf[FD_SETSIZE];
	int sfd;
	sfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&seraddr, sizeof(seraddr));
	seraddr.sin_family = AF_INET;
	inet_pton(AF_INET, serip, &seraddr.sin_addr);	//PF_INET
	seraddr.sin_port = htons(atoi(port));
	connect(sfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
	//trans file to server
	write(sfd, "restartqt", 9);
	read(sfd, buf, FD_SETSIZE);
        if(0 == strncmp("ok",buf,2))
                printf("restart qt ok");
        return 0;
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
		write(sfd, serpath, strlen(serpath));
	} else {
		printf("un known cmd\n");
		exit(1);
	}

	printf("will begin get file<br> \n");
	read(sfd, buf, FD_SETSIZE);
	if (0 == strncmp("OK", buf, strlen("OK"))) {
		printf("recive %s will trans file<br>\n", buf);
		ofd = open(clipath, O_RDONLY);
		if (ofd < 0)
			perr_exit("open clipath");
		while ((n = read(ofd, buf, FD_SETSIZE)))
			write(sfd, buf, n);
		printf("tranfer end<br>\n");
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
	ofd = open(clipath, O_RDWR | O_CREAT | O_TRUNC, 0777);
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

int get_file_tmp(int tfd, char *serpath, char *serip, char *port)
{
	struct sockaddr_in seraddr;
	char buf[FD_SETSIZE];
	int n;
	int sfd;
        char temp_filename[] = "/tmp/temp_file.XXXXXX";
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

        tfd = mkstemp (temp_filename);

        /*  Unlink the file immediately, so that it will be removed when the
        file descriptor is closed. */
        /* 文件立刻被unlink，这样只要文件描述符一关闭文件就会被自动删除*/
        //unlink (temp_filename);
        /*  Write the number oscriptor as the handle for the temporary file.*/

	//ofd = open(clipath, O_RDWR | O_CREAT | O_TRUNC, 0777);
//	printf("will begin trans\n");
	while ((n = read(sfd, buf, FD_SETSIZE))){
		write(tfd, buf, n);
                write(tfd, buf, n);
        }
//	printf("trasnfer end\n");


	close(sfd);

        /* 函数返回文件描述符，作为临时文件的句柄*/
        return 0;
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
/*--------------------------------------------------
* 
* 
* int main ( int argc, char *argv[] )
* { 
*         //up_file("/home/gdbdzgd/Desktop/a.out", "/home/gdbdzgd/Desktop/b.out","127.0.0.1","8000" );
*         //get_file("data.txt", "/opt/OAK/txts/data.txt","192.168.0.100","8000" );
*         get_file("data.txt", "/opt/OAK/txts/data.txt","192.168.0.100","8080" );
*         get_file("data.txt", "/opt/OAK/playlist","192.168.0.100","8080" );
*         //rm_file("/home/gdbdzgd/Desktop/c.out", "127.0.0.1","8000");
*         
*         
*         return 0;
* }				/ * ----------  end of function main  ---------- * /
*--------------------------------------------------*/
