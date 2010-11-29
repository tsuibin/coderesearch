#include <iostream> 
using namespace std; 
#include <unistd.h>

void child(){
	for(;;){
		cout <<'.'<<flush;
		sleep(3);
	}
}

int main(int argc ,char *argv[]){
	
	if( fork() ==0 ){
		child();
	}
		//cout << "return to shell;"<<endl;
		return 0; 

}
