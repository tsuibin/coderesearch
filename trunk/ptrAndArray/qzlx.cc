#include <iostream>
using namespace std;
int main(int argc,char* argv[]){

	//int p[] = {1,3,4,6,8,9};
	int *p = (int []){1,3,4,6,8,9};
	p[0] = 5;
	cout << p[0] << endl;
}
