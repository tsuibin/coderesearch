#include <iostream> 
using namespace std; 
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h> 

void sig_proc(int sig)
{
	//signal(SIGCHLD,sig_proc);//为了每次都可以用
	wait(NULL);
	cout << "waited one child"<<endl;

}

void child(int len,char ch)
{
	if ( fork() != 0 ) return;
	for(int i=0;i<len;i++){
		cerr << ch;
		sleep(1);
	}
	exit(0);
}

int main(int argc ,char *argv[]) 
{
	signal(SIGCHLD,sig_proc);
		child(10,'.');
		child(20,'^');
	for(int i =0;i <100; i++){
		cerr <<'$';
		sleep(1);
	}
}
