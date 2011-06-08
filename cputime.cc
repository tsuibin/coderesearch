#include <iostream> 
#include <stdlib.h> 
using namespace std; 

inline unsigned long int GetCycleCount()
{
	asm _emit   0x0F;
	asm _emit   0x31;
}


int main(int argc ,char *argv[]) 
{
	cout << GetCycleCount() <<endl;
}
