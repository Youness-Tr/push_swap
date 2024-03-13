/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:16:29 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/03/13 18:03:00 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_list **a, t_list **b, t_data *data)
{
	int	size;

	size = data->i;
	if (data->i == 3 || data->i == 2)
		sort_three(a, data);
	else if (data->i == 5 || data->i == 4)
		sort_five(a, b, size, data);
	else if (data->i >= 6)
		ft_sort(a, b, data);
}

void	sort_three(t_list **a, t_data *data)
{
	if (data->i == 2)
	{
		if ((*a)->num > (*a)->next->num)
			sa(a, 1);
	}
	else
	{
		if ((*a)->num > (*a)->next->num && (*a)->num > (*a)->next->next->num)
			ra(a, 1);
		if ((*a)->next->num > (*a)->num
			&& (*a)->next->num > (*a)->next->next->num)
			rra(a, 1);
		if ((*a)->next->next->num > (*a)->num
			&& (*a)->num > (*a)->next->num && (*a)->num > (*a)->next->num)
			sa(a, 1);
	}
}

void	sort_five(t_list **a, t_list **b, int size, t_data *data)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = (*a);
	while (size > 3)
	{
		if (small_one(a, data->tab[i]) < (size / 2))
			ra(a, 1);
		else
			rra(a, 1);
		if (small_one(a, data->tab[i]) == 0)
		{
			pb(a, b, 1);
			size--;
			i++;
		}
	}
	sort_three(a, data);
	while (i > 0)
	{
		pa(b, a, 1);
		i--;
	}
}

int check_sorted(t_list *stack)
{
	t_list *tmp;

	if (!stack)
		return (1);
	tmp = stack;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		// printf("stack => %d\n", tmp->num);
		tmp = tmp->next;
	}
	return (1);
}

int	small_one(t_list **a, int small_nb)
{
	t_list	*tmp;
	int		small;

	small = 0;
	tmp = *(a);
	while (tmp)
	{
		if (tmp->num == small_nb)
			break ;
		small++;
		tmp = tmp->next;
	}
	return (small);
}
