#include <iostream>
using namespace std;
int main(int argc,char* argv[]){

	double d[5]={};
	for(int i = 0;i<5;i++){
		cout <<d[i] <<endl;
	}
	int a[5]={10,20,30};
	int b[ ]={10,20,30};
	cout << "sizeof(a)=" << sizeof(a) << endl;
	cout << "sizeof(c)=" << sizeof(b) << endl;

}
