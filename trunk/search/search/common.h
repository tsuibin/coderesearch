#ifndef __COMMON_H_
#define __COMMON_H_

struct parse_result
{
	int ret;     //ret = 1,is a link,email,image; = 0 isn't anyone
	char * data; //if ret =1,data = the name;
};

struct weblink{
	char domain[64];
	char *page;
	int page_len;
	int id;
};

extern int use_db;
extern int timeout;
extern char * use_domain;
extern char * use_page;

char   get_char  (char *data);
char * is_string (char *data,char * dst);
char * get_start (char *data);
int    get_end   (char *data);
char * get_line  (void );
char * get_web_buf(void);
struct weblink *get_a_record(void);

#endif  //__COMMON_H_
