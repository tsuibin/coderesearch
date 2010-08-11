#include <stdio.h>

#include <pthread.h>

#include <stdlib.h>

#include <errno.h>

#include <string.h>

#include <netdb.h>

#include <sys/types.h>

#include <netinet/in.h>

#include <sys/socket.h>

#include <unistd.h>

#define MAXDATASIZE 1000

void *thread(void* test)

{

	int sockfd,numbytes;

	char buf[MAXDATASIZE];

	struct hostent *he;

	struct sockaddr_in their_addr;

	unsigned int myport;

	int i;

	myport = 80;

	for(i=0;i<5;i++){

		if((he=gethostbyname("192.168.0.114"))==NULL){

			perror("gethostbyname");

			exit(1);

		}

		if((sockfd = socket(PF_INET,SOCK_STREAM,0)) == -1){

			perror("socket");

			exit(1);

		}

		their_addr.sin_family=PF_INET;

		their_addr.sin_port=htons(myport);

		their_addr.sin_addr=*((struct in_addr *)he->h_addr);//here is different with RHEL

		bzero(&(their_addr.sin_zero),0);

		if(connect(sockfd,(struct sockaddr *)&their_addr,sizeof(struct sockaddr)) == -1){

			perror("connect");

			exit(1);

		}



		char requestheader[1024];

		memset(requestheader,'\0',1024);

		strcat(requestheader,"GET /\r\n");

		if((numbytes=send(sockfd,requestheader,MAXDATASIZE,0)) == -1){

			perror("send");

			exit(1);

		}

		numbytes=0;

		if((numbytes=recv(sockfd,buf,MAXDATASIZE,0)) ==-1){

			perror("recv");

			exit(1);

		}

		buf[numbytes]=0;

		printf("Received: %s \n thread %d\r\n",buf,i);

		close(sockfd);

	}

}

int main(void)

{

	pthread_t id;

	int i,ret;

	pthread_attr_t attr;

	pthread_attr_init(&attr);

	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);

	for(i=0;i<=5;i++){

		ret=pthread_create(&id,&attr,thread,NULL);

		printf("this is %d\r\n",i);

		if(ret!=0){

			printf("Create pthread error!\n");

			exit(1);

		}

	}

	return 0;

}
