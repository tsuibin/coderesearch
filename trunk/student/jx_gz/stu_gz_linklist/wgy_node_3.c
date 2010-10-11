#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student 
{
	int id ;
	char name[64] ;
	int age ;
	struct student *prev , *next ;
};

struct student *head ;

struct student *create_node (int id , char name[64] , int age)
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



void add_to_node (struct student *p)
{
	if(p == NULL)
		return ;
	if(head == NULL)
	{
		head = p ;
		return ;
	}

	p->next = head->next ;
	p->prev = head ;
	if (head->next != NULL ) 
		head->next->prev = p ;
	head->next = p ;

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
	free (p);

	return ;
}




void print_node (struct student *p)
{
	
	return ;
}

int main ( int argc , char *argv[])
{
		
	struct student *p ;

	if((p = malloc(sizeof(struct student))) == NULL)
	{
		printf ("malloc error !\n");
		return -1 ;
	}
	head = create_node (1 , "Tom" , 22);
	p = create_node  (2 , "Lucy" , 23);
	add_to_node (p);

	p = create_node  (3 , "Tomas" , 24);	
	add_to_node(p);

	p = create_node  (4 , "TIMME" , 23);
	add_to_node (p);
	
	
	delete_node (p);	

	while (head != NULL)
	{
		print_node (head);
		head = head->next ;
	}

	printf ("id = %d \t name = %s \t age = %d\n", p->id , p->name , p->age); 
		

	return 0 ;
}
