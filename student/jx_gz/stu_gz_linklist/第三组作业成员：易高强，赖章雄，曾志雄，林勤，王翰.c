#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
struct node

{
	int a;
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
	
	if((p0_node = malloc( sizeof( struct node ))) == NULL)
		{
			return NULL;   
		}
		
		p0_node ->a = value;
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
		return NULL;   
	}	
	if(p1->next == NULL)
	 {
		p1->prev->next = NULL;
		p = p1->prev;
		free(p1);
		return p;   
	 }
	if(p1->prev == NULL)
	{
		p1->next->prev = NULL;
		p = p1->next;
		free(p1);
		return p;   
	}
	p1->next->prev = p1->prev ;
	p1->prev->next = p1->next ;
	p = p1->next;
	free(p1);
	return p;   
}

int my_printf(struct node *first)

{
	struct node *p;
	p = first->prev->prev;
	
	while(p != NULL)
	{
		printf("%d\n",p->a);
		p = p->prev;
	}
	return 0;   	
}



int main( void )  

{
	struct node *first;
	struct node *last;
	struct node *p;
	int i,j,num;

	
	first = create_node();
	last = insert_node(first,0);
	printf("输入创建链表个数：");
	scanf("%d",&num);
	for(i = 1 ;i <= num; i++)
	{
		last = insert_node(last,i);
	
	}
	printf("创建成功的链表数据：\n"); 
	my_printf(first);
	printf("输入删除的节点的数据域的数据（0 —— 4 之间）:\n"); //输入删除节点的个数
	scanf("%d",&j);
	p = first->prev;
	while(p != NULL)
	
	{
		if(p ->a == j)
		{
			delete_node(p);
			break;
		}
		p = p->prev;
	}
	printf("删除成功后的链表数据：\n"); 
	my_printf(first);

	return 0;   
}



