#include <iostream> 
using namespace std; 
#include <unistd.h>
#include <stdlib.h>

int gabc;

int main(int argc ,char *argv[]) 
{
	int ppp=888;
	int cid;
	cout << "我是全局的:" << gabc << endl;
	//cout << "我是父进程:" <<getpid()<< endl;
	//cout << "父进程ppid:" << getppid() <<endl;
		
	if((cid = vfork()) == 0){
		gabc = 1;
	//cout << "儿子我是全局的:" << gabc << endl;
	/*
		cout << "我是子进程:" <<cid <<endl;	
		*/ppp=999;/*
		cout << "子进程ppp:" << ppp <<endl;
		cout << "getppid:" << getppid() <<endl;
		sleep(3);
		cout << "getppid:" << getppid() <<endl;
*/	sleep(2);
_exit(0);
	//exit(0);
	}else{
		//cout << "cid子进程:" << cid << endl;
		cout <<"父进程"<< ppp <<endl;
		cout << "at end我是全局的:" << gabc << endl;
	}
	
	cout <<"程序结束啦" <<endl;

}
