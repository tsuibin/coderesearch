#include <iostream> 
using namespace std; 
#include <unistd.h>
#include <sys/wait.h>

int main(int argc ,char *argv[]) 
{
	pid_t id,cid;
	cout << "父进程id:" << getpid() <<endl;
	int i,ci;
	if(fork() == 0){
		cout << "子进程id:" << getpid() <<endl;
		//sleep(2);
		cout << "儿子来了"<<endl;

		return 1;
	}else{
		id = wait(&i);
		//cid = wait(NULL);
		cout << "i:"<< i <<endl;
		cout << "爸爸要走了:"<< id <<endl;
		//cout << "爸爸要走了:"<< cid <<endl;
	}

}
