/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:30:23 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/03/15 00:42:57 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **b, t_list **a, int i)
{
	if (!b || !*b)
		return ;
	push(a, (*b)->num);
	pop(b);
	if (i == 1)
		write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b, int i)
{
	if (!a || !*a)
		return ;
	push(b, (*a)->num);
	pop(a);
	if (i == 1)
		write(1, "pb\n", 3);
}

void	ra(t_list **a, int i)
{
	t_list	*last;
	t_list	*tmp;

	if (!a || !*a)
		return ;
	tmp = (*a)->next;
	last = ft_lstlast(*a);
	last->next = (*a);
	(*a)->next = NULL;
	(*a) = tmp;
	if (i == 1)
		write(1, "ra\n", 3);
}

void	rb(t_list **b, int i)
{
	t_list	*last;
	t_list	*tmp;

	if (!b || !*b)
		return ;
	tmp = (*b)->next;
	last = ft_lstlast(*b);
	last->next = (*b);
	(*b)->next = NULL;
	(*b) = tmp;
	if (i == 1)
		write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b, int i)
{
	ra(a, 0);
	rb(b, 0);
	if (i == 1)
		write(1, "rr\n", 3);
}
