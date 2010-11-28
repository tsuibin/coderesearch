#include <iostream> 
#include <stdlib.h> 
using namespace std; 

int main(int argc ,char *argv[]) 
{
	char* name = "HOME";

	char* value = NULL;

	value = getenv(name);

	cout << "value=" << value << endl;

}
