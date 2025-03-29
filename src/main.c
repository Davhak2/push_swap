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
	{
		ft_putstr_fd("Memory allocation failed!\n", 2);
		exit(EXIT_FAILURE);
	}
	new->data = value;
	new->next = NULL;
	return (new);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putstr_fd("Your input should be\n./push_swap num1 num2 num3 ... numN.\n", 2);
		exit(1);
	}
	t_lst *head;
	int i;

	head = NULL;
	i = 0;
	while (++i < argc)
	{
		t_lst *new = allocate_node(ft_myatoi(argv[i], head));
		if (!head)
			head = new;
		else
		{
			t_lst *tmp = head;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
	if (contain_duplicates(head))
	{
		free_list(head);
		ft_putstr_fd("In your input contains duplicates", 2);
		exit(EXIT_FAILURE);
	}

	t_lst *tmp = head;
	while (tmp)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	free_list(head);
	exit(EXIT_SUCCESS);
}
