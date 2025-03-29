#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_lst
{
	int				data;
	struct s_lst	*next;
}	t_lst;

typedef struct s_stack
{
	t_lst	lst;
}	t_stack;

t_lst	*reverseList(t_lst *head);
t_lst	*allocate_node(int value);
void	ft_error(char *txt, t_lst *head);
int		ft_myatoi(char *str, t_lst *lst);
int		contain_duplicates(t_lst *list);
void	free_list(t_lst *head);
int		list_size(t_lst *head);
int		is_empty(t_lst *stack);
void	sa(t_lst *stack);


#endif
