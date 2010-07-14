#include <iostream>

using namespace std;

int main(int argc,char* argv[]){
		int a[3][3] = { {1,3,5},
				{2,4,6},
				{7,8,9}
		};
		int *p;//处理行
		
		for (p = a[0]; p < a[2] ; p++ ){
			*p=0;
			cout << p <<endl;
		}

		cout << "---------"<<endl;
		cout << a[0][0] <<endl; //int (*p)[0]->(*p)[8];p=&a[0];//处理列
		cout << a[0][1] <<endl;
		cout << a[0][2] <<endl;
		
		cout << a[0][3] <<endl;
		cout << a[0][4] <<endl;
		cout << a[0][5] <<endl;
		
		cout << a[0][6] <<endl;
		cout << a[0][7] <<endl;
		cout << a[0][8] <<endl;
		
		
		for (int i =0 ; i < 3 ; i++ ){	
			cout << *a[i] <<endl;
		}

		return	0;
}
