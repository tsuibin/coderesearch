#include <stdio.h> 
#include <time.h>



char * getStuName()
{
	int i;
	static char rname[6] = {0};
	for ( i = 0; i < 5; i++)
	{   
		rname[i] = rand()%26 + 97; 
	}

	return rname;
}

int getStuNumber()
{
	return rand();
}

int main(int argc ,char *argv[]) 
{
	time_t t;
	srand(time(&t));
	int i;

	for (i = 0; i < 20; i++) {
		printf("stu No:%d\n", getStuNumber());	
		printf("stu Name:%s\n",getStuName());
	}
	return 0; 
}
