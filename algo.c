/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:26:32 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/03/05 17:43:12 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"
void ft_range(t_data *data)
{
	data->rg = 1;
	if (data->i >= 6 && data->i <= 16)
		data->rg = 3;
	else if (data->i >= 17 && data->i <= 100)
		data->rg = 15;
	else if (data->i > 100)
		data->rg = 29;
	else if (data->i > 500)
		data->rg = 45;
}

int find_index(t_list *stack, int start, int end)
{
	int index = 0;
	int find = 0;
	
	while (stack)
	{
		if (stack->num == start)
			break;
		if (stack->num >= start && stack->num <= end)
		{
			break;
			find = 1;
		}
		index++;
		stack = stack->next;
	}
	if (find == 1)
		return (index);
	return (0);
}

int isbign(t_list *stack, int nb)
{
	 int index = 0;

    while (stack)
    {
        if (stack->num == nb)
            break;
        index++;
        stack = stack->next;
    }
    return (index);
}
 void push_to_a(t_list **a, t_list **b,t_data *data)
 {
	int i = data->i - 1;
	while (data->i > 0)
	{
		if (isbign(*b,data->tab[i]) <= (data->i / 2) && isbign(*b,data->tab[i]) != 0)
			rb(b,1);
		else
			rrb(b,1);
		if (isbign(*b,data->tab[i]) == 0)
		{
			pa(b,a);
			data->i--;
			i--;
		}
	}
 }

void ft_sort(t_list **a, t_list **b, t_data *data)
{
	int start = 0;
	int end;

	ft_range(data);
	end = data->rg;
	while (*a)
	{
		if (end > data->i -1)
			end = data->i -1;
		if ((*a)->num >= data->tab[start] && (*a)->num <= data->tab[end])
		{
			pb(a,b);
			if (ft_lstsize(*b) >= 2 && (*b)->num < (*b)->next->num)
				sb(b, 1);
			start++;
			end++;
		}
		else if((*a)->num < data->tab[start])
		{
			// printf("\033[1;31melse if \033[0m\n");
			pb(a,b);
			rb(b,1);
			start++;
			end++;
		}
		else if((*a)->num > data->tab[end])
		{
			if (find_index(*a, data->tab[start], data->tab[end]) <= (ft_lstsize(*b) / 2))
		 		ra(a,1);
			else
				rra(a, 1);
		}
	}
	// printf("\033========================================\n\033[0m\n");
	// while ((*b))
	// {
	// 	printf("\033[1;32m[%d] \n\033[0m\n",(*b)->num);
	// 	(*b) = (*b)->next;
	// }
	// printf("\033========================================\n\033[0m\n");
	push_to_a(a, b, data);
}

// void    algorithm(t_list **stack_a, t_list **stack_b, t_data *data)
// {
//     int    start;
//     int    end;

//     start = 0;
//     end = buffersize(data);
//     while (*stack_a)
//     {
//         if (end > data->size)
//             end = data->size;
//         if ((*stack_a)->content > data->array[start]
//             && (*stack_a)->content <= data->array[end])
//         {
//             pb(stack_a, stack_b);
//             if (ft_lstsize(*stack_b) > 2
//                 && (*stack_b)->content < (*stack_b)->next->content)
//                 sa(stack_a);
//             start++;
//             end++;
//         }
//         else if ((*stack_a)->content <= data->array[start])
//         {
//             pb(stack_a, stack_b);
//             rb(stack_b);
//             start++;
//             end++;
//         }
//         else
//             ra(stack_a);
//     }
// }