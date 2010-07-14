#include <iostream>	
using namespace std;	
int [] func()
{
   int a[5]= {2,5};
   return a;
}

int main(int argc,char* argv[]){	
	cout << (func())[1] << endl;
}
