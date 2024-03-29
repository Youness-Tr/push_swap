/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 20:54:13 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/03/23 15:39:02 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				num;
	struct s_list	*next;

}	t_list;

typedef struct s_data
{
	int		size;
	char	**p;
	char	*str;
	int		*tab;
	t_list	*befor;
	int		rg;
	int		end;
}	t_data;

/*parsing*/
void	ft_sort_int_tab(int *tab, int size);
void	cat_all(int ac, char **av, t_data *data);
void	ft_check(t_data *data, int f, int s);
void	check_doubel(t_data *data, int f, int s);
void	fill_stack(t_list **a, t_data *data);

/*parsing tools*/
char	**ft_split(char const *s, char c);
char	*ft_strjoin_p(char *save, char *buff);
long	ft_atoi(char *nptr, long res, int i, t_data *data);
int		ft_isdigit(int c);
void	ft_free(char **p);
size_t	ft_strlen(const char *s);
void	ft_error(char *s, t_data *data);

/*operations*/
void	pa(t_list **b, t_list **a, int i);
void	pb(t_list **a, t_list **b, int i);
void	sa(t_list **a, int f);
void	sb(t_list **b, int f);
void	ss(t_list **b, t_list **a, int i);
void	ra(t_list **a, int i);
void	rb(t_list **b, int i);
void	rr(t_list **a, t_list **b, int i);
void	rra(t_list **a, int i);
void	rrb(t_list **b, int i);
void	rrr(t_list **a, t_list **b, int i);

/*op_tools*/
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_before(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	push(t_list **stack, int num);
void	pop(t_list **stack);
void	ft_lstclear(t_list **lst);

/*sorting*/
void	sorting(t_list **a, t_list **b, t_data *data);
void	sort_three(t_list **a, t_data *data);
void	sort_five(t_list **a, t_list **b, int size, t_data *data);
int		check_sorted(t_list *stack);
int		small_one(t_list **a, int small_nb);

/*algo*/
void	ft_range(t_data *data);
int		find_index(t_list *stack, int start, int end);
int		isbign(t_list *stack, int nb);
void	push_to_a(t_list **a, t_list **b, t_data *data);
void	ft_sort(t_list **a, t_list **b, t_data *data, int start);

#endif