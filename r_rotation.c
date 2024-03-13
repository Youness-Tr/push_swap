/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:27:18 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/03/13 17:07:45 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (0);
	tmp = lst;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

t_list	*ft_before(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (0);
	tmp = lst;
	while (tmp->next->next != NULL)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

void	rra(t_list **a, int i)
{
	t_list	*tmp;
	t_list	*last;

	if (!(*a)->next || !(a))
		return ;
	last = ft_lstlast(*a);
	tmp = ft_before(*a);
	last->next = (*a);
	tmp->next = NULL;
	(*a) = last;
	if (i == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_list **b, int i)
{
	t_list	*tmp;
	t_list	*last;

	if (!(*b) || !(*b)->next)
		return ;
	last = ft_lstlast(*b);
	tmp = ft_before(*b);
	last->next = (*b);
	tmp->next = NULL;
	(*b) = last;
	if (i == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b, int i)
{
	rra(a, 0);
	rrb(b, 0);
	if (i == 1)
		write(1, "rrr\n", 4);
}
