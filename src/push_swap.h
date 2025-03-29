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

void	ft_error(char *txt, t_lst *head);
int		ft_myatoi(char *str, t_lst *lst);
int		contain_duplicates(t_lst *list);
void	free_list(t_lst *head);

#endif
