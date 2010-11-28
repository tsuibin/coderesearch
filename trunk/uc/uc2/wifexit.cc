#include <iostream> 
using namespace std; 

#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


int main(int argc ,char *argv[]) 
{
	if(fork() ==0){//子进程
	//	for(int i =0;i < 5;i++ ){
			cout <<"子进程" <<getpid()<<endl;
			sleep(1);
	//	}
		cout <<"子进程结束"<<endl;
		return 256; //256%
	}else{
		cout << "父进程" <<getpid() <<endl;
		int s;
		pid_t cid=wait(&s);//get return code
		cout <<"等待"<<cid <<endl;
		//waitpid
		if(WIFEXITED(s)){
			cout << "return :" << WEXITSTATUS(s) <<endl;
		}

		return 0; 
	}
}





















//wait_pid(cid,&c);
//return code type char >0 <256
