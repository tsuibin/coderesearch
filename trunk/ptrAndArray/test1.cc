#include <iostream>
#include "extern.h"
using namespace std;
int main(int argc,char* argv[]){
	extern int *p;
	//extern int *arr;
	extern int arr[6];
	arr[0] =1;
	cout << arr[0] <<endl;
}
