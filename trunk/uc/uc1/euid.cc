#include <iostream> 
#include <string.h> 
#include <pwd.h>
using namespace std; 

int main(int argc ,char *argv[]) 
{
	int uid;
	string name;

	cout << "user:"<< getlogin() << endl;
	cout << "有效uid:"<< geteuid() << endl;
	cout << "uid:"<< getuid() << endl;
	struct passwd * p = getpwuid(getuid());
	cout << "input username or id:";
	char ch;
	ch = cin.peek();
	if(ch>='0'&&ch <='9'){
		cin >> uid;
		p = getpwuid(uid);

	}else{
		cin >> name;
		p = getpwnam(name.c_str());
	}
	if (p == NULL ){
		cout << "error!" <<endl;
	}

	cout << "name:"<< p->pw_name << endl;
	cout << "uid:"<< p->pw_uid << endl;
	cout << "gid:"<< p->pw_gid << endl;
	cout << "dir:"<< p->pw_dir << endl;
	cout << "shell:"<< p->pw_shell << endl;

}
