#include <iostream>
using namespace std;
int main(int argc,char* argv[]){
	int a[10];
	int *p;
	p = &a[0];
	*p=5;
	p++;
	*p=6;
	cout << a[1] <<endl;

}
