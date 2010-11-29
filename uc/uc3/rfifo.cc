#include <iostream> 
using namespace std; 
#include <sys/stat.h>
#include <string.h> 
#include <fcntl.h>
#include <unistd.h>
int main(int argc ,char *argv[]) 
{
	string fn = "fifo.tmp";
	if( mkfifo(fn.c_str(),0600) < 0 ){
		cerr <<"mkfifo err";
	}

	int fd = open(fn.c_str() ,O_RDONLY);
	if(fd < 0){
		cerr << "error!";
		return -1; 
	}
	cerr <<"pipe ready!";
	string str;
//	string uname;
//	cout <<"input name:"<<endl;
//	getline(cin,uname);
	char buf[1000];
	do{
		//cout <<"input text:";
		//getline(cin,str);
		int n = read(fd,buf,1000);
		buf[n] = '\0';
		cout << "info:" << buf <<endl;
	}while( strcmp(buf,"bye") != 0 );
	unlink(fn.c_str());
	close(fd);
}
