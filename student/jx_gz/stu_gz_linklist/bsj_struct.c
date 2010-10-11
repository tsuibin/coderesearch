#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct excel{
	int ID;
	struct excel *next;
	struct excel *prev;
	};

struct excel *create_e(void)
{
	struct excel *np;
	if((np = malloc(sizeof(struct excel))) == NULL)
	{
		printf("malloc error");
		return(NULL);
	}
	np -> next = NULL;
	np -> prev = NULL;
	return np;
}

struct excel *add_e(struct excel *list ,int ID)
{
	struct excel *new;
	if(list == NULL)
	{
		return(NULL);
	}
	if((new = create_e()) == NULL)
	{
		return(NULL);
	}
	new -> ID = ID;
	new -> next = list;
	new -> prev = NULL;
	list -> prev = new;
	return new;
}

struct excel *delete_e(struct excel *list)
{
	struct excel *d;
	if(list == NULL)
	{
		return(NULL);
	}
	if(list -> next != NULL && list -> prev != NULL)
	{
		list -> next -> prev = list -> prev;
		list -> prev -> next = list -> next;
	}
	free(list);
	d = list -> next;
	return(d);
}

int print_struct(struct excel *st)
{
	struct excel *m;
	m = st -> prev;
	while(m != NULL)
	{
		printf("%d\n",m -> ID);
		m = m -> prev;
	}
	return 0;
}

struct excel *choose_d(struct excel *list)
{
	int ID;
	printf("Input ID you want delete:");
	scanf("%d",&ID);
	while(list -> ID != ID )
	{
		list = list -> prev;
	}
	delete_e(list);
	return;
}


int main(int argc,char *argv[])
{
	struct excel *p;
	struct excel *st;
	struct excel *q;	
	int i;
	p = create_e();
	q = add_e(p,0);
	for(i = 1;i <= 20;i ++)
	{
		q = add_e(q,i);
	}
	print_struct(p);
	choose_d(p);

	st = p -> prev;
	while(st != NULL)
	{
		printf("%d\n",st -> ID);
		st = st -> prev;

	}
	

}
