/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecelli <gpecelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 18:54:49 by marvin            #+#    #+#             */
/*   Updated: 2026/06/08 14:08:56 by gpecelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_pos_max
{
	int	pos_max;
	int	pos_max_1;
}	t_pos_max;

typedef struct s_i_range
{
	int	i;
	int	range;
}	t_i_range;

typedef struct l_stack
{
	int				value;
	int				idx;
	int				curr_pos;
	int				cost_a;
	int				cost_b;
	int				total_cost;
	int				is_cheap;
	struct l_stack	*prev;
	struct l_stack	*next;
	struct l_stack	*target;
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
	float	disorder;
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

void			check_flag(int argc, char **argv, t_algo *algo, int *flag_err);
int				find_start_idx(char **argv, t_algo *algo);

void			handle_error(t_stack **l_stack_a, t_stack **l_stack_b,
					t_algo *algo);
void			finish_prog(t_stack **l_stack_a, t_stack **l_stack_b,
					t_data_bench *data, t_algo *algo);

int				have_duplicate(t_stack *begin_list);
int				atoi_check(char *str, int *flag_err);

void			free_mtrx(char **mtrx);
void			fill_stack(t_stack **first, char **temp_split, int *flag_err);
t_stack			*argv_to_list(char **argv, int *flag_err);
void			fast_sort(t_stack *begin_list);

t_stack			*new_node(int value);
int				list_push_back(t_stack **begin_list, int value);
void			list_clear(t_stack **node);
int				list_size(t_stack *begin);
t_stack			*init_list(char **argv, int *flag_err);
t_stack			*list_last(t_stack *begin);

void			sort_three(t_stack **l_stack, t_data_bench *data);
void			sort_five(t_stack **l_stack_a, t_stack **l_stack_b,
					t_data_bench *data);
void			chunk_sort(t_stack **l_stack_a, t_stack **l_stack_b,
					t_data_bench *data);
void			sort_stack(t_stack **l_stack_a, t_algo *algo);

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
void			bring_target_to_top_a(t_stack **l_stack_a, t_stack *target,
					t_data_bench *data);
void			push_smart_to_a(t_stack **l_stack_a, t_stack **l_stack_b,
					t_data_bench *data);

void			sort_max_min_extraction(t_stack **l_stack_a,
					t_stack **l_stack_b, t_data_bench *data);

t_stack			*get_target_in_b(t_stack *l_stack_a, t_stack *l_stack_b);
t_stack			*get_target_in_a(t_stack *node_b, t_stack *l_stack_a);
void			set_all_target(t_stack *l_stack_a, t_stack *l_stack_b);
void			no_combo_move_cost_a(t_stack **l_stack_a, t_stack *node_cheap,
					t_data_bench *data);
void			no_combo_move_cost_b(t_stack **l_stack_b, t_stack *node_cheap,
					t_data_bench *data);
void			calculate_cost(t_stack *stack_a, t_stack *stack_b);

void			move_cheap_head_a(t_stack **l_stack_a, t_stack **l_stack_b,
					t_stack *node_cheap,
					t_data_bench *data);
void			turk_push_back(t_stack **l_stack_a, t_stack **l_stack_b,
					t_data_bench *data);
void			turk_sort(t_stack **l_stack_a, t_stack **l_stack_b,
					t_data_bench *data);
void			insert_curr_pos(t_stack *l_stack);

void			set_cheapest(t_stack *l_stack);
t_stack			*find_cheap(t_stack *l_stack);

void			sa(t_stack **l_stack_a, t_data_bench *data);
void			sb(t_stack **l_stack_b, t_data_bench *data);
void			ss(t_stack **l_stack_a, t_stack **l_stack_b,
					t_data_bench *data);

void			pa(t_stack **l_stack_a, t_stack **l_stack_b,
					t_data_bench *data);
void			pb(t_stack **l_stack_a, t_stack **l_stack_b,
					t_data_bench *data);

void			ra(t_stack **l_stack_a, t_data_bench *data);
void			rb(t_stack **l_stack_b, t_data_bench *data);
void			rr(t_stack **l_stack_a, t_stack **l_stack_b,
					t_data_bench *data);

void			rra(t_stack **l_stack_a, t_data_bench *data);
void			rrb(t_stack **l_stack_b, t_data_bench *data);
void			rrr(t_stack **l_stack_a, t_stack **l_stack_b,
					t_data_bench *data);

int				ft_abs(int n);
int				ft_sqrt(int nb);

t_stack			*find_max(t_stack *l_stack);
t_stack			*find_min(t_stack *l_stack);

t_algo			*init_algo(void);
int				algo_is_valid(t_algo *algo);
void			set_flag_algo(char *argv, t_algo *algo);
int				is_a_flag(char *s);

void			bench_writer(t_data_bench *data_bench, t_algo *algo);
float			compute_disorder(t_stack *a);
void			print_disorder(float f);

t_data_bench	*init_bench(float disorder);
t_pos_max		*init_pos_max(void);
#endif
