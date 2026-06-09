/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:17:23 by marvin            #+#    #+#             */
/*   Updated: 2026/06/07 19:57:53 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Finds and returns the node with the minimum index value in the stack.
** Iterates through the given stack to locate the smallest element.
**
** @param l_stack A pointer to the first node of the stack to evaluate.
** @return A pointer to the node with the minimum index, or NULL if empty.
*/
t_stack	*find_min(t_stack *l_stack)
{
	t_stack	*min;

	if (!l_stack)
		return (NULL);
	min = l_stack;
	while (l_stack != NULL)
	{
		if (l_stack->idx < min->idx)
			min = l_stack;
		l_stack = l_stack->next;
	}
	return (min);
}

/*
** Finds and returns the node with the maximum index value in the stack.
** Iterates through the given stack to locate the largest element.
**
** @param l_stack A pointer to the first node of the stack to evaluate.
** @return A pointer to the node with the maximum index, or NULL if empty.
*/
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

/*
** Returns the current position of the node with the smallest value.
** Scans the stack to find the minimum index and returns its position.
**
** @param l_stack Pointer to the first node of the stack.
** @return The position (integer) of the smallest node, or -1 if empty.
*/
int	get_pos_idx_min(t_stack *l_stack)
{
	int	i;
	int	idx_stack_min;
	int	idx_value_min;

	if (!l_stack)
		return (-1);
	i = 0;
	idx_stack_min = 0;
	idx_value_min = l_stack->idx;
	while (l_stack != NULL)
	{
		if (l_stack->idx < idx_value_min)
		{
			idx_value_min = l_stack->idx;
			idx_stack_min = i;
		}
		i++;
		l_stack = l_stack->next;
	}
	return (idx_stack_min);
}

/*
** Returns the current position of the node with the largest value,
** ignoring the specified target value.
**
** @param l_stack Pointer to the first node of the stack.
** @param target_to_ignore The value to bypass during the search.
** @return The position (integer) of the largest node, or -1 if empty.
*/
int	get_pos_idx_max(t_stack *l_stack, int target_to_ignore)
{
	int	i;
	int	idx_stack_max;
	int	idx_value_max;

	if (!l_stack)
		return (-1);
	i = 0;
	idx_stack_max = 0;
	idx_value_max = -1;
	while (l_stack != NULL)
	{
		if (l_stack->idx != target_to_ignore && l_stack->idx > idx_value_max)
		{
			idx_value_max = l_stack->idx;
			idx_stack_max = i;
		}
		i++;
		l_stack = l_stack->next;
	}
	return (idx_stack_max);
}
