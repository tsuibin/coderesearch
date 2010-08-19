#include <stdio.h>
#include <string.h>
#include "common.h"
/* email format  tom@akaedu.org
 * tom is name,akaedu.org is domain name.
 * name: a-z, 0-9, ".","_"
 * lenght < 32 char
 * domain: a-z,0-9,".","-"
 * domain format see : http://zh.wikipedia.org/wiki/%E5%9F%9F%E5%90%8D
 * lenght < 63 char; 
 *
 */

//tom@akaedu.com
struct email_info{
	int ret;  //=1,is a email,=0 isnot a email
	char name[33]; // name = tom ,name[32]=0
	char domain[64]; //domain name = akaedu.com,name[63]=0
};


int is_digital(char c)
{
	if (c <= '9' && c >= '0')
		return 1;

	return 0;

}

int is_char(char c)
{
	if (c >= 'a' && c <= 'z')
		return 1;
	
	if (c >= 'A' && c <= 'Z')
		return 1;
	
	return 0;
}

int is_underline (char c)
{
	if (c == '_')
		return 1;
	
	return 0;
}

int is_dot (char c)
{
	if (c == '.')
		return 1;

	return 0;

}

int is_hyphen (char c)
{
	if (c == '-')
		return 1;

	return 0;
}

/* tom@akaedu.com 
 * buffer = "tom@akaedu.com"
 * at = "@akaedu.com"
 * we need get "tom"
 */
char * search_name(char *at,char * buffer)
{
	char *tmp;
	
	tmp = at;
	tmp --;
	for (;*tmp != '\0', tmp != buffer;tmp-- )
	{
		if(is_char(*tmp))
			continue;
		if(is_digital(*tmp))
			continue;
		if(is_underline(*tmp))
			continue;
		if(is_dot(*tmp))
			continue;
	
		tmp ++;	
		return tmp;
	}
	
	return tmp;

}

/* tom@akaedu.com 
 * buffer = "tom@akaedu.com"
 * at = "@akaedu.com"
 * we need get "akaedu.com"
 */
char * search_domain(char *at)
{
	char *tmp;
	
	tmp = at;
	tmp ++;
	
	for (;*tmp != '\0';tmp++ )
	{
		if(is_char(*tmp))
			continue;
		if(is_digital(*tmp))
			continue;
		if(is_hyphen(*tmp))
			continue;
		if(is_dot(*tmp))
			continue;
		
		return tmp;
	}
	
	return tmp;

}




/* a-z,0-9,"_","."
 * lenght < 32 char
 * return =0: isn't email;
 * return =1: is a email !!!
 */

int check_name (char *name,int check)
{
	int len = 32;
	int i;
	int ret = 1;

		
	if (!is_char(name[0]))
		return 0;

	if (check)
	{
		i = strlen(name);
	
		if (i>len)
			return 0;
		return 1;
	}

	for (i = 1; name[i] != '\0';i++)
	{
		if(is_char(name[i]))
			continue;
		if(is_digital(name[i]))
			continue;
		if(is_underline(name[i]))
			continue;
		if(is_dot(name[i]))
			continue;
		
		/*error*/
		return 0;
	}
	
	if (i>len )
		return 0;
	
	/*ok */
	return 1;
}

/* a-z,0-9,"-","."
 * length < 64
 * return 1: isn't domain name
 * return 0: is domain name
 *
 */

int check_domain(char *domain,int check)
{
	int len = 64;
	int have_dot = 0;
	int i;

	for (i = 0; domain[i] != '\0';i++)
        {
		if(is_char(domain[i]))
			continue;
                if(is_digital(domain[i]))
			continue;
                if(is_hyphen(domain[i]))
			continue;

                if(is_dot(domain[i]))
		{
			have_dot = 1;
			continue;
		}
                /*error!*/
		return 0;
        }
	if (have_dot == 0)
		return 0;
	
	if (i > len || i < 3)
		return 0;
	
	/*ok*/
	return 1;
}


char * search_one_email (char *data)
{
	char *tmp;
	char *name;
	char *domain;
	int ret,count,have_at = 0;
	struct email_info one_email;

	tmp  = data;
	
	for ( ; *tmp !='\0';tmp++ )
	{
		if (*tmp == '@')
		{	
			have_at = 1;
			break;
		}
	}
	
	if (!have_at)
		return NULL;
	
	name = search_name(tmp,data);

	if (name == NULL)	
		return NULL;

	count = tmp - name ;
	if (count > 32)
		return NULL;
	
	strncpy(one_email.name,name,count);	
	
	one_email.name[count] = 0;
	
	ret = check_name(one_email.name,1);
	if (!ret)
		return NULL;

	domain = search_domain(tmp);
	
	if (domain == NULL)
		return NULL;
	count = domain - tmp - 1;
	
	if (count > 64)
		return NULL;
	tmp ++;
	strncpy(one_email.domain ,tmp,count);	
	one_email.domain[count] = 0;
	ret = check_domain(one_email.domain,1);
	if (!ret)
	     return NULL;

	/*if (use_db){
		char email[200];
		sprintf (email,"%s@%s",one_email.name,one_email.domain);	
        	insert_email(email,use_page,use_domain);
	}*/
	printf("name: %s@%s\n",one_email.name,one_email.domain); 
}

char * search_email(char *data)
{
	char *tmp;
	
	tmp = data;

	for ( ; *tmp !='\0';tmp++ )
	{
		if (*tmp == '@')
		{
			search_one_email(data);
			tmp ++;
			data = tmp;
		}
	}

}
/*
int main(void)
{
	char * email1 = "mailto:tsuibin1@akaedu.org";
	char * email2 = "mailto :tsuibin2@akaedu.org";
	char * email3 = "mailto : tsuibin3@akaedu.org";

	printf("email : %s \n", search_email(email1));
	printf("email : %s \n", search_email(email2));
	printf("email : %s \n", search_email(email3));
}
*/
