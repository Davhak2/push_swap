#include "checker.h"

static void	exit_from_input(t_stack *a, t_stack *b, int flag, char *str)
{
	if (str)
		ft_putstr_fd(str, 1);
	if (a)
	{
		if (a->lst)
			free_list(a->lst);
		free(a);
	}
	if (b)
	{
		if (b->lst)
			free_list(b->lst);
		free(b);
	}
	exit(flag);
}

static bool	input_commands(t_stack *a, t_stack *b, char *str)
{
	if (!ft_strncmp(str, "sa\n", 3))
		sa(a, 0);
	else if (!ft_strncmp(str, "sb\n", 3))
		sb(b, 0);
	else if (!ft_strncmp(str, "ss\n", 3))
		ss(a, 0);
	else if (!ft_strncmp(str, "ra\n", 3))
		ra(a, 0);
	else if (!ft_strncmp(str, "rb\n", 3))
		rb(b, 0);
	else if (!ft_strncmp(str, "rr\n", 3))
		rr(a, b);
	else if (!ft_strncmp(str, "rra\n", 4))
		rra(a, 0);
	else if (!ft_strncmp(str, "rrb\n", 4))
		rrb(b, 0);
	else if (!ft_strncmp(str, "rrr\n", 4))
		rrr(a, b);
	else if (!ft_strncmp(str, "pa\n", 3))
		pa(a, b, 0);
	else if (!ft_strncmp(str, "pb\n", 3))
		pb(a, b, 0);
	else
		return (true);
	return (false);
}

static int	are_you_okay(t_lst *list)
{
	t_lst	*tmp;
	t_lst	*curr;

	if (!list)
		return (0);
	tmp = list->next;
	curr = list;
	while (tmp)
	{
		if (curr->data > tmp->data)
			return (0);
		tmp = tmp->next;
		curr = curr->next;
	}
	return (1);
}

void	infloop(t_stack *a, t_stack *b)
{
	char	*str;
	bool	error;

	error = false;
	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		if (input_commands(a, b, str))
		{
			free(str);
			error = true;
			break ;
		}
		free(str);
	}
	if (error)
		exit_from_input(a, b, 0, "Error\n");
	if (a->lst && are_you_okay(a->lst) && !b->lst)
		exit_from_input(a, b, 0, "OK\n");
	else
		exit_from_input(a, b, 1, "KO\n");
}
