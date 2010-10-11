#include<stdio.h>
#include<string.h>
#include <stdlib.h>
struct node{
		int data;
		struct node *prev;
		struct node *next;
			};
struct node *head;
	
struct node *creat_node()
{
	struct node *new;
	
	if((new=malloc(sizeof(struct node)))==NULL)
	{
		printf("malloc node faild");
		return NULL;
	}
	else 
	{
		new->next=NULL;
		new->prev=NULL;
	}
	return new;
		
}

void insert_node(struct node *old,struct node  *new)//结点q插入到p后面
{
        if(old==NULL)
	printf("list is NULL");
	 else if(old->next!=NULL)
		{
		new->next=old->next;
		old->next=new;
		old->next->prev=new;
		new->prev=old;
		}
		else 
			{
			old->next=new;
			new->prev=old;
			} 
	return ;
		
}

void print(struct node *p)
{	
	while(p->next!=NULL)
	{	printf("%d\n",p->data);
		p=p->next;
	}
}
struct node *make_link(void)
{	
	int i;
	struct node *old,*new;
	head=creat_node();
	head->data=1;
	old=head;
	for(i=2;i<=10;i++)
	{
		new=creat_node();
		new->data=i;
		insert_node(old,new);
		old=new;
	}
	print(head);
	return head;
}



int del_node(struct node *list , int t )//将链表list中值为t的删除
{	struct node *temp;

	if(list==NULL)
	   printf("the list is NULL!");
        else
	    for(temp=list;;temp=temp->next)
	    {
		if((temp->data==t)&&temp->next!=NULL)
		    {
			temp->next->prev=temp->prev;
			temp->prev->next=temp->next;
		    }
		 else if((temp->data==t)&&temp->next==NULL)
			{	
				temp->prev->next=NULL;
			}
			else
				printf("have not find the node!");
		
	     }
		free(temp);
	
	return 0;	
	
}
int main(int argc,char *argv[])
{	
	int del;

	make_link();
	printf("input the number that you want to delete!\n");
	scanf("%d",&del);
	del_node(head,del);
	return 0 ;
}

