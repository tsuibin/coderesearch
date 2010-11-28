#include <iostream> 
using namespace std; 
#include <unistd.h>

int main(int argc ,char *argv[]) 
{
	//int argc;

	//char *argvv[]={"ls",NULL};

	cout <<"我真的执行了" <<endl;
	execlp("ls","ls","-l","aaa", "bbb",NULL);

	cout <<"我要退出啦" <<endl;

}
