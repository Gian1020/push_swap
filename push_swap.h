#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "/libft/libft.h"
# include "/libftprintf/libftprintf.h"

typedef struct	l_stack
{
	int	value;
	int	idx;
	struct l_stack	*prev;
	struct l_stack	*next;
}	t_stack;

void	handle_error(t_stack **l_stack_a, t_stack **l_stack_b);

int		have_duplicate(t_stack *begin_list);
int		atoi_check(char *str, int *flag_err);

t_stack	*new_node(int value);
int		list_push_back(t_stack **begin_list, int value);
void	list_clear(t_stack **node);
int		list_size(t_stack *begin);
t_stack	*init_list(char **argv, int *flag_err);
t_stack *list_last(t_stack *begin);
//void	print_list(t_stack *begin, char *label);

void	sort_three(t_stack **l_stack);
void	sort_five(t_stack **l_stack_a, t_stack **l_stack_b);
void	sort_big(t_stack **l_stack_a, t_stack **l_stack_b);
void	sort_stack(t_stack **l_stack_a);

int		is_sorted(t_stack *l_stack);
int		get_pos_idx_max(t_stack *l_stack, int target_to_ignore);
int		get_pos_idx_min(t_stack *l_stack);
void	push_min_to_b(t_stack **l_stack_a, t_stack **l_stack_b);
void	push_back_to_a(t_stack **l_stack_a, t_stack **l_stack_b);
int		smart_choice(int pos_first_max, int pos_sec_max, int size);
void	bring_to_top_b(t_stack **l_stack, int target_pos);
void	push_smart_to_a(t_stack **l_stack_a,t_stack **l_stack_b);

int		sa(t_stack **l_stack_a);
int		sb(t_stack **l_stack_b);
int		ss(t_stack **l_stack_a, t_stack **l_stack_b);

int		pa(t_stack **l_stack_a, t_stack **l_stack_b);
int		pb(t_stack **l_stack_a, t_stack **l_stack_b);

int		ra(t_stack **l_stack_a);
int		rb(t_stack **l_stack_b);
int		rr(t_stack **l_stack_a, t_stack **l_stack_b);

int		rra(t_stack **l_stack_a);
int		rrb(t_stack **l_stack_b);
int		rrr(t_stack **l_stack_a, t_stack **l_stack_b);
#endif
