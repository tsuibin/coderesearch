#include <iostream>

using namespace std;

int main(int argc,char* argv[]){
	//int arr[5] = {2,4,6,8,10};
	
	int *p;
	*p = 5;
	//p=arr;
	cout << p[0] << endl;
	p++;
	cout << p[0] << endl;
	p+=1;
	cout << p[0] << endl;

}
