/* server.c */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <errno.h>
#define MAXLINE 80
int             port = 8000;

int
main( void )
{
    struct sockaddr_in sin;
    struct sockaddr_in pin;
    int             listen_fd;
    int             conn_fd;
    int             sock_fd;
    int             nready;
    int             client[FD_SETSIZE];
    int             maxi;
    int             maxfd;
    fd_set          rset;
    fd_set          allset;
    int             address_size;
    char            buf[MAXLINE];
    char            str[INET_ADDRSTRLEN];
    int             i;
    int             n;
    int             len;

    bzero( &sin, sizeof( sin ) );
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons( port );

    listen_fd = socket( AF_INET, SOCK_STREAM, 0 );
    if ( listen_fd == -1 )
    {
        perror( "call to socket" );
        exit( 1 );
    }
    {
        int             opt = 1;
        setsockopt( listen_fd, SOL_SOCKET, SO_REUSEADDR, 
	            &opt, sizeof( opt ) );
    }
    n = bind( listen_fd, ( struct sockaddr * ) &sin, sizeof( sin ) );
    if ( n == -1 )
    {
        perror( "call to bind" );
        exit( 1 );
    }
    n = listen( listen_fd, 20 );
    if ( n == -1 )
    {
        perror( "call to listen" ), exit( 1 );
    }
    printf( "Accepting connections ...\n" );

    maxfd = listen_fd;          /* initialize */
    maxi = -1;                  /* index into client[] array */
    for ( i = 0; i < FD_SETSIZE; i++ )
        client[i] = -1;         /* -1 indicates available entry */
    FD_ZERO( &allset );
    FD_SET( listen_fd, &allset );
    
    for ( ;; )
    {
        rset = allset;          /* structure assignment */
        nready = select( maxfd + 1, &rset, NULL, NULL, NULL );
        if ( FD_ISSET( listen_fd, &rset ) )
        {                       /* new client connection */
	    address_size = sizeof( pin );
            conn_fd =
                accept( listen_fd, ( struct sockaddr * ) &pin,
                        &address_size );

            for ( i = 0; i < FD_SETSIZE; i++ )
                if ( client[i] < 0 )
                {
                    client[i] = conn_fd;    /* save descriptor */
                    break;
                }
            if ( i == FD_SETSIZE )
            {
                printf( "too many clients" );
                exit( 1 );
            }
            printf( "new client: %s, port %d\n",
                    inet_ntop( AF_INET, &pin.sin_addr, str, sizeof( str ) ),
                    ntohs( pin.sin_port ) );
            FD_SET( conn_fd, &allset ); /* add new descriptor to set */
            if ( conn_fd > maxfd )
                maxfd = conn_fd;    /* for select */
            if ( i > maxi )
                maxi = i;       /* max index in client[] array */
            if ( --nready <= 0 )
                continue;       /* no more readable descriptors */
        }

        for ( i = 0; i <= maxi; i++ )
        {                       /* check all clients for data */
            if ( ( sock_fd = client[i] ) < 0 )
                continue;
            if ( FD_ISSET( sock_fd, &rset ) )
            {
                n = read( sock_fd, buf, MAXLINE );
                if ( n == 0 )
                {
                    printf( "the other side has been closed.\n" );
                    fflush( stdout );
                    close( sock_fd );
                    FD_CLR( sock_fd, &allset );
                    client[i] = -1;
                }
                else
                {
                    printf( "received from client %d: %s\n", i, buf );
                    // just convert the characters to upper case
                    len = strlen( buf );
                    for ( i = 0; i < len; i++ ) buf[i] = toupper( buf[i] );
                    write( sock_fd, buf, len + 1 );
                }
                if ( --nready <= 0 )
                    break;      /* no more readable descriptors */
            }
        }
    }
}
