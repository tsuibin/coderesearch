#include <iostream> 
using namespace std; 
#include <unistd.h>
void child(){

	close(0);
	close(1);
	close(2);
	//后台程序 服务程序
	//长时间在后台提供服务的程序
	//精灵进程有一套规范的写法
	for(;;){
		cout <<'.'<<flush;
	}
}
int main(int argc ,char *argv[]) {
	if(fork() == 0){
		child();
	}
	return 0; 
}
