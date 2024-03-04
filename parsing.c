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

void cat_all(int ac, char **av, t_data *data)
{
    data->i = 1;
    data->str = NULL;
    data->p = NULL;
    data->tab = NULL;

    while (data->i < ac)
    {
        data->str = ft_strjoin(data->str, av[data->i]);
        data->i++;
    }
    data->p = ft_split(data->str, ' ');
    data->i = 0;
    while (data->p[data->i] != '\0')
        data->i++;
    if (data->i == 0)
        ft_error("error");
    data->tab = malloc(sizeof(int) * data->i);
    if (!data->tab)
        exit (0);
}

void ft_check(t_data *data)
{
    int s = 0;
    int f = 0;

    while (data->i > 0)
    {
        s = 0;
        if (data->p[f][s] == '+' || data->p[f][s] == '-')
            s++;
        if (!data->p[f][s])
            ft_error("error\n");
        while (data->p[f][s])
        {
            printf("p[i][s] is : %c\n", data->p[f][s]);
            printf("----------------\n");
            if (!ft_isdigit(data->p[f][s]))
                ft_error("error\n");
            s++;
        }
        s = 0;
        data->tab[f] = ft_atoi(data->p[f]);
        s = f - 1;
        while (f > s && f != 0 && s >= 0)
        {
            if (data->tab[f] == data->tab[s])
                ft_error("error\n");
            s--;
        }
        printf("num[i] is : %i \n", data->tab[f]);
        f++;
        data->i--;
    }
    data->i = f;
}


void fill_stack(t_list **a, t_data *data)
{
    int c;

    c = 0;
    // a->num = data->tab[c];
    while (c < data->i)
    {
        ft_lstadd_back(a, ft_lstnew(data->tab[c]));
        c++;
    }
    printf("%i \n", c);
}
