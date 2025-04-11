#include "checker.h"

static int	atoi_helper(char *str)
{
	if (*str != '-' && *str != '+' && !ft_isdigit(*str))
		return (false);
	if (*str == 48 && *(str + 1))
		return (false);
	if ((*str == '+' || *str == '-') && *(str + 1) == 48 && \
		*(str + 2))
		return (false);
	return (true);
}

static void	exit_program(t_lst *lst, char ***split)
{
	if (split && *split)
		free_2d(*split);
	ft_error("Error\n", lst);
}

int	ft_myatoi(char *str, t_lst *lst, char ***split)
{
	int		flag;
	long	res;

	flag = 1;
	res = 0;
	if (!atoi_helper(str))
		exit_program(lst, split);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag = -1;
		str++;
		if (!*str)
			exit_program(lst, split);
	}
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - 48);
		if (res * flag > INT_MAX || res * flag < INT_MIN)
			exit_program(lst, split);
		str++;
	}
	if (*str)
		exit_program(lst, split);
	return (res * flag);
}

static t_lst	*process_split_args(char **split_args, t_lst *head)
{
	t_lst	*new;
	t_lst	*tmp;
	int		j;

	j = 0;
	while (split_args[j])
	{
		new = allocate_node(ft_myatoi(split_args[j], head, &split_args));
		if (!new)
			exit_program(head, &split_args);
		if (!head)
			head = new;
		else
		{
			tmp = head;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
		j++;
	}
	return (head);
}

t_lst	*parse_input(int argc, char **argv)
{
	t_lst	*head;
	char	**split_args;
	int		i;

	head = NULL;
	i = 0;
	while (++i < argc)
	{
		if (!argv[i][0] || check_only_space(argv[i]))
			ft_error("Error\n", head);
		split_args = ft_split(argv[i], ' ');
		if (!split_args)
			ft_error("Error\n", head);
		head = process_split_args(split_args, head);
		free_2d(split_args);
	}
	if (contain_duplicates(head))
		ft_error("Error\n", head);
	return (head);
}
