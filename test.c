#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


typedef struct s_list
{
	int data;
	struct s_list	*next;
	struct s_list	*prev;
} t_list;

// t_list	*ft_lstnew(void *num)
// {
// 	t_list	*new;

// 	new = (t_list *)malloc(sizeof(t_list));
// 	if (!new)
// 		return (NULL);
// 	new->data = num;
// 	new->next = NULL;
// 	new->prev = NULL;

// 	return (new);
// }

void addback(t_list **head, int i)
{
	t_list *new_node = malloc(sizeof(t_list));
	if (!new_node)
		exit(1);
	new_node->data = i;
	new_node->next = NULL;
	new_node->prev = *head;
	(*head)->next = new_node;
	*head = new_node;

}

void addfront(t_list **tail, int i)
{
	t_list *new_node = malloc(sizeof(t_list));
	if (!new_node)
		exit(1);
	new_node->data = i;
	new_node->prev = NULL;
	new_node->next = *tail;
	(*tail)->prev = new_node;
	*tail = new_node;
}

void init(t_list **head, t_list **tail, int i)
{
	t_list new = malloc(sizeof(t_list));
	if (!new)
		exit 1;
	new->n

}

int main()
{
	int i = 0;
	int c = 0;

	t_list *tail = malloc(sizeof(t_list));
	t_list *head = malloc(sizeof(t_list));
	t_list *tmp;

	tail->prev = NULL;
	tail->data = 125;
	tail->next = NULL;
	while (i < 5)
	{
		addfront(&tail, i);
		i++;
	}
	tmp = tail;
	while (tmp)
	{
		printf("value is : %i\n", tmp->data);
		tmp = tmp->next;
	}
}

./s	 "54 57 9 6" "5 58"
