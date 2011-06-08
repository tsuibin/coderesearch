void swap(int i, int j)
{
	int temp;
	temp = i;
	i = j;
	j = temp;
}
int main(void)
{
	int a=2, b=3;
	swap(a,b);
	printf("a=%d,b=%d\n", a, b);
	return 0;
}
