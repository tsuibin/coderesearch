#include <stdio.h>
#include <stdlib.h>


void pargv(int argc, char ***argv)
{
	int i = 1;
	for (;i < argc;i++)
	{
		printf("%s\n",(*argv)[i]);
	}
}

int main(int argc , char *argv[])
{
	pargv(argc,&argv);

	return 0;
}
