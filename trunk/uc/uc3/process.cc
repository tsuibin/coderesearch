#include <iostream> 
using namespace std; 
#include <unistd.h>

int main(int argc ,char *argv[]){
	if( fork() !=0 ){
		cout << "return to shell;"<<endl;
		return 0; 
	}
	for(;;){
		cout <<'.'<<flush;
		sleep(3);
	}
}
