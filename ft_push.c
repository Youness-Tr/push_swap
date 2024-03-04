/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:30:23 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/03/04 18:28:48 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_list **b, t_list **a)
{
	push(a, (*b)->num);
	pop(b);
	printf("pa function\n");
}
void pb(t_list **a, t_list **b)
{
	push(b, (*a)->num);
	pop(a);
	printf("pb function\n");
}