#include <iostream> 
using namespace std; 
#include <signal.h>
#include <stdlib.h> 
#include <time.h> 

int v=0;
int x=0;
void func(int sig){
	cout <<"time out!"<<endl;
	cout <<"V:"<< v <<endl;
	cout <<"X:"<< x <<endl;
	exit(0);
}

int main(int argc ,char *argv[]) 
{
	signal(SIGALRM,func);
	srand(time(NULL));
	alarm(20);
	for(int i =0;i<10;i++){
		int n1 = rand()%10;
		int n2 = rand()%10;
		cout << n1 <<"+" << n2 <<"=";
		int sum;
		cin >> sum;
		if(sum == n1+n2){
			v++;
		}else{
			x++;
		}
	}
	cout <<"你太有才了!"<<endl;
	raise(SIGALRM);
}
