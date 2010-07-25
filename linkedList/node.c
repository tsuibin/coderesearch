#include <stdio.h> 
#include <stdlib.h> 

struct node {
	int value;		//data stored in the node
	struct node *next;	//pointer to the next node
};

struct node * add_to_node(struct node *list,int value)
{
	struct node *new_node;
	if ( (new_node = malloc(sizeof(struct node)) ) == NULL)
	{
		printf("malloc error!");
		return 0;
	}
	new_node->value = value;
	new_node->next = list;
	return new_node;
	
}

int main(int argc,char* argv[])
{
	struct node *first = NULL;
	struct node *p;

	first = add_to_node( first, 0);
	first = add_to_node( first, 0);
	first = add_to_node( first, 1);
	first = add_to_node( first, 2);
	first = add_to_node( first, 3);
	
	p = first;
	while( p != NULL )
	{
		printf("%d,",p->value);
		p = p->next;
	}
	printf("\b\n");

	return 0;
}
