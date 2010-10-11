#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student 
{
	int id ;
	char name[50] ;
	int age ;
	struct student *prev , *next ;
};

struct student *head ;

struct student *new_node (int id , char name[50] , int age)
{
	

	struct student *new_node ;
	if((new_node = malloc(sizeof(struct student))) == NULL)
	{
		printf ("malloc error !\n"); 
		return NULL ;
	}
	new_node -> id = id ;	
	strcpy(&(new_node -> name[0]) , name );
	new_node -> age = age ;
	new_node -> next = NULL ;
	new_node -> prev = NULL ;

	return new_node ;

}

void free_node (struct student *p)
{
	free (p);
}

void insert_node (struct student *list)
{
	struct student *new_node ;
	if(list == NULL)
		return ;
	new_node->next = list->next ;
	new_node->prev = list ;
	if (list->next != NULL ) 
		list->next->prev = new_node ;
	list->next = new_node;

	return ;
}

void delete_node (struct student *p)
{
	if (p == NULL)
		return ;
	if(p->prev)
		p->prev->next = p->next ;
	else 
		head = p->next ;
	if (p->next)
		p->next->prev = p->prev ;	
	free_node (p);
	return ;
}

struct student *search_node (int id)
{
	struct student *new_node ;
	
	if((new_node = malloc(sizeof(struct student))) == NULL)
	{
		printf ("malloc error !\n"); 
		return NULL ;
	}
	for (new_node = head ; new_node != NULL ; new_node = new_node->next)
	{
		if (new_node->id == id)
			return new_node ;
	}
	
	return NULL ;
}


void print_node (struct student *p)
{
	printf ("id = %d \t name = %s \t age = %d\n", p->id , p->name , p->age); 
	return ;
}

int main ( int argc , char *argv)
{
		
	struct student *p ;

	if((p = malloc(sizeof(struct student))) == NULL)
	{
		printf ("malloc error !\n");
		return -1 ;
	}
	head = new_node (1 , "Lily" , 20);
	p = new_node (2 , "Lucy" , 21);
	insert_node (p);

	p = new_node (3 , "Mary" , 22);	
	insert_node (p);
	
	p = search_node (2);
	delete_node (p);	

	while (head != NULL)
	{
		print_node (head);
		head = head->next ;
	}

	return 0 ;
}
