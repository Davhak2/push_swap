#include "checker.h"

void	free_2d(char **arr)
{
	int	i;

	if (!arr && !*arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	is_sorted(t_lst *list)
{
	t_lst	*tmp;
	t_lst	*curr;

	tmp = list->next;
	curr = list;
	while (tmp)
	{
		if (curr->data > tmp->data)
			return ;
		tmp = tmp->next;
		curr = curr->next;
	}
	if (list)
		free_list(list);
	exit(EXIT_SUCCESS);
}

int	contain_duplicates(t_lst *list)
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

int	check_only_space(char *str)
{
	while (*str)
	{
		if (*str != ' ')
			return (false);
		str++;
	}
	return (true);
}

void	ft_error(char *txt, t_lst *head)
{
	if (head)
		free_list(head);
	ft_putstr_fd(txt, 2);
	exit(EXIT_FAILURE);
}
