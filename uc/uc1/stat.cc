#include <iostream> 

using namespace std; 
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc ,char *argv[]) 
{
	if(argc ==1){
		cout << *argv << " filename"<<endl;
		
		return 0; 
	}
	int res;
	struct stat s;
	res = stat(argv[1],&s);
	if(res < 0){
		cout << "no this file" << endl;

		return -1; 
	}
	cout << s.st_uid << ",size:" << s.st_size << endl;
	if(S_ISDIR(s.st_mode))
		cout << "directory" << endl;
	else
		cout << "file" <<endl;

}
