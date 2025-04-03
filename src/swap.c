#include "push_swap.h"

t_lst *reverseList(t_lst *head)
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

void sa(t_stack *stack)
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
	ft_putstr_fd("sa\n", 1);
}

void sb(t_stack *stack)
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
	ft_putstr_fd("sb\n", 1);
}
