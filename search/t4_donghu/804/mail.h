
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#define MAX 1048
#define SIZE 20
extern sqlite3 *db;
extern char *err;
extern int ret;
extern int empty;

char * str_searc(const char *, char);
char * sear_start(const char *);
char * sear_end(const char *);
void putstr(const char *, const char *);
void collect_mail(const char *, const char *, char *);
int rscallback(void *p, int argc, char **argv, char **argvv);
void create_table(void);
void insert_table(int, char *);
void delete_table(int);
void update_table(int, char *);
void select_table(void);

