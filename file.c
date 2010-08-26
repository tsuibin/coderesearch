int main(int argc, char *argv[])
{
	char file[SLEN];
	char ch;
	FILE *fp;
	long count ,last;

	puts("Enter the name of the file to processed:");
	gets(file);
	if((fp = fopen(file ,"rb")) == NULL)
	{
		printf("reverse can't open %s\n",file);
		exit(1);
	}
	fseek(fp ,0,SEEK_END);
	last = ftell(fp);
	printf("last = %d\n",last);
	for (count = 1L ; count <= last ; count++)
	{
		fseek(fp,-count,SEEK_END);
		ch = getc(fp);

		if(ch != CNTL_Z && ch != '\r')
			putchar(ch);
	}
	/*      if(ch == '\r')
	 *                      putchar('\n');
	 *                              else
	 *                                              putchar(ch);
	 *                                              */
	putchar('\n');
	fclose(fp);


	return 0;
}
