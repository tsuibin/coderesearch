#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
	int id;
	struct node *prev;
	struct node *next;
};

struct node *create_node(void)
{
	struct node *new_node;
	new_node = malloc(sizeof(struct node));
	if(new_node == NULL)
	{
		printf("create error \n");
		return NULL;
	}
	new_node -> next = NULL;
	new_node -> prev = NULL;
	return new_node;
}

struct node *add_node(struct node *list, int id)
{
	struct node *new_node;
	if(list == NULL)
	{
		return NULL;
	}
	if((new_node = create_node()) == NULL)
	{
		return NULL;
	}
	new_node -> id = id;
	new_node -> next = list;
	new_node -> prev = NULL;
	list -> prev = new_node;
	return new_node;
}

struct node *delete_node(struct node *list)
{
	struct node *p;
	if(list == NULL)
	{
		return NULL;
	}
	if(list -> prev != NULL && list -> next != NULL)
	{
		list -> next -> prev = list -> prev;
		list -> prev -> next = list -> next;
	}
	if(list -> prev == NULL)
	{
		list -> next -> prev = NULL;
	}
	if(list ->next == NULL)
	{
		list -> prev -> next = NULL;
	}
	free(list);
	p = list -> next;

	return p;
}

struct node *sd_node(struct node *list)
{
	int id;
	printf("please enter you want delete:\n");
	scanf("%d",&id);
	while(list -> id != id)
	{
		list = list -> prev;
	}
	delete_node(list);
}

int main(int argc,char *argv[])
{
	int i;
	struct node *p,*q,*first,*last;
	first = create_node();
	q = add_node(first,0);
	for(i = 1;i < 10;i++)
	{
		q = add_node(q,i);
	}
	sd_node(first);

	p = first -> prev;
	while(p != NULL)
	{
		printf("%d\n",p -> id);
		p = p -> prev;
	} 

	return 0;
}

