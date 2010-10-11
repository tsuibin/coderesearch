//双向链表

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node *prev;
	struct node *next;
};
struct node *head;

void insert_node(struct node *,struct node *);
void del_node(struct node *);

int main (int argc, char *argv[])
{
	int i, a, b;
	struct node *current, *new, *del;
	head = malloc(sizeof(struct node));
	head->value = 1;
	head->next = NULL;
	head->prev = NULL;
	current = head;
	
	printf("请输入要建立的节点数目");
	scanf("%d",&b);

	for(i = 2; i <= b; i++)
	{
		new = malloc(sizeof(struct node));
		new->value = i;
		insert_node(current, new);
		current = new;
	}
	puts("原序列为：");
	current = head;
	while(current->next != NULL)
	{
		printf("%d    ",current->value);
		current = current->next;
	}
	printf("%d    ",current->value);
	putchar('\n');
	
	printf("请输入要删除的节点");
	scanf("%d",&a);
	del = head;
	for(i = 1; i < a; i++)
		del = del->next;
	del_node(del);     //删除第9个节点

	current = head;
	while(current->next != NULL)
	{
		printf("%d    ",current->value);
		current = current->next;
	}
	printf("%d    ",current->value);
	putchar('\n');

	return 0;
}

void insert_node(struct node *current, struct node *new)
{
	if(current == NULL)
	{
		printf("无法插入\n");
		return ;
	}
	
	new->prev = current;
	current->next = new;
	new->next = NULL;

	return ;
}

void del_node(struct node *current)
{
	if(current == NULL)
	{
		printf("无法删除\n");
		return ;
	}
	if(current->prev == NULL)
	{
		current->next->prev = NULL;
		head = head->next;
		free(current);
		return ;
	}

	if(current->next == NULL)
	{
		current->prev->next = NULL;
		free(current);
		return ;
	}
	else
	{	
		current->next->prev = current->prev;
		current->prev->next = current->next;
		free(current);
		return ;
	}

	return ;
}
