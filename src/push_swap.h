#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

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

t_lst	*allocate_node(int value);
void	ft_error(char *txt, t_lst *head);
int		ft_myatoi(char *str, t_lst *lst, char ***split);
t_lst	*parse_input(int argc, char **argv);
int		contain_duplicates(t_lst *list);
void	free_list(t_lst *head);
int		list_size(t_lst *head);
int		is_empty(t_stack *stack);
void	assign_indexes(t_lst *head);
int		max_index(t_stack *stack, int i);

void	sa(t_stack *stack, int flag);
void	sb(t_stack *stack, int flag);
void	ss(t_stack *s1, t_stack *s2);

void	ra(t_stack *stack, int flag);
void	rb(t_stack *stack, int flag);
void	rr(t_stack *s1, t_stack *s2);

void	rra(t_stack *stack, int flag);
void	rrb(t_stack *stack, int flag);
void	rrr(t_stack *s1, t_stack *s2);

void	pa(t_stack *a, t_stack *b, int flag);
void	pb(t_stack *a, t_stack *b, int flag);

int		max_index(t_stack *stack, int i);
void	butterfly(t_stack *a, t_stack *b);

void	sort_2pairs(t_stack *a);
void	sort_3pairs(t_stack *a);
void	sort_4pairs(t_stack *a, t_stack *b);
void	sort_5pairs(t_stack *a, t_stack *b);

void	free_2d(char **arr);
void	is_sorted(t_lst *list);
int		check_only_space(char *str);

#endif
