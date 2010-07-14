#include <iostream>
using namespace std;
int main(int argc,char* argv[]){
	int arr[] = {12,432,4,324,32,4};
	for(int i = 0 ;i < 6; i++ ){
		cout << *(arr+i) <<endl;
	}
}
