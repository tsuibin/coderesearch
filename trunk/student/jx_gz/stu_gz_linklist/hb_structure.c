#include <stdio.h>
#include <stdlib.h>
#define M 100

struct cloud{
	int valuse;
	struct cloud *priouse;
	struct cloud *next;
	};

//******创建头结点*******//
struct cloud *cleate(void)
{

	struct cloud *new_valuse;
	new_valuse = malloc (sizeof(struct cloud));
	if (new_valuse==NULL)
	{
		printf("malloc is error!");
		return NULL;
	}
	new_valuse->next=NULL;
	new_valuse->priouse=NULL;
	
	return new_valuse;
}

//**********************添加结点******************//
struct cloud *add_count (struct cloud *pa,int aa)
{
	struct cloud *new_valuse;
	if (pa == NULL)
	{
		printf("error!");
		return NULL;
	}
	if(aa==M+1)
	{
		return NULL;
	}
	new_valuse=malloc(sizeof(struct cloud));
	new_valuse->valuse=aa;
	pa->next=new_valuse;
	new_valuse->priouse=pa;
	new_valuse->next=NULL;
	
	return new_valuse->priouse;
}

//******************删除结点*****************//
struct cloud *delete_count (struct cloud *pb)
{
	struct cloud *kk,*hh;
	int a=1;
	kk=malloc(sizeof(struct cloud));
	hh=malloc(sizeof(struct cloud));
	kk=pb;
	while (kk->next->next!=kk)
	{
		if(a==3)
		{
			kk->next->priouse=kk->priouse;
			kk->priouse->next=kk->next;
			free(kk);
		}
		kk=kk->next;
		a++;
	}
	printf("%d %d",kk->valuse,kk->next->valuse);
	return NULL;
}

//*******************插入结点************************//
struct cloud *insert_count (struct cloud *count ,int bb)
{
	struct cloud *new_valuse;

	if(count==NULL)
		return NULL;
	new_valuse=malloc(sizeof (struct cloud));
	new_valuse->valuse = bb;
	while(count->valuse < new_valuse->valuse)
	{
		count=count->next;
	}
	if (new_valuse==NULL)
	{
		return NULL;
	}
	new_valuse->priouse=count;
	if(count->priouse == NULL)
		return NULL ;
	count->priouse->next=new_valuse;
	new_valuse->next=count;
	count->priouse=new_valuse;
	
	return NULL;
}
int main (int argc,char *argv)
{
	struct cloud *head,*new,*kk;
	int i,k;

	head = cleate();
	head->valuse=1;
	head->next=NULL;
	new=malloc (sizeof (struct cloud));
	new=head;
	for(i=2;i<=M;i++)
	{
		kk=add_count(new,i);
		new=kk->next;
	}
	while (head!=NULL)
	{
		printf("%d  ",head->valuse);
		head=head->next;
	}
	delete_count (head);
	insert_count (head,60);	
	/*while (head!=NULL)
	{
		printf("%d  ",head->valuse);
		head=head->next;
	}*/	
	
	return 0;
}
