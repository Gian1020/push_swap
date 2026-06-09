/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:07:49 by marvin            #+#    #+#             */
/*   Updated: 2026/06/07 19:57:56 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Locates the min value in A and pushes it to B with minimum moves.
** Computes the index relative to the stack median (size/2) to choose
** direct (ra) or reverse (rra) rotations. Once the element is at
** position 0, it pushes it to B.
**
** @param l_stack_a Double pointer to stack A.
** @param l_stack_b Double pointer to stack B.
** @param data Pointer to benchmark struct for move tracking.
*/
void	push_min_to_b(t_stack **l_stack_a, t_stack **l_stack_b,
			t_data_bench *data)
{
	int	pos_min;
	int	size;

	if (!l_stack_a || !*l_stack_a)
		return ;
	pos_min = get_pos_idx_min(*l_stack_a);
	size = list_size(*l_stack_a);
	if (pos_min <= size / 2)
	{
		while (pos_min > 0)
		{
			ra(l_stack_a, data);
			pos_min--;
		}
	}
	else
	{
		while (pos_min < size)
		{
			rra(l_stack_a, data);
			pos_min++;
		}
	}
	pb(l_stack_a, l_stack_b, data);
}

/*
** Brings the target position element in B to the top with minimum moves.
** Computes the index relative to the stack median (size/2) to choose
** direct (rb) or reverse (rrb) rotations.
**
** @param l_stack Double pointer to stack B.
** @param target_pos The index position of the element to bring to top.
** @param data Pointer to benchmark struct for move tracking.
*/
void	bring_to_top_b(t_stack **l_stack, int target_pos, t_data_bench *data)
{
	int	size;

	if (!l_stack || !*l_stack)
		return ;
	size = list_size(*l_stack);
	if (target_pos <= size / 2)
	{
		while (target_pos > 0)
		{
			rb(l_stack, data);
			target_pos--;
		}
	}
	else
	{
		while (target_pos < size)
		{
			rrb(l_stack, data);
			target_pos++;
		}
	}
}

/*
** Brings a specified target node to the top of stack A using optimal moves.
** Computes whether to use 'ra' or 'rra' based on current position relative
** to the median stack size.
**
** @param l_stack_a Double pointer to stack A.
** @param target Pointer to the specific node intended to reach the top.
** @param data Pointer to benchmark struct for move tracking.
*/
void	bring_target_to_top_a(t_stack **l_stack_a,
			t_stack *target, t_data_bench *data)
{
	int	pos;
	int	size;
	int	moves;

	insert_curr_pos(*l_stack_a);
	pos = target->curr_pos;
	size = list_size(*l_stack_a);
	if (pos <= size / 2)
	{
		moves = pos;
		while (moves-- > 0)
			ra(l_stack_a, data);
	}
	else
	{
		moves = size - pos;
		while (moves-- > 0)
			rra(l_stack_a, data);
	}
}
