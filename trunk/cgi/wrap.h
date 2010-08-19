/*
 * =====================================================================================
 *
 *       Filename:  wrap.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/21/09 14:25:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ZhangGuoDong (gdbdzgd), gdbdzgd@gmail.com
 *        Company:  akae
 *
 * =====================================================================================
*/
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <netinet/in.h>

#define BUFLEN 512

int getconf(char *port);

int prase(char *argv1, char *argv2, int *mode, char *serpath,
	  char *clipath, char *serip);
void perr_exit(const char *s);
int Accept(int fd, struct sockaddr *sa, socklen_t * salenptr);
void Bind(int fd, const struct sockaddr *sa, socklen_t salen);
void Connect(int fd, const struct sockaddr *sa, socklen_t salen);
void Listen(int fd, int backlog);
int Socket(int family, int type, int protocol);
ssize_t Read(int fd, void *ptr, size_t nbytes);
ssize_t Write(int fd, const void *ptr, size_t nbytes);
void Close(int fd);
ssize_t Writen(int fd, const void *vptr, size_t n);
ssize_t Readn(int fd, void *vptr, size_t n);
ssize_t Readline(int fd, void *vptr, size_t maxlen);
