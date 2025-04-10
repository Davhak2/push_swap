#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_lst	*head;
	t_stack	*a;
	t_stack	*b;
	int		size;

	if (argc < 2)
		exit(EXIT_FAILURE);
	else
	{
		head = parse_input(argc, argv);
		assign_indexes(head);
		a = malloc(sizeof(t_stack));
		b = malloc(sizeof(t_stack));
		if (!a || !b)
			ft_error("Memory allocation failed\n", head);
		a->lst = head;
		b->lst = NULL;
		size = list_size(a->lst);
		if (size > 1)
			butterfly(a, b);
		free_list(a->lst);
		free(a);
		free(b);
		return (0);
	}
}
