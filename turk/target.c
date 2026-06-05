/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:44:42 by marvin            #+#    #+#             */
/*   Updated: 2026/06/05 16:44:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*get_target_in_b(t_stack *l_stack_a, t_stack *l_stack_b)
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

t_stack *get_target_in_a(t_stack *node_b, t_stack *l_stack_a)
{
	t_stack *target;
	t_stack *current_a;

	target = NULL;
	current_a = l_stack_a;
	while (current_a != NULL)
	{
		if (current_a->idx > node_b->idx)
		{
			if (target == NULL || current_a->idx < target->idx)
				target = current_a;
		}
		current_a = current_a->next;
	}
	if (target == NULL)
		target = find_min(l_stack_a);
	return (target);
}

void	set_all_target(t_stack *l_stack_a, t_stack *l_stack_b)
{
	t_stack	*temp_a;

	temp_a = l_stack_a;
	while(temp_a != NULL)
	{
		temp_a->target = get_target_in_b(temp_a, l_stack_b);
			temp_a = temp_a->next;
	}
}