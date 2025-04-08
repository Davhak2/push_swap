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

void pa(t_stack *a, t_stack *b, int flag)
{
	if (!b->lst)
		return;
	t_lst *tmp = b->lst;
	b->lst = b->lst->next;
	tmp->next = a->lst;
	a->lst = tmp;
	if (flag)
		printf("pa\n");
}

void pb(t_stack *a, t_stack *b, int flag)
{
	if (!a->lst)
		return;
	t_lst *tmp = a->lst;
	a->lst = a->lst->next;
	tmp->next = b->lst;
	b->lst = tmp;
	if (flag)
		printf("pb\n");
}
