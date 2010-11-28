#include <iostream> 

using namespace std; 

	int g=0;
	int n;
int main(int argc ,char *argv[]) 
{
	cout << "&g=" <<&g <<endl;
	for(;;)
	{
		cout << "intput an integer:";
		cin >> n;
		g+=n;
		cout <<"g=" << g << endl;
	}
}
