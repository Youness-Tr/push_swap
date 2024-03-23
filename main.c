/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:03:29 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/03/23 16:49:40 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	cat_all(ac, av, &data);
	ft_check(&data, 0, 0);
	fill_stack(&stack_a, &data);
	if (check_sorted(stack_a) == 0)
	{
		ft_sort_int_tab(data.tab, data.size);
		sorting(&stack_a, &stack_b, &data);
	}
	ft_free(data.p);
	free(data.tab);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
