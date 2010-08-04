#include <iostream>	
using namespace std;
int main(int argc,char* argv[]){
	int a[3][3]={{1,3,5},{2,4,6},{7,8,9}};
	int (*p)[3]=NULL;
	p=a;
	cout << p <<endl;
	p+=4;
	cout << p <<endl;	
	cout <<"------"<<endl;
	cout << **p << endl;
	cout << **p++ <<endl;
	cout <<"------"<<endl;
	cout << **p++ <<endl;
	cout <<"------"<<endl;
	cout << *p[0] <<endl;
	for(int i = 0; i < 3 ; i++){
		for(int j = 0 ; j < 3 ; j++){
			cout << &a[i][j] <<endl;
			cout << a[i][j] <<endl;
		}
	}
	return 0;
}
