/* client.c */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <stdlib.h>
#define MAXLINE 80
int             port = 8000;

int
main( int argc, char *argv[] )
{
    struct sockaddr_in pin;
    char            buf[MAXLINE];
    int             sock_fd;
    char            str[MAXLINE];
    int             n;

    bzero( &pin, sizeof( pin ) );
    pin.sin_family = AF_INET;
    inet_pton( AF_INET, "127.0.0.1", &pin.sin_addr );
    pin.sin_port = htons( port );

    sock_fd = socket( AF_INET, SOCK_STREAM, 0 );
    if ( sock_fd == -1 )
    {
        perror( "call to socket" );
        exit( 1 );
    }
    n = connect( sock_fd, ( void * ) &pin, sizeof( pin ) );
    if ( n == -1 )
    {
        perror( "call to connect" ), exit( -1 );
    }
    while ( fgets( str, MAXLINE, stdin ) != NULL )
    {
        write( sock_fd, str, strlen( str ) + 1 );
        n = read( sock_fd, buf, MAXLINE );
        if ( n == 0 )
            printf( "the other side has been closed.\n" );
        else
            printf( "Response from server: %s\n", buf );
    }
    close( sock_fd );
    return 0;
}
