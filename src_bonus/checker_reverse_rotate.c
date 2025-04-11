#include "checker.h"

void	rra(t_stack *stack, int flag)
{
	t_lst	*first;
	t_lst	*last;
	t_lst	*tmp;

	if (!is_empty(stack) || list_size(stack->lst) < 2)
		return ;
	first = stack->lst;
	while (first->next)
		first = first->next;
	last = stack->lst;
	tmp = last;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	stack->lst = first;
	first->next = last;
	if (flag)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *stack, int flag)
{
	t_lst	*first;
	t_lst	*last;
	t_lst	*tmp;

	if (!is_empty(stack) || list_size(stack->lst) < 2)
		return ;
	first = stack->lst;
	while (first->next)
		first = first->next;
	last = stack->lst;
	tmp = last;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	stack->lst = first;
	first->next = last;
	if (flag)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *s1, t_stack *s2)
{
	rra(s1, 0);
	rrb(s2, 0);
}
