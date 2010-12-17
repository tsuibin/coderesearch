#include <iostream> 
using namespace std; 
#include <signal.h>

void func(int sig){
	switch(sig){
		case SIGINT:
			cout <<"我是ctrl+c,被捕捉了"<<endl;
			break;
		case SIGUSR1:
			cout <<"u1"<<endl;
			break;
		case SIGUSR2:
			cout <<"u2"<<endl;
			break;
		default:
			cout <<"unknow"<<endl;
			break;
	}
}

void helloworld(int i)
{
	cout << "hello world!" <<endl;
}

int main(int argc ,char *argv[]) 
{
	//cout << "====1===="<<endl;
	signal(SIGINT, func);
	signal(SIGUSR1, helloworld);
	signal(SIGUSR2, func);

	//cout << "====2===="<<endl;

	for(int i=0;i <20; i++){
		sleep(10);
		cerr << "x";
	}

}
