#include "push_swap.h"

int main(int argc, char **argv)
{
	t_lst *head;
	int i, j;
	t_lst *new;
	t_lst *tmp;
	t_stack *st1;
	char **split_args;

	if (argc < 2)
		exit(EXIT_FAILURE);
	head = NULL;
	i = 0;
	while (++i < argc)
	{
		split_args = ft_split(argv[i], ' ');
		if (!split_args)
			ft_error("Memory allocation failed\n", head);
		j = 0;
		while (split_args[j])
		{
			new = allocate_node(ft_myatoi(split_args[j], head));
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
			free(split_args[j]);
			j++;
		}
		free(split_args);
	}
	if (contain_duplicates(head))
		ft_error("Error\n", head);
	st1 = malloc(sizeof(t_stack));
	if (!st1)
		ft_error("Memory allocation failed\n", head);
	st1->lst = head;
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
