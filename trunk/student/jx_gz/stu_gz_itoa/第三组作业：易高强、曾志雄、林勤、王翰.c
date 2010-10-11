 #include <stdio.h> 
 #include <string.h>
 void my_change( int a) 
 {
 	int b,i;	
	char variable[20];
	memset(variable,0 ,20);
	b = sprintf(variable,"%d",a);
	for(i = 0; i < b ; i++)
		printf("variable[%d] =  %c\n",i,variable[i]);
	printf("variable = %s\n",variable); 
	return ;   
 
 }
 int main ( void)
 {
	int b;
	printf("input your number: ");
	scanf("%d",&b);
	my_change( b );

	return 0;   
}

