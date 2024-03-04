/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:03:29 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/03/04 22:57:24 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_list **a)
{
    // t_list *f = (*a);
    // t_list *s = (*a)->next;
    // t_list *t = (*a)->next->next;

	if ((*a)->num > (*a)->next->num && (*a)->num > (*a)->next->next->num)
        ra(a, 1);
    if ((*a)->next->num > (*a)->num && (*a)->next->num > (*a)->next->next->num)
        rra(a, 1);
	if ((*a)->next->next->num > (*a)->num && (*a)->num > (*a)->next->num && (*a)->num > (*a)->next->num)
        sa(a, 1);
}
int check_sort(t_list *a, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        if ((a)->num > (a)->next->num)
            return (1);
        i++;
    }
    return (0);
}

// int small_one(t_list **a)
// {
//     t_list *tmp;
//     int small = 0;
//     int curr;
//     int i = 0;

//     tmp = (*a);
//     curr = (*a)->num;
//     while(tmp)
//     {
//         if (tmp->num < curr)
//         {
//             curr = tmp->num;
//             small = i;
//         }
//         i++;
//         tmp = tmp->next;
//     }
//     return(small);
// }

int small_one(t_list **a, int small_nb)
{
    t_list *tmp;
    int small = 0;

    tmp = *(a);
    while (tmp)
    {
        if (tmp->num == small_nb)
            break;
        small++;
        tmp = tmp->next;
    }
    return (small);
}

void sort_five(t_list **a, t_list **b, int size ,t_data *data)
{
    t_list *tmp;
    
    tmp = (*a);
    int i = 0;
    while (size > 3)
    {
        if (small_one(a, data->tab[i]) < (size / 2))
            ra(a, 1);
        else 
            rra(a, 1);
        // printf("small is %i\n", small_one(a, data->tab[i]));
        if (small_one(a, data->tab[i]) == 0)
        {
            pb(a, b);
            size--;
            i++;
        }
    }
    sort_three(a);
    while (i > 0)
    {
        pa(b, a);
        i--;
    }
}
void sorting(t_list **a, t_list **b,t_data *data)
{
    // int small_nb = data->tab[0];
    // int big = data->tab[data->i];
    int size = data->i;


	if(data->i <= 3)
		sort_three(a);
	else if(data->i <= 5)
		sort_five(a, b, size, data);
	else if(data->i <= 500)
		ft_sort(a, b, data);
}


int main(int ac, char** av)
{
    t_data data;
    t_list *A;
    t_list *B;

    A = NULL;
    int s = 0;

    if (ac < 2)
    {
        printf("error\n");
        return (1);
    }
    cat_all(ac, av, &data);
    ft_check(&data);
    fill_stack(&A, &data);
    ft_sort_int_tab(data.tab, data.i);
	sorting(&A, &B, &data);
     s = 0;
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
    return (0);
}