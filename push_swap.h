#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct s_list
{
	int num;
	struct s_list *next;

}	t_list;

typedef struct s_data 
{
	int i;
	char **p;
	char *str;
	int *tab;
	t_list *befor;
	int m;
	int f;
}	t_data;

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/*parsing*/
void	ft_sort_int_tab(int *tab, int size);
void cat_all(int ac, char **av, t_data *data);
void ft_check(t_data *data);
void fill_stack(t_list **a, t_data *data);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *save, char *buff);
long		ft_atoi(const char *nptr);
int	ft_isdigit(int c);
void	ft_free(char **map);
size_t	ft_strlen(const char *s);
void	ft_error(char *s);


/*stack*/
t_list	*ft_lstnew(int num);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_before(t_list *lst);

void push(t_list **stack, int num);
void	pop(t_list **stack);

/*operations*/
void sa(t_list **a,int f);
void pa(t_list **b, t_list **a);
void pb(t_list **a, t_list **b);
void ra(t_list **a, int i);
void rra(t_list **a,int i);
void rrb(t_list **b, int i);
void rrr(t_list **a, t_list **b);


#endif