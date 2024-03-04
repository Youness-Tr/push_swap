#include "push_swap.h"

void sa(t_list **a,int f)
{
	t_list *tmp;
	
	tmp = (*a)->next;
	(*a)->next = (*a);
	(*a) = tmp;
	if (f == 1)
		printf("sa function\n");
}
void sb(t_list **b, int f)
{
	t_list *tmp;

	tmp = (*b)->next;
	(*b)->next = (*b);
	(*b) = tmp;
	if (f == 1)
		printf("sb function\n");
}
void ss(t_list **b,t_list **a)
{
	sa(a,0);
	sb(b,0);
	printf("ss function\n");
}
