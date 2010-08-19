#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "wrap.h"

#define MAXLINE 80
#define SERV_PORT 8088

int m_cntrl(char *sendbuf, char *serip)
{
	struct sockaddr_in servaddr;
	//char buf[MAXLINE];
	int sockfd, n;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	inet_pton(AF_INET, serip, &servaddr.sin_addr);
	servaddr.sin_port = htons(SERV_PORT);

	Connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	if (sendbuf) {

		if (0 == strncmp(sendbuf, "getstat",strlen("getstat"))) {
		        Write(sockfd, sendbuf, strlen(sendbuf));
		        n = Read(sockfd, sendbuf, MAXLINE);
			//printf("getstat ok mplayer is %s\n", sendbuf);
                        if (0 == strncmp(sendbuf, "paused",strlen("paused"))) {
                                return 1;
			       //printf("pause ok mplayer is %s \n", sendbuf);
                        } else if (0 == strncmp(sendbuf, "playing",strlen("playing"))) {
                                return 1;
                               //printf("getstat ok mplayer is %s \n", sendbuf);
                        } 
			


		}
                if (0 == strncmp(sendbuf, "pause",strlen("paused"))) {
		        Write(sockfd, sendbuf, strlen(sendbuf));
			//printf("pause ok mplayer is %s \n", sendbuf);

		} 
                if (0 == strncmp(sendbuf, "start",strlen("start"))) {
		        Write(sockfd, sendbuf, strlen(sendbuf));
			//printf("getstat ok mplayer is %s \n", sendbuf);
		}
                if (0 == strncmp(sendbuf, "disable_tv",strlen("disable_tv"))) {
		        Write(sockfd, sendbuf, strlen(sendbuf));
			//printf("disable_tv ok mplayer is %s \n", sendbuf);
                }

                if (0 == strncmp(sendbuf, "enable_tv",strlen("enable_tv"))) {
		        Write(sockfd, sendbuf, strlen(sendbuf));
			//printf("enable_tv ok mplayer is %s \n", sendbuf);
                }

	}
	Close(sockfd);
	return 1;
}
