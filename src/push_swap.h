#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_lst
{
	int				data;
	int				index;
	struct s_lst	*next;
}	t_lst;

typedef struct s_stack
{
	t_lst	*lst;
}	t_stack;

t_lst	*reverseList(t_lst *head);
t_lst	*allocate_node(int value);
void	ft_error(char *txt, t_lst *head);
int		ft_myatoi(char *str, t_lst *lst);
int		contain_duplicates(t_lst *list);
void	free_list(t_lst *head);
int		list_size(t_lst *head);
int		is_empty(t_stack *stack);

void	sa(t_stack *stack, int flag);
void	sb(t_stack *stack, int flag);
void	ss(t_stack *s1, t_stack *s2);

void	ra(t_stack *stack, int flag);
void	rb(t_stack *stack, int flag);
void	rr(t_stack *s1, t_stack *s2);
void	rra(t_stack *stack, int flag);

void pa(t_stack *a, t_stack *b, int flag);
void pb(t_stack *a, t_stack *b, int flag);


void print_stack(const char *name, t_lst *lst);


#endif
