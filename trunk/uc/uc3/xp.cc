#include <iostream> 
using namespace std; 
#include <unistd.h>
#include <stdlib.h> 
void child(){
	for(;;){
		cout <<'.'<<flush;
		sleep(3);
	}
}
void $(){
	if( fork() ==0 ){
		child();
	}
}
int main(int argc ,char *argv[]){
	
		atexit($);
//		//cout << "return to shell;"<<endl;
//		_exit(0);
		return 0; 

}
