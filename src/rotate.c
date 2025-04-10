#include "push_swap.h"

void	ra(t_stack *stack, int flag)
{
	t_lst	*first;
	t_lst	*last;

	if (!is_empty(stack) || list_size(stack->lst) < 2)
		return ;
	first = stack->lst;
	stack->lst = stack->lst->next;
	first->next = NULL;
	last = stack->lst;
	while (last->next)
		last = last->next;
	last->next = first;
	if (flag)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *stack, int flag)
{
	t_lst	*first;
	t_lst	*last;

	if (!is_empty(stack) || list_size(stack->lst) < 2)
		return ;
	first = stack->lst;
	stack->lst = stack->lst->next;
	first->next = NULL;
	last = stack->lst;
	while (last->next)
		last = last->next;
	last->next = first;
	if (flag)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *s1, t_stack *s2)
{
	ra(s1, 0);
	rb(s2, 0);
	ft_putstr_fd("rr\n", 1);
}
