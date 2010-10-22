/* client.c */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define MAXLINE 80
int             port = 8000;

int
main( int argc, char *argv[] )
{
    struct sockaddr_in pin;
    char            buf[MAXLINE];
    int             sock_fd;
    char           *str = "A default test sting";

    if ( argc > 1 )
    {
        str = argv[1];
    }

    bzero( &pin, sizeof( pin ) );
    pin.sin_family = AF_INET;
    inet_pton( AF_INET, "127.0.0.1", &pin.sin_addr );//转换文本地址为网络二进制码
    pin.sin_port = htons( port );

    sock_fd = socket( AF_INET, SOCK_STREAM, 0 );
    connect( sock_fd, ( void * ) &pin, sizeof( pin ) );
    write( sock_fd, str, strlen( str ) + 1 );
    read( sock_fd, buf, MAXLINE );
    printf( "Response from server: %s\n", buf );
    close( sock_fd );
    return 0;
}
