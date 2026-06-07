/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:30:51 by marvin            #+#    #+#             */
/*   Updated: 2026/06/07 19:58:49 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	set_calculate_total_cost(t_stack *node_in_a)
{
	int	abs_a;
	int	abs_b;

	if ((node_in_a->cost_a > 0 && node_in_a->cost_b > 0)
		|| (node_in_a->cost_a < 0 && node_in_a->cost_b < 0))
	{
		abs_a = ft_abs(node_in_a->cost_a);
		abs_b = ft_abs(node_in_a->cost_b);
		if (abs_a > abs_b)
			node_in_a->total_cost = abs_a;
		else
			node_in_a->total_cost = abs_b;
	}
	else
	{
		abs_a = ft_abs(node_in_a->cost_a);
		abs_b = ft_abs(node_in_a->cost_b);
		node_in_a->total_cost = abs_a + abs_b;
	}
}

static void	enter_cost_a(t_stack *node, int len)
{
	if (node->curr_pos <= len / 2)
		node->cost_a = node->curr_pos;
	else
		node->cost_a = -(len - node->curr_pos);
}

static void	enter_cost_b(t_stack *node, int len, t_stack *target)
{
	if (target->curr_pos <= len / 2)
		node->cost_b = target->curr_pos;
	else
		node->cost_b = -(len - target->curr_pos);
}

void	calculate_cost(t_stack *l_stack_a, t_stack *l_stack_b)
{
	int		len_a;
	int		len_b;
	t_stack	*node_in_a;
	t_stack	*target_node;

	len_a = list_size(l_stack_a);
	len_b = list_size(l_stack_b);
	node_in_a = l_stack_a;
	while (node_in_a != NULL)
	{
		enter_cost_a(node_in_a, len_a);
		target_node = node_in_a->target;
		if (!target_node)
		{
			node_in_a->cost_b = 0;
			node_in_a->total_cost = INT_MAX;
			node_in_a = node_in_a->next;
			continue ;
		}
		enter_cost_b(node_in_a, len_b, target_node);
		set_calculate_total_cost(node_in_a);
		node_in_a = node_in_a->next;
	}
}
