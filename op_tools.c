/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:36:02 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/03/05 14:55:38 by ytarhoua         ###   ########.fr       */
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

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->num = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void push(t_list **stack, int num)
{
	t_list *new;

	new = ft_lstnew(num);
	new->next = (*stack);
	(*stack) = new;

}

void	pop(t_list **stack)
{
	t_list *tmp;

	tmp = (*stack);
	(*stack) = (*stack)->next;
	free(tmp);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (!lst || !new)
		return ;
	node = ft_lstlast(*lst);
	if (*lst)
		node->next = new;
	else
		*lst = new;
}

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