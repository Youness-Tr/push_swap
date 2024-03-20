/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:16:18 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/03/20 15:13:35 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}

void	cat_all(int ac, char **av, t_data *data)
{
	data->size = 1;
	data->str = NULL;
	data->p = NULL;
	data->tab = NULL;
	while (data->size < ac)
	{
		data->str = ft_strjoin_p(data->str, av[data->size]);
		data->size++;
	}
	data->p = ft_split(data->str, ' ');
	free(data->str);
	data->size = 0;
	while (data->p[data->size] != '\0')
		data->size++;
	if (data->size == 0)
		ft_error("Error\n", data);
	data->tab = malloc(sizeof(int) * data->size);
	if (!data->tab)
		exit (0);
}

void	ft_check(t_data *data, int f, int s)
{
	while (data->size > 0)
	{
		s = 0;
		if (data->p[f][s] == '+' || data->p[f][s] == '-')
			s++;
		if (!data->p[f][s])
			ft_error("Error\n", data);
		while (data->p[f][s])
		{
			if (!ft_isdigit(data->p[f][s]))
				ft_error("grror\n", data);
			s++;
		}
		s = 0;
		data->tab[f] = ft_atoi(data->p[f], 0, 0, data);
		if (data->tab[f])
			s = f - 1;
		check_doubel(data, f, s);
		f++;
		data->size--;
	}
	data->size = f;
}

void	check_doubel(t_data *data, int f, int s)
{
	while (f > s && f != 0 && s >= 0)
	{
		if (data->tab[f] == data->tab[s])
		{
			ft_error("Error\n", data);
		}
		s--;
	}
}

void	fill_stack(t_list **a, t_data *data)
{
	int	c;

	c = 0;
	while (c < data->size)
	{
		ft_lstadd_back(a, ft_lstnew(data->tab[c]));
		c++;
	}
}
