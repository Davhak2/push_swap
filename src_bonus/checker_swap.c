#include "checker.h"

void	sa(t_stack *stack, int flag)
{
	t_lst	*a;
	t_lst	*b;

	if (is_empty(stack) && list_size(stack->lst) >= 2)
	{
		a = stack->lst;
		b = stack->lst->next;
		a->next = b->next;
		b->next = a;
		stack->lst = b;
	}
	if (flag)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *stack, int flag)
{
	t_lst	*a;
	t_lst	*b;

	if (is_empty(stack) && list_size(stack->lst) >= 2)
	{
		a = stack->lst;
		b = stack->lst->next;
		a->next = b->next;
		b->next = a;
		stack->lst = b;
	}
	if (flag)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *st1, t_stack *st2)
{
	sa(st1, 0);
	sb(st2, 0);
}

void	pa(t_stack *a, t_stack *b, int flag)
{
	t_lst	*tmp;

	if (!b->lst)
		return ;
	tmp = b->lst;
	b->lst = b->lst->next;
	tmp->next = a->lst;
	a->lst = tmp;
	if (flag)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *a, t_stack *b, int flag)
{
	t_lst	*tmp;

	if (!a->lst)
		return ;
	tmp = a->lst;
	a->lst = a->lst->next;
	tmp->next = b->lst;
	b->lst = tmp;
	if (flag)
		ft_putstr_fd("pb\n", 1);
}
