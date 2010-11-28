#include <iostream> 
using namespace std;
#include <string.h> 
#include <stdlib.h> 

int main(int argc ,char *argv[]) 
{
	char str[256];
	cout <<"unix#";
	cin.getline(str,256);
	string bye = "exit";
	while(strcmp(str,bye.c_str())){
		system(str);
		cout<< "unix#";
		cin.getline(str,256);
	}
}
