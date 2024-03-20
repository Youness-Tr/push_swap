/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:41:44 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/03/20 15:00:53 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "get_next_line.h"

void	ft_operations(t_list **A, t_list **B, char *line, t_data *data)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		sa(A, 0);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb(B, 0);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(B, A, 0);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(A, 0);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb(B, 0);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(A, B, 0);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rra(A, 0);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(B, 0);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(A, B, 0);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		pa(B, A, 0);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb(A, B, 0);
	else
		ft_error("ERROR !\n", data);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_list	*stack_a;
	t_list	*stack_b;
	char	*line;

	stack_a = NULL;
	stack_b = NULL;
	line = NULL;
	if (ac < 2)
		return (0);
	cat_all(ac, av, &data);
	ft_check(&data, 0, 0);
	fill_stack(&stack_a, &data);
	line = get_next_line(0);
	while (line)
	{
		ft_operations(&stack_a, &stack_b, line);
		free(line);
		line = get_next_line(0);
	}
	if (check_sorted(stack_a) == 0 || stack_b != NULL)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	return (0);
}

	// t_list *tmp;
	// tmp = (*A);
	// printf("op is : %s", line);
	// while (tmp)
	// {
	// 	printf("stack A => %d\n", tmp->num);
	// 	tmp = tmp->next;
	// }