/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:49:18 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/03/23 15:40:49 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*tmp;

	tmp = lst;
	len = 0;
	if (lst == NULL)
		return (0);
	while (tmp != NULL)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
	tmp = NULL;
}

void	sa(t_list **a, int f)
{
	t_list	*tmp;

	if (ft_lstsize(*a) == 1)
		return ;
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = *a;
	*a = tmp;
	if (f == 1)
		write(1, "sa\n", 3);
}

void	sb(t_list **b, int f)
{
	t_list	*tmp;

	if (!(*b) || !b)
		return ;
	tmp = (*b)->next;
	(*b)->next = tmp->next;
	tmp->next = *b;
	*b = tmp;
	if (f == 1)
		write(1, "sb\n", 3);
}

void	ss(t_list **b, t_list **a, int i)
{
	sa(a, 0);
	sb(b, 0);
	if (i == 1)
		write(1, "ss\n", 3);
}
