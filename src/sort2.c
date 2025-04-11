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

void	sort_2pairs(t_stack *a)
{
	if (a->lst->index > a->lst->next->index)
		sa(a, 1);
}

void	sort_3pairs(t_stack *a)
{
	if (a->lst->index == 2 && a->lst->next->index == 0)
		ra(a, 1);
	else if (a->lst->index == 2 && a->lst->next->index == 1)
	{
		ra(a, 1);
		sa(a, 1);
	}
	else if (a->lst->index == 1 && a->lst->next->index == 2)
		rra(a, 1);
	else if (a->lst->index == 1 && a->lst->next->index == 0)
		sa(a, 1);
	else if (a->lst->index == 0 && a->lst->next->index == 2)
	{
		sa(a, 1);
		ra(a, 1);
	}
}

void	sort_4pairs(t_stack *a, t_stack *b)
{
	while (a->lst->index != 3)
	{
		if (max_index(a, 4))
			ra(a, 1);
		else
			rra(a, 1);
	}
	pb(a, b, 1);
	sort_3pairs(a);
	pa(a, b, 1);
	ra(a, 1);
}

static void	sorting_5_1(t_stack *a)
{
	if (a->lst->index == 4 && a->lst->next->index == 2)
		ra(a, 1);
	else if (a->lst->index == 4 && a->lst->next->index == 3)
	{
		ra(a, 1);
		sa(a, 1);
	}
	else if (a->lst->index == 3 && a->lst->next->index == 4)
		rra(a, 1);
	else if (a->lst->index == 3 && a->lst->next->index == 2)
		sa(a, 1);
	else if (a->lst->index == 2 && a->lst->next->index == 4)
	{
		sa(a, 1);
		ra(a, 1);
	}
}

void	sort_5pairs(t_stack *a, t_stack *b)
{
	int	j;
	int	i;

	i = 2;
	j = 0;
	while (j != 2)
	{
		while (a->lst->index != i - 1)
		{
			if (max_index(a, i) == 1)
				ra(a, 1);
			else
				rra(a, 1);
		}
		pb(a, b, 1);
		--i;
		++j;
	}
	sorting_5_1(a);
	if (b->lst->index < b->lst->next->index)
		sb(b, 1);
	pa(a, b, 1);
	pa(a, b, 1);
}
