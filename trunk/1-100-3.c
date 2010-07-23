#include <stdio.h>
#include <stdlib.h>

struct link_names{
		int num ;
		struct link_names * next ;
};

struct link_names *head ;


struct link_names *  creat_link(struct link_names * link)
{
		link = malloc(sizeof(struct link_names));
		return link ;
		//    printf("link");
}

void insert_link(struct link_names * link , struct link_names * new)
{
		struct link_names * tmp ;
		tmp = link->next ;
		link->next = new ;
		new->next = tmp ;
}

void del_link(struct link_names * link)
{
		link->next = link->next->next ;
}

void init_link(void)
{
		struct link_names  *rear ,*tmp,*link;
		head = malloc(sizeof(struct link_names));
		rear = malloc(sizeof(struct link_names));

		head->num = 1 ;
		rear->num = 100 ;
		head->next = rear ;
		rear->next = head ;
		tmp = head ;
		int i ;

		for(i = 2 ; i < 100 ; i ++)
		{
				link = creat_link(link);
				link->num = i ;
				insert_link(tmp,link);
				tmp = link ;    
		}
}

int main(int * argc ,char ** argvs)
{
		init_link();
		struct link_names * tmp ;

		tmp = head ;    
		int i ;
		for(i = 1 ;i < 101 ; i ++ )
		{
				//printf("%d,",tmp->num);
				tmp = tmp->next ;
		}
		i = 1 ;

		while(tmp != tmp->next->next)
		{
				if(i%3 == 0)
				{    
				        printf("%d,",tmp->next->num);
						del_link(tmp);
						i++ ;
				}
				i ++ ;
				tmp = tmp->next ;
		}
		//printf("%d,%d\n",tmp->next->num,tmp->num);
}
