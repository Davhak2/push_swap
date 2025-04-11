#include "push_swap.h"

int	max_index(t_stack *stack, int i)
{
	t_lst	*tmp;

	tmp = stack->lst;
	while (tmp->index)
	{
		if (tmp->index == i - 1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static void	sort_stack(t_stack *a, t_stack *b)
{
	int	size;

	size = list_size(a->lst);
	if (size == 2)
		sort_2pairs(a);
	else if (size == 3)
		sort_3pairs(a);
	else if (size == 4)
		sort_4pairs(a, b);
	else if (size == 5)
		sort_5pairs(a, b);
	else
		butterfly(a, b);
}

int	main(int argc, char **argv)
{
	t_lst	*head;
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		exit(EXIT_FAILURE);
	else
	{
		head = parse_input(argc, argv);
		assign_indexes(head);
		a = (t_stack *)malloc(sizeof(t_stack));
		b = (t_stack *)malloc(sizeof(t_stack));
		if (!a || !b)
			ft_error("Memory allocation failed\n", head);
		a->lst = head;
		b->lst = NULL;
		sort_stack(a, b);
		free_list(a->lst);
		free(a);
		free(b);
		return (0);
	}
}
