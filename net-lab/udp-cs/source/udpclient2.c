/* udpclient.c */
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
    char            sip[INET_ADDRSTRLEN];
    int             n;

    bzero( &pin, sizeof( pin ) );
    pin.sin_family = AF_INET;
    inet_pton( AF_INET, "127.0.0.1", &pin.sin_addr );
    pin.sin_port = htons( port );

    sock_fd = socket( AF_INET, SOCK_DGRAM, 0 );
    if ( sock_fd == -1 )
    {
        perror( "call to socket" );
        exit( 1 );
    }
    n = connect( sock_fd, ( struct sockaddr * ) &pin, sizeof( pin ) );
    if ( n == -1 )
    {
        perror( "call to connect" );
        exit( 1 );
    }
    else
    {
        printf( "connect to %s port %d OK.\n",
                inet_ntop( AF_INET, &pin.sin_addr, sip, sizeof( sip ) ),
                ntohs( pin.sin_port ) );
    }
    while ( fgets( str, MAXLINE, stdin ) != NULL )
    {
      writeagain:
        n = write( sock_fd, str, strlen( str ) + 1 );
        if ( n == -1 && errno == EINTR )
            goto writeagain;
        else if ( n == -1 )
        {
            perror( "call to write." );
            exit( 1 );
        }
      readagain:
        n = read( sock_fd, buf, MAXLINE );
        if ( n == -1 && errno == EINTR )
            goto readagain;
        else if ( n == -1 )
        {
            perror( "call to read." );
            exit( 1 );
        }
        else
        {
            printf( "Response from connect: %s\n", buf );
        }
    }
    n = close( sock_fd );
    if ( n == -1 )
    {
        perror( "call to close.\n" );
        exit( 1 );
    }

    return 0;
}
