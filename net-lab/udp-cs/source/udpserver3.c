/* udpserver.c */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#define MAXLINE 80
int             port = 8000;

int
main( void )
{
    struct sockaddr_in sin;
    struct sockaddr_in rin;
    int             sock_fd;
    int             address_size;
    char            buf[MAXLINE];
    char            str[INET_ADDRSTRLEN];
    int             i;
    int             n;
    int             len;
    long            flags;

    bzero( &sin, sizeof( sin ) );
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons( port );

    sock_fd = socket( AF_INET, SOCK_DGRAM, 0 );
    if ( sock_fd == -1 )
    {
        perror( "call to socket" );
        exit( 1 );
    }
    n = bind( sock_fd, ( struct sockaddr * ) &sin, sizeof( sin ) );
    if ( n == -1 )
    {
        perror( "call to bind" );
        exit( 1 );
    }
    flags = fcntl( sock_fd, F_GETFL );
    flags |= O_NONBLOCK;
    if ( fcntl( sock_fd, F_SETFL, flags ) == -1 )
    {
        perror( "trying to set sock_fd to non-blocking" );
        exit( 1 );
    }
    printf( "sock_fd has been set to non-blocking mode.\n" );
    while ( 1 )
    {
        sleep( 3 );
        address_size = sizeof( rin );
        n = recvfrom( sock_fd, buf, MAXLINE, 0, ( struct sockaddr * ) &rin,
                      &address_size );
        if ( n == -1 && errno != EAGAIN )
        {
            perror( "call to recvfrom" );
            exit( 1 );
        }
        else if ( n == 0 || ( n == -1 && errno == EAGAIN ) )    /* no data */
        {
            printf( "no data yet\n" );
            continue;
        }
        else
        {
            printf( "received from client %s at port %d: %s\n",
                    inet_ntop( AF_INET, &rin.sin_addr, str, sizeof( str ) ),
                    ntohs( rin.sin_port ), buf );
        }
        // just convert the characters to upper case
        len = strlen( buf );
        for ( i = 0; i < len; i++ )
            buf[i] = toupper( buf[i] );

        n = sendto( sock_fd, buf, len + 1, 0, ( struct sockaddr * ) &rin,
                    address_size );
        if ( n == -1 && errno != EAGAIN )
        {
            perror( "call to sendto" );
            exit( 1 );
        }


    }
}
