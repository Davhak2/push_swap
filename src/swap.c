#include "push_swap.h"

t_lst	*reverseList(t_lst *head)
{
	t_lst *a;
	t_lst *b;

	a = NULL;
	b = NULL;
	while (head)
	{
		a = head->next;
		head->next = b;
		b = head;
		head = a;
	}
	head = b;
	return (head);
}

void	sa(t_stack *stack, int flag)
{
	t_lst *a;
	t_lst *b;

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
	t_lst *a;
	t_lst *b;

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
	ft_putstr_fd("ss\n", 1);
}
