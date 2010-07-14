#include <iostream>	
using namespace std;	
int main(int argc,char* argv[]){	

	int arr[] = {12,45,3,5,7,8,9,34,32,};
	int *p = NULL;
	int *q = NULL;

	p = &arr[2];
	q = &arr[0];
	cout << (p>q) <<endl;
}
