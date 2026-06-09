/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max_min_extraction.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecelli <gpecelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:39:47 by gpecelli          #+#    #+#             */
/*   Updated: 2026/06/07 19:57:50 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Pushes all elements from stack B back to stack A.
** Iterates until stack B is completely empty.
**
** @param l_stack_a Double pointer to the destination stack A.
** @param l_stack_b Double pointer to the source stack B.
** @param data Pointer to benchmark tracking.
*/
void	push_back_to_a(t_stack **l_stack_a, t_stack **l_stack_b,
			t_data_bench *data)
{
	if (!l_stack_b || !*l_stack_b)
		return ;
	while (*l_stack_b != NULL)
		pa(l_stack_a, l_stack_b, data);
}

/*
** Iteratively pushes the minimum value of A to B, then pushes everything
** back to A to achieve a fully sorted stack.
** This functions acts as a very basic Selection Sort algorithm variant.
**
** @param l_stack_a Double pointer to stack A to sort.
** @param l_stack_b Double pointer to stack B used as a buffer.
** @param data Pointer to benchmark struct to record the actions taken.
*/
void	sort_max_min_extraction(t_stack **l_stack_a, t_stack **l_stack_b,
			t_data_bench *data)
{
	if (*l_stack_b != NULL)
		list_clear(l_stack_b);
	while (*l_stack_a != NULL)
		push_min_to_b(l_stack_a, l_stack_b, data);
	push_back_to_a(l_stack_a, l_stack_b, data);
}
