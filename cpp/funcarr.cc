#include <iostream> 
using namespace std;

void f(int arr[])
{

	for(int i =0;i<3;i++){
		cout << arr[i] <<endl;
	}
}

void func2(int arr2[])
{
	arr2[2] = 5;
	for(int i=0;i<3;i++){
		cout << arr2[i] <<endl;
	}
}
int main(int argc,char* argv[]){
	int abc[] = {1,4,7};
	f(abc);
	cout << "--------------"<<endl;
	func2(abc);
	return 0;

}
