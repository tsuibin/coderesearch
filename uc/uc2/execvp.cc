#include <iostream> 
using namespace std; 
#include <unistd.h>
#include <stdlib.h>

int main(int argc ,char *argv[]) 
{
	if(fork() == 0){
		char * argv[5]={
			"./cmdline",
			"aa","bb","cc",
			NULL};
		execvp("cat",argv);
		cout <<"Not found cat"<<endl;
		
		return -1;
	}else{
		fork();
		execvp("cat",argv);
		
		sleep(30);
		cout << "父进程退出"<<endl;
	}

	return 0; 
}

