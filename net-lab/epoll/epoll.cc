#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <iostream>
#include <signal.h>
#include <sys/epoll.h>
#include <stdlib.h> 
#include <string.h>

using namespace std;

#define MAXFDS 256
#define EVENTS 100
#define PORT 8080

int epfd;

bool setNonBlock(int fd)
{
	int flags = fcntl(fd, F_GETFL, 0);
	flags |= O_NONBLOCK;
	if (-1 == fcntl(fd, F_SETFL, flags))
		return false;
	return true;
}

int main(int argc, char *argv[], char *evp[])
{
	int fd, nfds, confd, ret;
	int on = 1;
	char buffer[512];
	struct sockaddr_in saddr, caddr;
	struct epoll_event ev, events[EVENTS];

	if (-1 == (fd = socket(AF_INET, SOCK_STREAM, 0)) )
	{
		cout << "create socket error!" <<endl;
		return -1;
	}

	cout << "fd :" <<  fd << endl; 

	epfd = epoll_create(MAXFDS);

	setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

	bzero( &saddr, sizeof( saddr ) );
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons((short)(PORT));
	saddr.sin_addr.s_addr = INADDR_ANY;
	if ( -1 == bind(fd, (struct sockaddr *)&saddr, sizeof( saddr ) ) )
	{
		cout << " cann't bind socket on server " <<endl;
		return -1;
	}

	if (-1 == listen(fd ,32))
	{
		cout << "listen error" <<endl;
		return -1;
	}

	ev.data.fd = fd;
	ev.events = EPOLLIN;
	epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &ev);
	for(;;)
	{
		nfds = epoll_wait(epfd, events, MAXFDS, 0);
		for( int i = 0; i < nfds; ++i )
		{
			nfds = epoll_wait(epfd, &events[i], MAXFDS, 0);
			if(fd == events[i].data.fd)
			{
				memset(&caddr, 0,sizeof(caddr));
				int len = sizeof(caddr);
				int cfd = accept(fd, (struct sockaddr*)&caddr, (socklen_t *)&len);
				cout << "accept!" <<endl;
				if (-1 == cfd)
				{
					cout << "server has an error, now accept a socket fd" <<endl;
					break;
				}

				setNonBlock(cfd);

				ev.data.fd = cfd;
				ev.events = EPOLLIN;
				epoll_ctl(epfd, EPOLL_CTL_ADD, cfd, &ev);
			}
			else if(events[i].data.fd & EPOLLIN)
			{
				bzero(&buffer, sizeof(buffer));
				cout << "server is ready read"<<endl;
				ret = recv(events[i].data.fd, buffer, sizeof(buffer), 0);

				if(ret < 0)
				{
					cout << "server recvice message size is zero" <<endl;
					return -1;
				}
				else
				{
					cout << "recviced message:" << (char *)buffer << endl;
					ev.data.fd = events[i].data.fd;
					ev.events = EPOLLOUT;
					epoll_ctl(epfd, EPOLL_CTL_MOD, events[i].data.fd, &ev);
				}
			}
			else if (events[i].data.fd & EPOLLOUT)
			{
				bzero(&buffer, sizeof(buffer));
				char message[] = "Tsuibin's High-performance Epoll model";
				bcopy(message, buffer, strlen(message));
				ret = send(events[i].data.fd, buffer, strlen(buffer), 0);
				if(ret < 0)
				{
					cout << "server send message to client has an error" << endl;
					return -1;
				}

				ev.data.fd = events[i].data.fd;
				epoll_ctl(epfd, EPOLL_CTL_DEL, ev.data.fd, &ev);
			}
		}
	}
	if (fd > 0)
	{
		shutdown(fd, SHUT_RDWR);
		close(fd);
	}

	return 0; 
}
