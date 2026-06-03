#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include "./libftprintf/ft_printf_bonus.h"

/*
 * t_stack - node structure for push_swap (Turkish algorithm)
 *
 * value      : actual integer value of the node (never modified)
 * idx        : current position index of the node inside its stack (dynamic)
 * target     : index/value of the best insertion position in the opposite stack
 *
 * cost_a     : number of operations required to bring this node to the top of stack A
 * cost_b     : number of operations required to bring the target node to the top of stack B
 *
 * is_cheap   : flag marking the node with the lowest combined cost in the current iteration
 *
 * prev/next  : doubly linked list pointers for stack navigation
 */

typedef struct l_stack
{
	int				value;
	int				idx;
	int				target;
	int				cost_a;
	int				cost_b;
	int				is_cheap;
	struct l_stack	*prev;
	struct l_stack	*next;
}	t_stack;

typedef struct s_algo
{
	int simple;
	int medium;
	int complex;
	int adaptive;
	int bench;
}	t_algo;

typedef struct	s_data_bench
{
	int		total_ops;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;		
}	t_data_bench;

void	handle_error(t_stack **l_stack_a, t_stack **l_stack_b);

int		have_duplicate(t_stack *begin_list);
int		atoi_check(char *str, int *flag_err);

void	bench_writer(t_data_bench *data_bench, t_algo *algo_config, float f);
void	bench_writer_row4(t_data_bench *data_bench, t_algo *algo_config, float f);
void	bench_writer_row5(t_data_bench *data_bench, t_algo *algo_config, float f);


t_algo	*init_flag();
int	insert_in_algo(t_algo *check_algo, char *s1, char *s2);
int	check_flag(char	*flag_to_check, t_algo *check_algo);
void	print_algo(t_algo *check_algo);

t_stack	*new_node(int value);
int		list_push_back(t_stack **begin_list, int value);
void	list_clear(t_stack **node);
int		list_size(t_stack *begin);
t_stack	*init_list(char **argv, int *flag_err);
t_stack	*argv_to_list(char **argv, int *flag_err);
t_stack	*list_last(t_stack *begin);
void	print_list(t_stack *begin, char *label);

void	sort_three(t_stack **l_stack);
void	sort_five(t_stack **l_stack_a, t_stack **l_stack_b);
void	sort_big(t_stack **l_stack_a, t_stack **l_stack_b);
void	sort_max_min_extraction(t_stack **l_stack_a, t_stack **l_stack_b);
void	sort_stack(t_stack **l_stack_a);

float	compute_disorder(t_stack *a);
void	print_disorder(float f);
int		is_sorted(t_stack *l_stack);
int		get_pos_idx_max(t_stack *l_stack, int target_to_ignore);
int		get_pos_idx_min(t_stack *l_stack);
void	push_min_to_b(t_stack **l_stack_a, t_stack **l_stack_b);
void	push_back_to_a(t_stack **l_stack_a, t_stack **l_stack_b);
int		smart_choice(int pos_first_max, int pos_sec_max, int size);
void	bring_to_top_b(t_stack **l_stack, int target_pos);
void	push_smart_to_a(t_stack **l_stack_a, t_stack **l_stack_b);

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
