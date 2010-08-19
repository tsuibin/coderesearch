/*
 * =====================================================================================
 *
 *       Filename:  cgi_op.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/08/2010 03:50:15 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ZhangGuoDong (gdbdzgd), gdbdzgd@gmail.com
 *        Company:  akae
 *
 * =====================================================================================
 */
int up_file(char *filepath, char *serpath, char *serip, char *port);
int get_file(char *filepath, char *serpath, char *serip, char *port);
int rm_file(char *serpath, char *serip, char *port);
int rmplayer( char *serip, char *port);
int restartqt(char *serip, char *port);

