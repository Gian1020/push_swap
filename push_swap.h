#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include "./libftprintf/ft_printf_bonus.h"

typedef struct l_stack
{
	int				value;
	int				idx;
	int				curr_pos;
	int				target;
	int				cost_a;
	int				cost_b;
	int				is_cheap;
	struct l_stack	*prev;
	struct l_stack	*next;
}	t_stack;

typedef struct s_algo
{
	int		simple;
	int		medium;
	int		complex;
	int		adaptive;
	int		bench;
}	t_algo;

typedef struct s_data_bench
{
	int		total;
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

void			handle_error(t_stack **l_stack_a, t_stack **l_stack_b);

int				have_duplicate(t_stack *begin_list);
int				atoi_check(char *str, int *flag_err);

t_data_bench	*init_data_bench(void);
void			bench_writer(t_data_bench *data_bench);
void			bench_writer_row4(t_data_bench *data_bench);
void			bench_writer_row5(t_data_bench *data_bench);

t_algo			*init_struct_algo(void);
int				insert_in_algo(t_algo *check_algo, char *s1, char *s2);
int				check_flag(char	*flag_to_check, t_algo *check_algo);
void			print_algo(t_algo *check_algo);

t_stack			*new_node(int value);
int				list_push_back(t_stack **begin_list, int value);
void			list_clear(t_stack **node);
int				list_size(t_stack *begin);
t_stack			*init_list(char **argv, int *flag_err);
t_stack			*argv_to_list(char **argv, int *flag_err);
t_stack			*list_last(t_stack *begin);
void			print_list(t_stack *begin, char *label);

void			sort_two(t_stack **l_stack, t_data_bench *data);
void			sort_three(t_stack **l_stack, t_data_bench *data);
void			sort_five(t_stack **l_stack_a, t_stack **l_stack_b, t_data_bench *data);
void			sort_big(t_stack **l_stack_a, t_stack **l_stack_b,  t_data_bench *data);
void			sort_max_min_extraction(t_stack **l_stack_a,
					t_stack **l_stack_b);
void			sort_stack(t_stack **l_stack_a, t_data_bench *data);

float			compute_disorder(t_stack *a);
void			print_disorder(float f);
int				is_sorted(t_stack *l_stack);
int				get_pos_idx_max(t_stack *l_stack, int target_to_ignore);
int				get_pos_idx_min(t_stack *l_stack);
void			push_min_to_b(t_stack **l_stack_a, t_stack **l_stack_b,
					t_data_bench *data);
void			push_back_to_a(t_stack **l_stack_a, t_stack **l_stack_b,
					t_data_bench *data);
int				smart_choice(int pos_first_max, int pos_sec_max, int size);
void			bring_to_top_b(t_stack **l_stack, int target_pos,
					t_data_bench *data);
void			push_smart_to_a(t_stack **l_stack_a, t_stack **l_stack_b,
					t_data_bench *data);

int				sa(t_stack **l_stack_a, t_data_bench *data);
int				sb(t_stack **l_stack_b, t_data_bench *data);
int				ss(t_stack **l_stack_a, t_stack **l_stack_b,
					t_data_bench *data);

int				pa(t_stack **l_stack_a, t_stack **l_stack_b,
					t_data_bench *data);
int				pb(t_stack **l_stack_a, t_stack **l_stack_b,
					t_data_bench *data);

int				ra(t_stack **l_stack_a, t_data_bench *data);
int				rb(t_stack **l_stack_b, t_data_bench *data);
int				rr(t_stack **l_stack_a, t_stack **l_stack_b,
					t_data_bench *data);

int				rra(t_stack **l_stack_a, t_data_bench *data);
int				rrb(t_stack **l_stack_b, t_data_bench *data);
int				rrr(t_stack **l_stack_a, t_stack **l_stack_b,
					t_data_bench *data);
#endif
