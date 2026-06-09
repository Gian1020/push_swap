/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecelli <gpecelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 19:33:29 by marvin            #+#    #+#             */
/*   Updated: 2026/06/08 11:11:38 by gpecelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Sorts the stack based on its size, picking the correct specific sort.
** Evaluates simple base cases (2, 3, or up to 5 elements).
**
** @param l_stack_a Double pointer to stack A.
** @param l_stack_b Double pointer to stack B.
** @param size Integer representing the number of elements in A.
** @param data Pointer to benchmark tracking.
*/
void	sort_by_size(t_stack **l_stack_a, t_stack **l_stack_b,
		int size, t_data_bench *data)
{
	if (!l_stack_a || size < 2 || is_sorted(*l_stack_a))
		return ;
	if (size == 2)
		sa(l_stack_a, data);
	else if (size == 3)
		sort_three(l_stack_a, data);
	else if (size <= 5)
		sort_five(l_stack_a, l_stack_b, data);
	list_clear(l_stack_b);
}

/*
** Chooses an adaptive sorting strategy based on stack size and disorder.
** Switches between basic extraction, chunk sort, and Turk algorithm.
**
** @param l_stack_a Double pointer to stack A.
** @param l_stack_b Double pointer to stack B.
** @param data Pointer to benchmark data containing the disorder ratio.
** @param size Integer representing the number of elements in A.
*/
static void	sort_by_adaptive(t_stack **l_stack_a, t_stack **l_stack_b,
			t_data_bench *data, int size)
{
	if (data->disorder < 0.2 && size < 150)
		sort_max_min_extraction(l_stack_a, l_stack_b, data);
	else if (data->disorder >= 0.2 && data->disorder < 0.5)
		chunk_sort(l_stack_a, l_stack_b, data);
	else
		turk_sort(l_stack_a, l_stack_b, data);
}

/*
** Coordinates the sorting strategy based on element count and flags.
** Checks if the stack is already sorted or small, then delegates
** execution to specialized algorithms for various edge cases.
**
** @param l_stack_a Double pointer to stack A to sort.
** @param algo Pointer to the algorithm settings struct defining the strategy.
*/
void	sort_stack(t_stack **l_stack_a, t_algo *algo)
{
	t_data_bench	*data;
	t_stack			*l_stack_b;
	int				size;

	l_stack_b = NULL;
	size = list_size(*l_stack_a);
	data = init_bench(compute_disorder(*l_stack_a));
	if (size <= 5)
		sort_by_size(l_stack_a, &l_stack_b, size, data);
	else if (algo->simple == 1 && size > 5)
		sort_max_min_extraction(l_stack_a, &l_stack_b, data);
	else if (algo->medium == 1 && size > 5)
		chunk_sort(l_stack_a, &l_stack_b, data);
	else if (algo->complex == 1 && size > 5)
		turk_sort(l_stack_a, &l_stack_b, data);
	else
		sort_by_adaptive(l_stack_a, &l_stack_b, data, size);
	if (algo->bench == 1)
		bench_writer(data, algo);
	finish_prog(l_stack_a, &l_stack_b, data, algo);
}
