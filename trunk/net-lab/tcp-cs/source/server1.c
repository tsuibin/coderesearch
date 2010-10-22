/* server.c */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define MAXLINE 80
int             port = 8000;

int
main( void )
{
    struct sockaddr_in sin;
    struct sockaddr_in pin;
    int             listen_fd;
    int             conn_fd;
    int             address_size;
    char            buf[MAXLINE];
    char            str[INET_ADDRSTRLEN];
    int             i;
    int             len;

    bzero( &sin, sizeof( sin ) );
    sin.sin_family = AF_INET;//2
    sin.sin_addr.s_addr = INADDR_ANY;//0x00000000
    sin.sin_port = htons( port ); //int port 80

    listen_fd = socket( AF_INET, SOCK_STREAM, 0 );
    bind( listen_fd, ( struct sockaddr * ) &sin, sizeof( sin ) );
    listen( listen_fd, 20 );
    printf( "Accepting connections ...\n" );

    while ( 1 )
    {
        conn_fd =
            accept( listen_fd, ( struct sockaddr * ) &pin, &address_size ); //接受数据 返回链接fd
        read( conn_fd, buf, MAXLINE ); //从链接中读数据

        printf( "received from client %s at port %d: %s\n",
                inet_ntop( AF_INET, &pin.sin_addr, str, sizeof( str ) ),//convert IPv4 and IPv6 addresses from binary to text form
                ntohs( pin.sin_port ), buf ); //convert values between host and network byte order

        // just convert the characters to upper case
        len = strlen( buf );
        for ( i = 0; i < len; i++ )
        {
            buf[i] = toupper( buf[i] );
        }
        write( conn_fd, buf, len + 1 );//向链接中写回数据
        close( conn_fd );//关闭链接
    }
}
