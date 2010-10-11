#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node{
	int value ;
	struct node *next ;
	struct node *prev ;
};

struct node *head  ;

struct node *create_node(void)
{
	struct node *new_node;
	if((new_node = malloc(sizeof(struct node))) == NULL)
	{
		printf("malloc error!");
		return NULL ;
	}
	//    head -> value = 0 ;
	new_node -> next = NULL ;
	new_node -> prev = NULL ;
	return new_node ;
}

void insert_node(struct node *node)
{
	if(node == NULL)
	{
		return ;
	}
	if(head == NULL)
	{
		head = node ;
		return ;
	}

	node->next = head->next ;
	node->prev = head ;
	if (head->next != NULL )
	{
		head->next->prev = node ;
	}   
	head->next = node ;

	return ;

}

void delete_node (struct node *node)
{
	if (node == NULL)
		return ;
	if(node->prev)
		node->prev->next = node->next ;
	else
		head = node->next ;
	if (node->next)
		node->next->prev = node->prev ;   
	free(node);
	return ;
}

int main ( int argc , char *argv)
{

	struct node *node ;

	if((node = malloc(sizeof(struct node))) == NULL)
	{
		printf ("malloc error !\n");
		return NULL ;
	}                                        }
head = create_node() ;
node = new_node() ;
insert_node (node);
while(head != NULL)   
{
	printf("value = %d\n",head->value);
	head = head->next ;       
}                           
delete_node(node);
return 0 ;
}
