#include <iostream> 
using namespace std; 
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h> 

void exitFunc(){
	cout << "I'm in exiting..." <<endl;
}

int main(int argc ,char *argv[]) 
{
	atexit(exitFunc);
	int i = fork();
	if(i>0){
		cout <<"In parent process" <<endl;
		exit(0);
	}else if(i==0){
		cout <<"In child process" <<endl;
		exit(0);
	}else{
		cout <<"Error"<<endl;
	}
}
