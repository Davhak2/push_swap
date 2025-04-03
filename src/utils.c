#include "push_swap.h"

void	free_list(t_lst *head)
{
	t_lst	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

t_lst	*allocate_node(int value)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (!new)
		ft_error("Error\n", NULL);
	new->data = value;
	new->next = NULL;
	return (new);
}

int	list_size(t_lst *head)
{
	int	i;

	i = 0;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}

int	is_empty(t_stack *stack)
{
	if (!stack)
		return (0);
	return (1);
}
