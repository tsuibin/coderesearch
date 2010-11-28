#include <iostream> 
using namespace std; 

#include <unistd.h>
#include <sys/types.h>

int main(int argc ,char *argv[]) 
{
	cout <<"old pid:" <<getpid() << endl;

	cout << "try to fork()..."<<endl;

	pid_t id=fork();
	
	if(id < 0){
		cout << "fork error!" <<endl;
		return -1;
	}
	if(id > 0){ //parent process
		for(int i =0 ;i < 4; i++){
			cout <<"parent:" <<getpid()<<endl;

			sleep(3);
		}
	}else{//child process
		for(int i=0;i<5;i++){
			cout <<"child:"<<getpid()<<endl;
			sleep(3);
		}
	}
	fork();
	cout<<"---bye---"<<getpid()<<endl;

}
