#include "push_swap.h"

void print_stack(const char *name, t_lst *lst)
{
	printf("%s: ", name);
	while (lst)
	{
		printf("%d ", lst->data);
		lst = lst->next;
	}
	printf("\n");
}

t_lst *copy_list(t_lst *head)
{
	t_lst *copy = NULL, *tmp = NULL, *new;

	while (head)
	{
		new = allocate_node(head->data);
		if (!new)
		{
			free_list(copy);
			return NULL;
		}
		if (!copy)
			copy = new;
		else
			tmp->next = new;
		tmp = new;
		head = head->next;
	}
	return copy;
}

int main(int argc, char **argv)
{
	t_lst *head = NULL, *tmp;
	t_stack *a, *b;
	char **split_args;
	int i = 0, j;

	if (argc < 2)
		exit(EXIT_FAILURE);

	while (++i < argc)
	{
		split_args = ft_split(argv[i], ' ');
		if (!split_args)
			ft_error("Memory allocation failed\n", head);
		j = 0;
		while (split_args[j])
		{
			t_lst *new = allocate_node(ft_myatoi(split_args[j], head));
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

	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	if (!a || !b)
		ft_error("Memory allocation failed\n", head);
	a->lst = head;
	b->lst = copy_list(head);
	if (!b->lst)
		ft_error("Memory allocation failed while copying\n", head);

	// --- Test ra ---
	printf("\n--- Testing ra ---\n");
	print_stack("A before ra", a->lst);
	ra(a, 1);
	print_stack("A after ra", a->lst);

	// --- Test rb ---
	printf("\n--- Testing rb ---\n");
	print_stack("B before rb", b->lst);
	rb(b, 1);
	print_stack("B after rb", b->lst);

	// --- Test rr ---
	printf("\n--- Testing rr ---\n");

	print_stack("A before rr", a->lst);
	print_stack("B before rr", b->lst);
	rr(a, b);
	print_stack("A after rr", a->lst);
	print_stack("B after rr", b->lst);

	// Free memory
	free_list(a->lst);
	free_list(b->lst);
	free(a);
	free(b);

	exit(EXIT_SUCCESS);
}
