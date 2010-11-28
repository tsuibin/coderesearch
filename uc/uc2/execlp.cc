#include <iostream> 
using namespace std; 
#include <unistd.h>
#include <stdlib.h>

int main(int argc ,char *argv[]) 
{
	if(fork() == 0){
		//execlp("./cmdline","aa","bb","cc",NULL);
		execlp("ls","ls","-l","/etc",NULL);
		//execlp("ls","ls","-l","/etc",NULL);//nop don't use p ;e use env
		cout <<"Not found cat"<<endl;
		
		return -1;
	}else{
		//fork();
		//execvp("cat",argv);
		
		sleep(3);
		cout << "父进程退出"<<endl;
	}

	return 0; 
}

