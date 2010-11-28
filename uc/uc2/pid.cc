#include <iostream> 
using namespace std; 
#include <unistd.h>
#include <errno.h>

int main(int argc ,char *argv[]) 
{
	pid_t cid;
	int d = 8 ;
	cid = fork();
	cout << "d=" << d << endl;
	cout <<"pid="<<getpid()<<",ppid="<<getpid()<<",cid="<<cid<<endl;
	if(cid ==0){
		cout <<"Child!"<<endl;
	}else if(cid > 0){
		cout << "Parent!" <<endl;
	}else{
		cout <<"Error="<<errno <<endl;
	}
}
