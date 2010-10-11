#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct link)

struct link{
	int nu;
	struct link *next;
	struct link *pre;
}*head, *last;

/*struct link *create_new(void)
{
	struct link *new;

	if(new = malloc(LEN) == NULL)
	{
		printf("malloc error\n");
		return NULL;
	}
	
		new->next = NULL;
		new->pre  = NULL;
	return new;
}*/

void insert_new(struct link *new, struct link *old)
{
	struct link *p;

	if (old->next != NULL)
	{
		new->pre = old;
		new->next = old->next;
		old->next->pre = new;
		old->next = new;
	}
	else
	{
		old->next = new;
		new->next = NULL;
		new->pre  = old;
		last = new;
	}
	return ;
}

void del_3(struct link *link)/*隔3删除节点*/
{
	struct link *tmp, *p;

	while (link->next != link->pre)
	{
		tmp = link->next;
		link = tmp->next;
		tmp->next = link->next;
		link->next->pre = link->pre;
		free(link);
		link = tmp->next;
	}
    printf("%d,%d,%d",link->nu,link->next->nu,link->next->next->nu);

	return ;
}

int main(int argc, char *argv[])
{
	int i = 1;
	struct link *p, *tmp;

	head = malloc(LEN);
	head->nu = i;
	head->next = head;
	head->pre  = head;
	last = head;
	tmp	 = head; 
	
	for (i = 2; i <= 100; i ++)
	{
		p = malloc(LEN);
		if(p == NULL)
		{
			printf("malloc error\n");
			return -1;
		}
		p->next = NULL;
		p->pre  = NULL;
		p->nu = i;
		insert_new(p, tmp);
		tmp = p;
	}

	tmp = head;
	for (i = 1; i <= 200; i ++)/*正向遍历*/
	{
		printf("%d\n",tmp->nu);
		tmp = tmp->next;
	}
	tmp = last;
	for (i = 1; i <= 200; i ++)/*反向遍历*/
	{
		printf("%d\n",tmp->nu);
		tmp = tmp->pre;
	}
	del_3(head);
	printf("\n");
	return 0;
}
