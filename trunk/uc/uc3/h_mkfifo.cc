#include <iostream> 
using namespace std; 
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc ,char *argv[]) 
{
		mkfifo("abc",0600);

}
