/*
 * =====================================================================================
 *
 *       Filename:  wrap.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/21/09 14:11:18
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ZhangGuoDong (gdbdzgd), gdbdzgd@gmail.com
 *        Company:  akae
 *
 * =====================================================================================
 */
#include "wrap.h"

void perr_exit(const char *s)
{
	perror(s);
	exit(1);
}

int Accept(int fd, struct sockaddr *sa, socklen_t * salenptr)
{
	int n;
      again:
	if ((n = accept(fd, sa, salenptr)) < 0) {
		if ((errno == ECONNABORTED) || (errno == EINTR))
			goto again;
		else
			perr_exit("bind error");
	}
	return n;

}

void Bind(int fd, const struct sockaddr *sa, socklen_t salen)
{
	if (bind(fd, sa, salen) < 0)
		perr_exit("bind error");
}

void Connect(int fd, const struct sockaddr *sa, socklen_t salen)
{
	if (connect(fd, sa, salen) < 0)
		perr_exit("connect error");
}

void Listen(int fd, int backlog)
{
	if (listen(fd, backlog) < 0)
		perr_exit("listen error");
}

int Socket(int family, int type, int protocol)
{
	int n;
	if ((n = socket(family, type, protocol)) < 0)
		perr_exit("socket error");
	return n;
}

ssize_t Read(int fd, void *ptr, size_t nbytes)
{
	ssize_t n;
      again:
	if ((n = read(fd, ptr, nbytes)) == -1) {
		if (errno == EINTR)
			goto again;
		else
			return -1;

	}
	return n;
}

ssize_t Write(int fd, const void *ptr, size_t nbytes)
{
	ssize_t n;
      again:
	if ((n = write(fd, ptr, nbytes)) == -1) {
		if (errno == EINTR)
			goto again;
		else
			return -1;
	}
	return n;

}

void Close(int fd)
{
	if (close(fd) == -1)
		perr_exit("close error");
}

ssize_t Readn(int fd, void *vptr, size_t n)
{
	size_t nleft;
	ssize_t nread;
	char *ptr;

	ptr = vptr;
	nleft = n;
	while (nleft > 0) {
		if ((nread = read(fd, ptr, nleft)) < 0) {
			if (errno == EINTR)
				nread = 0;
			else
				return -1;
		} else if (nread == 0)
			break;
		nleft -= nread;
		ptr += nread;
	}
	return n - nleft;

}

ssize_t Writen(int fd, const void *vptr, size_t n)
{
	size_t nleft;
	ssize_t nwritten;
	const char *ptr;
	ptr = vptr;
	nleft = n;
	while (nleft > 0) {
		if ((nwritten = write(fd, ptr, nleft)) <= 0) {
			if (nwritten < 0 && errno == EINTR)
				nwritten = 0;
			else
				return -1;
		}
		nleft -= nwritten;
		ptr += nwritten;

	}
	return n;
}

static size_t my_read(int fd, char *ptr)
{
	static int read_cnt;
	static char *read_ptr;
	static char read_buf[100];

	if (read_cnt <= 0) {
	      again:
		if ((read_cnt = read(fd, read_buf, sizeof(read_buf))) < 0) {
			if (errno == EINTR)
				goto again;
			return -1;
		} else if (read_cnt == 0)
			return 0;
		read_ptr = read_buf;
	}
	read_cnt--;
	*ptr = *read_ptr++;
	return 1;
}

ssize_t Readline(int fd, void *vptr, size_t maxlen)
{
	ssize_t n, rc;
	char c, *ptr;
	ptr = vptr;
	for (n = 1; n < maxlen; n++) {
		if ((rc = my_read(fd, &c)) == 1) {
			*ptr++ = c;
			if (c == '\n')
				break;
		} else if (rc == 0) {
			*ptr = 0;
			return n - 1;
		} else
			return -1;
	}
	*ptr = 0;
	return n;
}

// -------------- under function is get config function ----//
// -------------- it will find client.conf to get config ---//
void mstrcpy(char *dst, char *src)
{
	char *p = dst;
	char *q = src;
	while (*q != '\n')
		*p++ = *q++;
	*p = '\0';

}

