#include <iostream> 
using namespace std; 
#include <stdlib.h> 

int main(int argc ,char *argv[]) 
{
	char* var = "AAA=jiangxiligong";

	char* name="AAA";

	char* value = NULL;

	putenv(var);
	
	value = getenv(name);

	cout << "value=" << value << endl;
}
