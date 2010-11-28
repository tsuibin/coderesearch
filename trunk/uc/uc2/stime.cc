#include <iostream> 

using namespace std; 
#include <time.h>
#include <string.h> 
int main(int argc ,char *argv[]) 
{
		time_t t ;
		char buf[100];
		tm* p;

		for(;;){
				t = time(NULL);
				p = localtime(&t);
				strftime(buf,100,"%F 星期%w  %T",p);
				cout <<'\r' << buf <<flush;
				memset(buf,0,100);
				sleep(1);
		}
}
