/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:27:18 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/03/04 22:23:45 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_list **a, int i)
{
	t_list *last;
	t_list *tmp;
	if (!a || !*a)
		return ;
	tmp = (*a)->next;
	last = ft_lstlast(*a);
	last->next = (*a);
	(*a)->next = NULL;
	(*a) = tmp;
	if (i == 1)
		printf("ra\n");
}
void rb(t_list **b, int i)
{
	t_list *last;
	t_list *tmp;
	if (!b || !*b)
		return ;
	tmp = (*b)->next;
	last = ft_lstlast(*b);
	last->next = (*b);
	(*b)->next = NULL;
	(*b) = tmp;
	if (i == 1)
		printf("rb\n");
}
void rr(t_list **a, t_list **b)
{
	ra(a, 0);
	rb(b, 0);
	printf("rr\n");
}

void rra(t_list **a,int i)
{
	if (!(*a)->next || !(a))
		return;
	t_list *tmp;
	t_list *last;

	last = ft_lstlast(*a);
	tmp = ft_before(*a);
	last->next = (*a);
	tmp->next = NULL;
	(*a) = last;
	if (i == 1)
		printf("rra\n");
}
void rrb(t_list **b, int i)
{
	if (!(*b) || !(*b)->next)
		return;
	t_list *tmp;
	t_list *last;

	last = ft_lstlast(*b);
	tmp = ft_before(*b);
	last->next = (*b);
	tmp->next = NULL;
	(*b) = last;
	if (i == 1)
		printf("rrb\n");
}
void rrr(t_list **a, t_list **b)
{
	rra(a, 0);
	rrb(b, 0);	
	printf("rrr\n");
}