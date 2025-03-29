#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_lst	*head;
	int		i;
	t_lst	*new;
	t_lst	*tmp;
	t_stack	*st1;

	if (argc < 2)
	{
		ft_putstr_fd("Your input should be\n./push_swap num1 num2 num3 ... numN.\n", 2);
		exit(1);
	}
	head = NULL;
	i = 0;
	while (++i < argc)
	{
		new = allocate_node(ft_myatoi(argv[i], head));
		if (!new)
			ft_error("Memory allocation failed\n", head);
		if (!head)
			head = new;
		else
		{
			tmp = head;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
	if (contain_duplicates(head))
		ft_error("Error\n", head);

	st1 = malloc(sizeof(t_stack));
	if (!st1)
		ft_error("Memory allocation failed\n", head);
	st1->lst = head;

	printf("%d\n", ft_list_size(st1));

	if (st1->lst && st1->lst->next)
		sa(st1);

	tmp = st1->lst;
	while (tmp)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");

	free_list(st1->lst);
	free(st1);
	exit(EXIT_SUCCESS);
}
