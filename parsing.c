/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:16:18 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/03/13 17:53:07 by ytarhoua         ###   ########.fr       */
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
	data->i = 1;
	data->str = NULL;
	data->p = NULL;
	data->tab = NULL;
	while (data->i < ac)
	{
		data->str = ft_strjoin_p(data->str, av[data->i]);
		data->i++;
	}
	data->p = ft_split(data->str, ' ');
	data->i = 0;
	while (data->p[data->i] != '\0')
		data->i++;
	if (data->i == 0)
		ft_error("Error\n");
	data->tab = malloc(sizeof(int) * data->i);
	if (!data->tab)
		exit (0);
}

void	ft_check(t_data *data, int f, int s)
{
	while (data->i > 0)
	{
		s = 0;
		if (data->p[f][s] == '+' || data->p[f][s] == '-')
			s++;
		if (!data->p[f][s])
			ft_error("Error\n");
		while (data->p[f][s])
		{
			if (!ft_isdigit(data->p[f][s]))
				ft_error("Error\n");
			s++;
		}
		s = 0;
		data->tab[f] = ft_atoi(data->p[f], 0, 0);
		// printf("data->tab[f] : %i\n", data->tab[f]);
		if (data->tab[f])
			s = f - 1;
		check_doubel(data, f, s);
		f++;
		data->i--;
	}
	data->i = f;
}

void	check_doubel(t_data *data, int f, int s)
{
	while (f > s && f != 0 && s >= 0)
	{
		// printf("s is : %i and f is : %i\n", s, f);
		// printf("data->tab[f] : %i data->tab[s] : %i\n", data->tab[f], data->tab[s]);
		if (data->tab[f] == data->tab[s])
		{
			ft_error("Error\n");
		}
		s--;
	}
}

void	fill_stack(t_list **a, t_data *data)
{
	int	c;

	c = 0;
	while (c < data->i)
	{
		ft_lstadd_back(a, ft_lstnew(data->tab[c]));
		c++;
	}
}
