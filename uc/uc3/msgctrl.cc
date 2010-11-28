
#include <iostream> 
using namespace std; 
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h> 

struct Msg{
		long change;
		char name[20];
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

		if( msgctl(qid,IPC_RMID,NULL) < 0) {
			cout <<"error!" << endl;;
		}else{
			cout <<"success"<< endl;;
		}
		;

}
