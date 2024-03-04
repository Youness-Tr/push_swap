/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:26:32 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/03/04 22:38:28 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"
void ft_range(t_data *data)
{
	data->rg = 1;
	if (data->i >= 6 && data->i <= 16)
		data->rg = 8;
	else if (data->i >= 17 && data->i <= 100)
		data->rg = 15;
	else if (data->i > 100)
		data->rg = 30;
	else if (data->i > 500)
		data->rg = 45;
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
			// printf("\033[1;31mif lowla\033[0m\n");
			pb(a,b);
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
			// printf("\033[1;31melse \033[0m\n");
		 	ra(a,1);
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