#include <iostream> 
using namespace std; 

#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


int main(int argc ,char *argv[]) 
{
	if(fork() ==0){//子进程
		for(int i =0;i < 5;i++ ){
			cout <<"子进程" <<getpid()<<endl;
			sleep(1);
		}
		return 8763;
	}else{
		cout << "父进程" <<getpid() <<endl;

		pid_t cid=wait(NULL);
		cout <<"等待"<<cid <<endl;
		return 0; 
	}
}
