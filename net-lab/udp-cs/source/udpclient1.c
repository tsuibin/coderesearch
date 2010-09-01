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
    struct sockaddr_in rin;
    char            buf[MAXLINE];
    int             sock_fd;
    char            str[MAXLINE];
    char            sip[INET_ADDRSTRLEN];
    int             n;
    int             address_size;

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
    while ( fgets( str, MAXLINE, stdin ) != NULL )
    {
        sendto( sock_fd, str, strlen( str ) + 1, 0,
                ( struct sockaddr * ) &pin, sizeof( pin ) );
        if ( n == -1 )
        {
            perror( "call to sendto.\n" );
            exit( 1 );
        }

        address_size = sizeof( rin );
        n = recvfrom( sock_fd, buf, MAXLINE, 0, ( struct sockaddr * ) &rin,
                      &address_size );
        if ( n == -1 )
        {
            perror( "call to recvfrom.\n" );
            exit( 1 );
        }
        else
        {
            printf( "Response from %s port %d: %s\n",
                    inet_ntop( AF_INET, &rin.sin_addr, sip, sizeof( sip ) ),
                    ntohs( rin.sin_port ), buf );
        }
    }
    close( sock_fd );
    if ( n == -1 )
    {
        perror( "call to close.\n" );
        exit( 1 );
    }
    return 0;
}
