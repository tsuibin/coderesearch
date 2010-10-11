#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
struct node

{
	int value;
	struct node *next;
	struct node *prev;

};

struct node *create_node(void)

{
	struct node *p0_node;
	if ((p0_node = malloc(sizeof(struct node))) == NULL)
	{
		printf("this malloc error");
		
		p0_node->next=NULL;
		p0_node->prev=NULL;
		
		return NULL;  
	}
}

struct node *insert_node(struct node *p1,int value)

{
	struct node *p0_node; 
	if(p1 == NULL)
	{	
		printf("the insert is error\n");
		return NULL;   
	}
	
	if((p0_node = create_node()) == NULL)
		{
			return NULL;   
		}
		
		p0_node ->value = value;
		p0_node ->next = p1;
		p0_node ->prev = NULL;
		p1->prev = p0_node;

	return p0_node;	

}

struct node *delete_node(struct node *p1)

{
	struct node *p;
	if(p1 == NULL)
	{	printf("the delete is error\n"); 
		return 0;   
	}	
	if(p1->next != NULL)
	 {
		p = p1->prev;
		p1->prev->next = NULL;
		p1->prev = NULL;
		free(p1);
		return p;   
	 }
	else
	{
		p1->next->prev= p1->prev;
	}
	if(p1->prev == NULL)
	{
		p = p1->next;
		p1->next->prev = NULL;
		p1->next = NULL;
		return p;   
	}
	else
	{
		p1->prev->next = p1->next;
	}
	
	p = p1->next;
	free(p1);
	return p;   
}

int my_printf(struct node *first)

{
	struct node *p;
	p = first->next;
	
	if(first == NULL)
		printf("is error\n");
	else
		while(p != NULL)
		{
			printf("%d\n",p->value);
			p = p->next;
		}
	return 0;   	
}



int main(int argc,char argv[])  

{
	struct node *first;
	struct node *last;
	struct node *p;
	int i,j;

	
	first = create_node();
	last = insert_node(first,0);
	for(i = 1 ;i < 5;i++)
	{
		last = insert_node(last,i);
	
	}
	my_printf(first);
	printf("please input delete node j:\n"); //输入删除节点的个数
	scanf("%d",&j);
	p = first->prev;
	while(p != NULL)
	
	{
		if(p ->value == j)
		{
			delete_node(p);
			break;
		}
		p = p->prev;
	}
	my_printf(first);

	return 0;   
}



