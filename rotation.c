/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:27:18 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/03/04 17:57:19 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_list **a, int i)
{
	t_list *last;
	t_list *tmp;

	tmp = (*a)->next;
	last = ft_lstlast(*a);
	last->next = (*a);
	(*a)->next = NULL;
	(*a) = tmp;
	if (i == 1)
		printf("ra function\n");
}
void rb(t_list **b, int i)
{
	t_list *last;
	t_list *tmp;

	tmp = (*b)->next;
	last = ft_lstlast(*b);
	last->next = (*b);
	(*b)->next = NULL;
	(*b) = tmp;
	if (i == 1)
		printf("sa function\n");
}
void rr(t_list **a, t_list **b)
{
	ra(a, 0);
	rb(b, 0);
	printf("sa function\n");
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
		printf("rra function\n");
}
void rrb(t_list **b, int i)
{
	if (!(*b)->next || !(b))
		return;
	t_list *tmp;
	t_list *last;

	last = ft_lstlast(*b);
	tmp = ft_before(*b);
	last->next = (*b);
	tmp->next = NULL;
	(*b) = last;
	if (i == 1)
		printf("rrb function\n");
}
void rrr(t_list **a, t_list **b)
{
	rra(a, 0);
	rrb(b, 0);	
	printf("sa function\n");
}