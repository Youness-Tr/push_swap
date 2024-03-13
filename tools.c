/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:17:51 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/03/13 16:25:26 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack, int num)
{
	t_list	*new;

	new = ft_lstnew(num);
	new->next = (*stack);
	(*stack) = new;
}

void	pop(t_list **stack)
{
	t_list	*tmp;

	tmp = (*stack);
	(*stack) = (*stack)->next;
	free(tmp);
}

void	ft_error(char *s)
{
	write(1, s, ft_strlen(s));
	// system("leaks push_swap");
	exit(1);
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
