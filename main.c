/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:03:29 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/03/16 21:26:24 by ytarhoua         ###   ########.fr       */
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
	return (0);
}
	// int s = 0;
	// t_list *curr;
	// // pb(&A, &B);
	// curr = A;
	// while (curr)
	// {
	//     printf("node [%i] is : %i \n", s, curr->num);
	//     curr = curr->next;
	//     s++;
	// }
	// printf("end\n");
	// system("leaks push_swap");
/*
write -> printf and exit in error cases and norm
and checker handle also test all things
*/
