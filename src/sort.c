#include "push_swap.h"

static int	chunk_size(int nb)
{
	int	sqrt;
	int	log;
	int	result;

	sqrt = 1;
	if (nb <= sqrt)
		return (sqrt);
	while (sqrt * sqrt < nb)
		++sqrt;
	log = 0;
	result = 1;
	while (result < nb)
	{
		result *= 2;
		++log;
	}
	return (sqrt + log - 1);
}

static bool	rot_frwd(t_lst *node, int target_idx, int size)
{
	int	steps;

	steps = 0;
	while (node && node->index != target_idx)
	{
		node = node->next;
		++steps;
	}
	return (steps <= size / 2);
}

static void	reverse_push(t_stack *a, t_stack *b, int max_idx)
{
	int	rotate_forward;

	while (b->lst)
	{
		rotate_forward = rot_frwd(b->lst, max_idx, list_size(b->lst));
		if (rotate_forward)
			while (b->lst->index != max_idx)
				rb(b, 1);
		else
			while (b->lst->index != max_idx)
				rrb(b, 1);
		pa(a, b, 1);
		max_idx--;
	}
}

void	butterfly(t_stack *a, t_stack *b)
{
	int	size;
	int	counter;
	int	total;

	total = list_size(a->lst);
	size = chunk_size(total);
	counter = 0;
	while (a->lst)
	{
		if (a->lst->index <= counter + size)
		{
			pb(a, b, 1);
			if (b->lst->index <= counter)
				rb(b, 1);
			counter++;
		}
		else
			ra(a, 1);
	}
	reverse_push(a, b, total - 1);
}
