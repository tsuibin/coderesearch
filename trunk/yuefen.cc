void yuefen(int fenmu, int fenzi)
{
	for(int i=1;i<(fenmu>fenzi? fenmu:fenzi) ; i++)
	{
		if(fenzi%i==0 && fenmu%i==0){
			fenzi /= i;
			fenmu /= i;
		}
	}
}
