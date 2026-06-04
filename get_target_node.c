/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecelli <gpecelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 10:49:30 by gpecelli          #+#    #+#             */
/*   Updated: 2026/06/04 17:06:31 by gpecelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_max(t_stack *l_stack)
{
	t_stack	*max;

	max = l_stack;
	while (l_stack != NULL)
	{
		if (l_stack->next->idx > max->idx)
			max = l_stack->next;
		l_stack = l_stack->next;
	}
	return (max);
}

int	get_target(t_stack *l_stack_a, t_stack *l_stack_b)
{
	t_stack *node_max_b;
	t_stack	*target;
	t_stack	*current_b;

	target->idx = -1;
	while (current_b != NULL)
	{
		if (l_stack_a->idx < current_b->idx 
				&& (target->idx == NULL || current_b->idx > target->idx))
			target->idx = current_b;
		current_b = current_b->next;
	}
	node_max_b = find_max(l_stack_b);
	if (target->idx == NULL && get_pos_idx_max(node_max_b, -1) == 0) 
		target->idx = node_max_b->idx;

	// TODO aggiungere il caso non troviamo il massim
	return (target->idx);
}
