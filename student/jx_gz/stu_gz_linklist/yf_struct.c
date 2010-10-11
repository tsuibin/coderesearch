#include<stdio.h>
#include<stdlib.h>

struct node
{
	int values;
	struct node *next;
	struct node *prev;
};

struct node *create_node (void)
{
	struct node *new;
	if((new = (malloc(sizeof(struct node)))) == NULL)
	{
		printf("malloc error!\n");
		return NULL;
	}
		new->next = NULL;
		new->prev = NULL;
}

struct node *add_node (struct node *old, struct node *new, int values)
{
	new->values = values;
	if(old == NULL)
	{
		printf("链表为空!\n");
		return NULL;
	}
	else
	{
		if(old->next = NULL)	//old为链表尾时；
		{
			new->prev = old;
			new->next = NULL;
			old->next = new;
		}
		else
		{
			new->next = old->next;
			new->prev = old;
			old->next->prev = new;
			old->next = new;
		}
	} 
}

struct node *delete_node(struct node *p)
{
	if(p->next != NULL || p->prev != NULL)
	{
		p->next->prev = p->prev;
		p->prev->next = p->next;
	}
	else
	{
		if(p->next = NULL)
		p->prev->next = NULL;
		if(p->prev = NULL)
		p->next->prev = NULL;
	}
}

int slt(struct node *a)
{
	if(a != NULL)
	{
		printf("%d\n",a->values);
		a = a->next;
	}
	return 0;
}

