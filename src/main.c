#include "push_swap.h"

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

void	print_list(t_lst *lst)
{
	printf("List:\n");
	while (lst)
	{
		printf("%d(%d)", lst->data, lst->index);
		if (lst->next)
			printf(" -> ");
		lst = lst->next;
	}
	printf(" -> NULL\n");
}

#include <stdio.h>

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
		//print_list(a->lst);
		free_list(a->lst);
		free(a);
		free(b);
		return (0);
	}
}
