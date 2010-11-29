#include <iostream> 
using namespace std; 
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h> 
#include <stdio.h> 
struct Msg{
	long cno;
	char name[100];
};

int main(int argc ,char *argv[]) 
{
	if(argc == 1){
		cout <<*argv<<" key"<<endl;
		return 0; 
	}
	int key = atoi(argv[1]);
	int qid;
	qid = msgget(key,IPC_CREAT|0600);
	if(qid < 0){
		cout <<"cannot create message queues"<<endl;
	return -1; 
	}

	cout <<"OK!"<<endl;
	cout <<"key=0x"<<hex<<key<<endl;
	cout <<"qid="<<dec<<qid<<endl;
	struct Msg m;
	cout <<"input qid:";
	int num;
	cin >> num;
	if( num = msgrcv(qid,&m,sizeof(m.name),num,0104000) > 0){
		//cout <<"msg size:"<<num;
		cout << m.name <<endl;
	}
	
	return 0; 
}
