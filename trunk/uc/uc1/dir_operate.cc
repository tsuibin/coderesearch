#include <iostream>
#include <stdio.h>
using namespace std; 
#include <sys/stat.h>
#include <unistd.h>
#include <string.h> 

int main(int argc ,char *argv[]) 
{
	string cmd;
	string dirname;
	for(;;){
		cout << "cmd:";
		cin >> cmd;
		if(cmd =="mkdir"){
			cin >> dirname;
			mkdir(dirname.c_str(),0777);
		}
		else if(cmd =="rmdir"){
			cin >> dirname;
			rmdir(dirname.c_str());
		}
		else if(cmd=="chdir"){
			cin >> dirname;
			chdir(dirname.c_str());
		}
		else if(cmd == "pwd"){
			char buf[256];
			getcwd(buf,256);
			cout << buf << endl;
		}
		else if(cmd == "rename"){
			cin >>dirname;
			string newdirname;
			cin >> newdirname;
			rename(dirname.c_str(),newdirname.c_str());
		}
		else if(cmd =="bye"){
			cout << "C U" << endl;
			break;
		}
		else{
			cout << "不认识 command!"<<endl;
		}

	}

}
