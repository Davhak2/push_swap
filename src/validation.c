#include "push_swap.h"

void	ft_error(char *txt, t_lst *head)
{
	if (head)
		free_list(head);
	ft_putstr_fd(txt, 2);
	exit(EXIT_FAILURE);
}

int	ft_myatoi(char *str, t_lst *lst)
{
	int		flag;
	long	res;

	flag = 1;
	res = 0;
	if (*str != '-' && *str != '+' && !ft_isdigit(*str))
		ft_error("Error\n", lst);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag = -1;
		str++;
		if (!*str)
			ft_error("Error\n", lst);
	}
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		if (res * flag > INT_MAX || res * flag < INT_MIN)
			ft_error("Error\n", lst);
		str++;
	}
	if (*str && !ft_isdigit(*str))
		ft_error("Error\n", lst);
	return (res * flag);
}

int contain_duplicates(t_lst *list)
{
	t_lst	*lst1;
	t_lst	*lst2;

	lst1 = list;
	while (lst1)
	{
		lst2 = lst1->next;
		while (lst2)
		{
			if (lst1->data == lst2->data)
				return (1);
			lst2 = lst2->next;
		}
		lst1 = lst1->next;
	}
	return (0);
}
