#include <iostream> 
using namespace std; 
#include <sys/stat.h>
#include <string.h> 
#include <fcntl.h>
#include <unistd.h>

int main(int argc ,char *argv[]) 
{
	string fn = "fifo.tmp";
	mkfifo(fn.c_str(),0600);

	int fd = open(fn.c_str() ,O_WRONLY);
	if(fd < 0){
		cerr << "error!";
		return -1; 
	}
	cout<<"pipe ready!"<<endl;
	string str;

	do{
		cout <<"input text:";
		getline(cin,str);
		write(fd,str.c_str(),str.size());
	}while( str != "bye" );
	unlink(fn.c_str());
	close(fd);
}
