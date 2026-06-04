/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecelli <gpecelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 10:49:30 by gpecelli          #+#    #+#             */
/*   Updated: 2026/06/04 17:09:02 by gpecelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_max(t_stack *l_stack)
{
	t_stack	*max;

	max = l_stack;
	while (l_stack != NULL)
	{
		if (l_stack->idx > max->idx)
			max = l_stack;
		l_stack = l_stack->next;
	}
	return (max);
}

t_stack	*get_target(t_stack *l_stack_a, t_stack *l_stack_b)
{
	t_stack	*target;
	t_stack	*current_b;

	target = NULL;
	current_b = l_stack_b;
	while (current_b != NULL)
	{
		if (current_b->idx < l_stack_a->idx)
		{
			if (target == NULL || current_b->idx > target->idx)
				target = current_b;
		}
		current_b = current_b->next;
	}
	if (target == NULL)
		target = find_max(l_stack_b);
	return (target);
}

void	set_all_target(t_stack *l_stack_a, t_stack *l_stack_b)
{
	t_stack	*temp_a;

	temp_a = l_stack_a;
	while(temp_a != NULL)
	{
		temp_a->target = get_target(l_stack_a, l_stack_b);
		temp_a = temp_a->next;
	}
}