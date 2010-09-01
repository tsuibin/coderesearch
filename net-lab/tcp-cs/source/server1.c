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
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons( port );

    listen_fd = socket( AF_INET, SOCK_STREAM, 0 );
    bind( listen_fd, ( struct sockaddr * ) &sin, sizeof( sin ) );
    listen( listen_fd, 20 );
    printf( "Accepting connections ...\n" );

    while ( 1 )
    {
        conn_fd =
            accept( listen_fd, ( struct sockaddr * ) &pin, &address_size );
        read( conn_fd, buf, MAXLINE );

        printf( "received from client %s at port %d: %s\n",
                inet_ntop( AF_INET, &pin.sin_addr, str, sizeof( str ) ),
                ntohs( pin.sin_port ), buf );

        // just convert the characters to upper case
        len = strlen( buf );
        for ( i = 0; i < len; i++ )
        {
            buf[i] = toupper( buf[i] );
        }
        write( conn_fd, buf, len + 1 );
        close( conn_fd );
    }
}
