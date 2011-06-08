#include <iostream> 
#include <dirent.h>
#include <sys/types.h>
#include <string.h> 
#include <list>
#include <iterator>
#include <algorithm>

using namespace std; 

int main(int argc ,char *argv[]) 
{
		char * dir = NULL;

		if(argc == 1) {
				dir = (char *) ".";
		}else{
				dir = argv[1];
		}
		DIR* p = opendir(dir);
		if(p == NULL) {
				cout << "not direntory of not exist" << endl;
		}
		struct dirent* pd = NULL;
		list<string> ls;
		while( (pd = readdir(p)) != NULL){
				if(pd->d_name[0] == '.') continue;
				//cout << pd->d_name << endl;
				ls.push_back(pd->d_name);
		}
		closedir(p);
		ls.sort();
		
		list<string>::iterator it;
		it = ls.begin();
		while(it != ls.end())
		{
			cout << *it++ <<endl;
		}

		//copy(ls.begin(),ls.end(),ostream_iterator<string>(cout,"\n"));

		return 0;

}
