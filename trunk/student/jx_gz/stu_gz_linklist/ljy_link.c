#include<stdio.h>
#include<stdlib.h>

struct node
{
	int value;
	struct node *next;
	struct node *prev;
};

struct node *create_node(int i)
{
	struct node *new;
	new = malloc(sizeof(struct node));
	if(new == NULL)
	{
		puts("malloc error:\n");
		return NULL;
	}
	new->next = NULL;
	new->prev = NULL;
	new->value = i;
	return new;
}

struct node *insert(struct node *temp,struct node *new)
{
	temp->next = new;
	new->prev = temp;
	return new;
}

struct node *delete_node(struct node *head,int i)
{
	struct node *temp;
	int j = 0;
	temp = head;
	if(i == 1)
	{
		temp->next->prev =NULL;
		head = temp->next;
		free(temp);
		return head;
	}
	for(; temp->next != NULL; temp = temp->next)
	{	
		j ++;
		if(j == i)
		{
			temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			free(temp);
			return head;
		}
	}
	j ++;
	if(j == i)
	{
		temp->prev->next = NULL;
		free(temp);
		return head;
	}
	 if(j < i)
	 {
		printf("该链表没有这么多个节点,不能删除该节点。\n");
		return head;
	}

}
int main(int argc,char **argv)
{
	struct node *head,*temp;
	struct node *new;
	int i,j;
	char p;

	printf("请输入要创建节点数：");
	scanf("%d",&i);
	head = malloc(sizeof(struct node));
	head->next = NULL;
	head->prev = NULL;
	head->value = 1;
	temp = head;

	for(j = 1;j < i;j ++)
	{
		new = create_node(j+1);
		temp = insert(temp,new);
	}

	printf("是否需要删除节点(y:是，其它：否)：");
	getchar();
	scanf("%c",&p);
	if(p == 'y')
	{
		printf("请输入要删除第几个节点：");
		scanf("%d",&i);
		head = delete_node(head,i);
	}

	for(temp = head;temp->next != NULL;temp = temp->next)
		printf("%d  ",temp->value);
	printf("%d\n",temp->value);
	for(;temp->prev != NULL;temp = temp->prev)
		printf("%d  ",temp->value);
	printf("%d\n",temp->value);
	return 0;

}


