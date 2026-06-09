/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:44:37 by marvin            #+#    #+#             */
/*   Updated: 2026/06/07 19:58:49 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
** Executes individual rotations for stack A when no combo moves are possible.
**
** @param l_stack_a Double pointer to stack A.
** @param node_cheap Pointer to the node flagged as the cheapest.
** @param data Pointer to benchmark tracking structure.
*/
void	no_combo_move_cost_a(t_stack **l_stack_a,
			t_stack *node_cheap, t_data_bench *data)
{
	if (node_cheap->cost_a > 0)
	{
		while (node_cheap->cost_a > 0)
		{
			ra(l_stack_a, data);
			node_cheap->cost_a--;
		}
	}
	else if (node_cheap->cost_a < 0)
	{
		while (node_cheap->cost_a < 0)
		{
			rra(l_stack_a, data);
			node_cheap->cost_a++;
		}
	}
}

/*
** Executes individual rotations for stack B when no combo moves are possible.
**
** @param l_stack_b Double pointer to stack B.
** @param node_cheap Pointer to the node flagged as the cheapest.
** @param data Pointer to benchmark tracking structure.
*/
void	no_combo_move_cost_b(t_stack **l_stack_b,
			t_stack *node_cheap, t_data_bench *data)
{
	if (node_cheap->cost_b > 0)
	{
		while (node_cheap->cost_b > 0)
		{
			rb(l_stack_b, data);
			node_cheap->cost_b--;
		}
	}
	else if (node_cheap->cost_b < 0)
	{
		while (node_cheap->cost_b < 0)
		{
			rrb(l_stack_b, data);
			node_cheap->cost_b++;
		}
	}
}

/*
** Applies optimal combo rotations first, then individual rotations,
** and finally pushes the cheapest node from A to B.
**
** @param l_stack_a Double pointer to stack A.
** @param l_stack_b Double pointer to stack B.
** @param node_cheap Pointer to the cheapest node to push.
** @param data Pointer to benchmark tracking structure.
*/
void	move_cheap_head_a(t_stack **l_stack_a, t_stack **l_stack_b,
			t_stack *node_cheap, t_data_bench *data)
{
	if (node_cheap->cost_a > 0 && node_cheap->cost_b > 0)
	{
		while (node_cheap->cost_a > 0 && node_cheap->cost_b > 0)
		{
			rr(l_stack_a, l_stack_b, data);
			node_cheap->cost_a--;
			node_cheap->cost_b--;
		}
	}
	else if (node_cheap->cost_a < 0 && node_cheap->cost_b < 0)
	{
		while (node_cheap->cost_a < 0 && node_cheap->cost_b < 0)
		{
			rrr(l_stack_a, l_stack_b, data);
			node_cheap->cost_a++;
			node_cheap->cost_b++;
		}
	}
	no_combo_move_cost_a(l_stack_a, node_cheap, data);
	no_combo_move_cost_b(l_stack_b, node_cheap, data);
	pb(l_stack_a, l_stack_b, data);
}
