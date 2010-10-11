#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct node
{
	int values;
	struct node *next;
	struct node *prev;
};


struct node *creat_node (void)
{
	struct node *new_node;
	if ((new_node = malloc(sizeof(struct node))) ==NULL)
	{
		printf ("malloc error!\n");
		exit(1);
	}
	new_node -> next = NULL;
	new_node -> prev = NULL;

	return new_node;

}

struct node *add_node (struct node *list ,int value)
{
	struct node *new_node;

	if (list == NULL)
	{
		printf ("error\n");
		return 0;

	}
	if ((new_node = creat_node()) == NULL)
	{
		printf ("add error\n");
		return 0;
	}
	new_node -> values = value;
	new_node -> next = list;
	new_node -> prev = NULL;
	list -> prev = new_node;


	return new_node;
}
struct node *dele_node (struct node *list)
{	
	struct node *p;
	if (list == NULL)
	{
		printf ("delete error!\n");
		return 0;
	}
	if (list -> next == NULL)
	{	p = list -> prev;
		list -> prev -> next = NULL;
		list -> prev = NULL;
		free (list);
		return p;
		
	}
	if (list -> prev == NULL)
	{
		p = list -> next;
		list -> next -> prev = NULL;
		list -> next = NULL;
		free (list);
		return p;
	}

	
		list -> prev -> next = list ->next;
		
	        list -> next -> prev = list ->prev;	
		
		p = list -> next;
		free(list);
	
		return p;
	
}
int print_node (struct node *list)
{
	struct node *p;
	
	p = list;
        while (p -> next != NULL)
        {
                printf ("%d",p -> values);
                p = p -> next;
        }
        printf ("\n");
	return 0;

}

int main(int argc, char *argv[])
{	
	int i,num;
	struct node *first;
	struct node *last;
	struct node *p;
	first = creat_node();
	last = add_node(first,0);
	for(i = 1; i< 10; i++)
	{
		
		last = add_node(last,i);
		 
		
	}

	print_node (last);

	printf ("please input delete node num:\n");
	scanf ("%d",&num); 
	p = first -> prev;
	while (p != NULL)
	{
		if (p -> values == num)
		{
			dele_node(p);
			break;
		}
		p = p -> prev;
	}

	print_node(last);

	return 0;
}	
