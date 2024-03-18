/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:26:32 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/03/16 21:23:58 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_range(t_data *data)
{
	data->rg = 1;
	if (data->size >= 6 && data->size <= 16)
		data->rg = 8;
	else if (data->size >= 17 && data->size <= 100)
		data->rg = 15;
	else if (data->size > 100)
		data->rg = 30;
	else if (data->size > 500)
		data->rg = 45;
}

int	find_index(t_list *stack, int start, int end)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack->num <= start && stack->num <= end)
			break ;
		index++;
		stack = stack->next;
	}
	return (index);
}

int	isbign(t_list *stack, int nb)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack->num == nb)
			break ;
		index++;
		stack = stack->next;
	}
	return (index);
}

void	push_to_a(t_list **a, t_list **b, t_data *data)
{
	int	i;

	i = data->size - 1;
	while (data->size > 0)
	{
		if (isbign(*b, data->tab[i]) <= (data->size / 2)
			&& isbign(*b, data->tab[i]) != 0)
			rb(b, 1);
		else
			rrb(b, 1);
		if (isbign(*b, data->tab[i]) == 0)
		{
			pa(b, a, 1);
			data->size--;
			i--;
		}
	}
}

void	ft_sort(t_list **a, t_list **b, t_data *data, int start)
{
	while (*a)
	{
		if (data->end > data->size -1)
			data->end = data->size -1;
		if ((*a)->num >= data->tab[start] && (*a)->num <= data->tab[data->end])
		{
			pb(a, b, 1);
			if (ft_lstsize(*b) >= 2 && (*b)->num < (*b)->next->num)
				sb(b, 1);
			start++;
			data->end++;
		}
		else if ((*a)->num < data->tab[start])
		{
			pb(a, b, 1);
			rb(b, 1);
			start++;
			data->end++;
		}
		else if (find_index(*a, data->tab[start], data->tab[data->end])
			>= (ft_lstsize(*a) / 2))
			rra(a, 1);
		else
			ra(a, 1);
	}
}
