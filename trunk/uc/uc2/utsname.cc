#include <iostream> 
using namespace std; 
#include <sys/utsname.h>
#include <unistd.h>

int main(int argc ,char *argv[]) 
{
	char host[256];
	if(gethostname(host,255)== 0) cout <<"Host name:"<<host <<endl;
	struct utsname sysinfo;
	if (uname(&sysinfo)!=-1){
		cout << "System name:" <<sysinfo.sysname<<endl;
		cout << "Node name:" <<sysinfo.nodename<<endl;
		cout << "Release:" <<sysinfo.release<<endl;
		cout << "Version:" <<sysinfo.version<<endl;
		cout << "Machine:" <<sysinfo.machine<<endl;
	}
}
