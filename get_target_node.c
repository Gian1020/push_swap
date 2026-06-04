/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecelli <gpecelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 10:49:30 by gpecelli          #+#    #+#             */
/*   Updated: 2026/06/04 11:17:22 by gpecelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_target_node(t_stack *l_stack_a, t_stack *l_stack_b)
{
	t_stack	*head_of_a;
	t_stack	*target_node;
	t_stack	*current_b;

	target_node = NULL;
	head_of_a = l_stack_a;
	current_b = l_stack_b;
	while (current_b != NULL)
	{
		if (head_of_a->idx > current_b->idx 
				&& (target_node == NULL || current_b->idx > target_node->idx))
			target_node = current_b;
		current_b = current_b->next;
	}

	// TODO maybe request a control - if target remain NULL

	return (target_node);
}