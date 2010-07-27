#include <stdio.h> 
#include <stdlib.h> 

struct node {
	int value;		//data stored in the node
	struct node *next;	//pointer to the next node
	struct node *prev;
};

struct node * create_node(void)
{
	struct node *new_node;
	
	if ( (new_node = malloc(sizeof(struct node)) ) == NULL)
	{
		printf("malloc error!");
		return NULL;
	}

	new_node->next = NULL;
	new_node->prev = NULL;

	return new_node;
}
struct node * add_to_node(struct node *list,int value)
{
	struct node *new_node;
	
	if (list == NULL)
	{
		return NULL;
	}

	if ( (new_node = create_node()) ==  NULL)
	{
		return NULL;
	}

	new_node->value = value;
	new_node->next = list;
	new_node->prev = NULL;
	list->prev = new_node;

	return new_node;
	
}

struct node * delete_node(struct node *list)
{
	struct node *p;
	
	if (list->next != NULL)
	{
		list->next->prev = list->prev;
	}
	if (list->prev != NULL && list->next != NULL)
	{
		list->prev->next = list->next->prev;
	}

	p = list->next;
	free(list);
	
	return p;
}

int main(int argc,char* argv[])
{
	struct node *first = NULL;
	struct node *last = NULL;
	struct node *p;
	
	if ( (first = create_node()) == NULL )
	{
		return 0;
	}

	if ( (first = add_to_node( first, 0)) == NULL )
	{
		printf("add false!\n"); 
	}
	last = first;
	
	if ( (first = add_to_node( first, 0)) == NULL )
	{
		printf("add false!\n"); 
	}

	if ( (first = add_to_node( first, 1)) == NULL )
	{
		printf("add false!\n"); 
	}
	
	if ( (first = add_to_node( first, 2)) == NULL )
	{
		printf("add false!\n"); 
	}
	
	if ( (first = add_to_node( first, 3)) == NULL )
	{
		printf("add false!\n"); 
	}
	
	first = delete_node(first);
	
	p = first;
	while( p != NULL )
	{
		printf("%d,",p->value);
		p = p->next;
	}
	printf("\b\n");

	p = last;
	while( p != NULL )
	{
		printf("%d,",p->value);
		p = p->prev;
	}
	printf("\b\n");

	return 0;
}
