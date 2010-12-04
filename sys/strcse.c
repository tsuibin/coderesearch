#include <stdio.h>
int main()
{
	char s[80] = "192.168.1.11    192.168.1.112     192.168.1.223";
	char* ip[80]={'\0'};
	char sep=' ';
	char* p;
	int index=0,j=0;
	p=s;
	ip[index]=s;
	while(*p){
		if(*p == sep){
			if(*(p+1) != *p  ){
				ip[++index]=p+1;
			}

			*p='\0';
		}
		p++;
	}
	printf("\n%d",index);
	for(j=0;j<=index;j++){
		printf("\n%d: %s\n",j,ip[j]);

	}
	return 0;
} 
