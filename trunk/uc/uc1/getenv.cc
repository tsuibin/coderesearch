#include <iostream> 
using namespace std; 
//main函数的第三种形式
int main(int argc ,char *argv[], char *env[])
{
	int i;
	for(i=0;env[i] != NULL; i++)
	{
		if (i < 9 ) cout << 0 ;
		cout << i+1 <<":" <<env[i] << endl;
		if (i%8 == 7) cin.get();
	}
}
