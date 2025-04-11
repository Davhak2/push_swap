#include "checker.h"

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
		infloop(a, b);
	}
}
