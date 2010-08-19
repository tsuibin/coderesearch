/*
 * =====================================================================================
 *
 *       Filename:  my_readline.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2010年01月08日 14时48分13秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ZhangGuoDong (gdbdzgd), gdbdzgd@gmail.com
 *        Company:  akaedu
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int my_readline(const char * playlist, char *buf, int line)
{

    FILE * fp;
    int count = 1;
    char str[258];
    char vchar;
    int i = 0;

    if ((fp = fopen(playlist, "r") ) == NULL)
    {
        printf("cannot open file\n");
        exit(0);
    }

    while (!feof(fp))
    {
        vchar = getc(fp);
        if ((count == line) && (vchar != '\n'))
        {
        str[i] = vchar;
        i++;
        str[i] == '\0';
        }
        if (vchar == '\n')
        {
            count++;
        }
        if (count > line)
            break;
    }
    if (line >= count)
    {
        //printf("the line is overflow");
        return -1;
    }
    for ( ; str[i] != '/'; i--)
        ;
    i++;
    while( str[i] != '\0')
    {
        *buf = str[i];
        buf++;
        i++;
    }
    return 1;

}

/*--------------------------------------------------
* 
* int main(void)
* {
*     char * buf;
*     char playlist[258] = "/home/akaedu/test";
* 
*     my_readline(playlist, buf, 2);
* 
*     printf("%s\n", buf);
* 
*     return;
* }
* 
*--------------------------------------------------*/
