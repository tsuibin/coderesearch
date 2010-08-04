#include <iostream>
using namespace std;
int main(int argc,char* argv[]){

	int *p=NULL;
	cout << "sizeof(int*) = " << sizeof(p) << endl;
	int a[100];
	cout << "sizeof(a[100]) = " << sizeof(a[100]) << endl;
	cout << "sizeof(a) = " << sizeof(a) << endl;
	cout << "sizeof(&a) = " << sizeof(&a) << endl;
	cout << "sizeof(&a[0]) = " << sizeof(&a[0]) << endl;

}