void interpret(char *confp, char *port, size_t confst_size)
{
	char buf[512];

	char *p = confp, *b = buf;
	int i;
	for (i = 0; i < confst_size; i++) {
		if (*p == '=') {
			*b = '\0';
			//printf("buf:%s\n*b:%s",buf,b);
			if ((0 == strcmp("Port", buf))) {
				mstrcpy(port, ++p);
				printf("get server port: %s\n", port);
				while (*p != '\n')
					p++;
				p++;
				b = buf;
				continue;
			}
			/* 
			   if( (0 == strcmp("Directory", buf))){
			   mstrcpy(root, ++p);
			   printf("get root :%s\n",root);myhttpd
			   *portbuf = '\0';
			   while(*p!= '\n')p++;
			   p++;
			   b = buf;
			   continue;
			   } */

		}
		*b++ = *p++;
		if (*b == EOF)
			break;
	}
}

int getconf(char *port)
{
	int pfd;
	struct stat confst;
	char *confp;

	if (0 > (pfd = open("setport.conf", O_RDONLY))) {
		perror("erro open setport.conf");
		exit(1);
	}
	fstat(pfd, &confst);
	confp = mmap(NULL, confst.st_size, PROT_READ, MAP_SHARED, pfd, 0);
	if (MAP_FAILED == confp) {
		perror("mmap");
		exit(1);
	}
	interpret(confp, port, confst.st_size);

	return 0;

}

void get_filename(char *path, char *buf)
{
	char *p = path;
	char *b = buf;
	while (*p != '\0')
		p++;
	while (*p != '/')
		p--;
	p++;
	while (*p != '\0') {
		*b++ = *p++;
	}
	*b = *p;
}

int getmode(char *argv, char *serpath, char *serip, char *buf)
{
	char *p, *b = buf;
        int i;
	p = argv;
	for (i = 0; i < strlen(argv); i++) {
		if (':' == *p) {
			*b = '\0';
			p += 1;
			strcpy(serip, buf);
			strcpy(serpath, p);
                        printf("serpah %s \n",serpath);
			return -1;
		}
		*b++ = *p++;
	}
	return 0;

}

int prase(char *argv1, char *argv2, int *mode, char *serpath,
	  char *clipath, char *serip)
{
	char buf[BUFLEN], *p, *b = buf;
	struct stat cliisdir;
	int i;

	if (0 > getmode(argv1, serpath, serip, buf)) {
		if (mode) {
			strcpy(clipath, argv2);
                        printf("clipath %s \n",clipath);
			*mode = -1;
		}
	} else if (argv2) {
		if ((argv2 && mode && clipath)) {
			getmode(argv2, serpath, serip, buf);
			strcpy(clipath, argv1);
			*mode = 1;
		}
	}

        if(argv2 && mode && clipath){
                if (0 > stat(clipath, &cliisdir)) {
                        perr_exit("stat clipath");
                }
        }
	if ( (argv2 && mode && clipath)&& (S_ISDIR(cliisdir.st_mode))) {
		b = buf;
		p = clipath, p = p + strlen(clipath) - 1;
		if ('/' != *p)
			strcat(clipath, "/");
		get_filename(serpath, buf);
		strcat(clipath, buf);

	} else {
		printf("argument is not correct!\n");
	}
	printf("serip:%s\n", serip);
	printf("serpath:%s\n", serpath);
	printf("clipath:%s\n", clipath);

	return 0;

}

//parse not use 
/*int parse(char *buf, int  n, char *action , char *root , char *protocol)
{
    char *pbuf = buf;
    char *p[3];
    p[0] = action;
    p[1] = root;
    p[2] = protocol;
    int i ,j = 0;

    for( i = 0; i < n; i++){
        if(*pbuf == ' '){
            p[j] = '\0';
            j++;
            pbuf++;
            
        }

        if(*pbuf == '\r'){
            p[j] = '\0';
            j++;
            break;
        }
   
    *p[j] = *pbuf;
    p[j]++;
    pbuf++;
    } 
}*/
