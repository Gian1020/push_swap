/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:44:31 by marvin            #+#    #+#             */
/*   Updated: 2026/06/07 19:58:48 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
** Iterates through the list and returns the node flagged as the cheapest.
**
** @param l_stack Pointer to the stack to search.
** @return A pointer to the cheapest node, or NULL if none is flagged.
*/
t_stack	*find_cheap(t_stack *l_stack)
{
	t_stack	*temp;

	temp = l_stack;
	while (temp != NULL)
	{
		if (temp->is_cheap)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

/*
** Finds the node with the absolute lowest total_cost and sets its is_cheap
** flag to 1, while resetting the flag to 0 for all other nodes.
**
** @param l_stack Pointer to the stack whose elements will be evaluated.
*/
void	set_cheapest(t_stack *l_stack)
{
	t_stack	*cheapest_node;
	t_stack	*current;

	if (l_stack == NULL)
		return ;
	current = l_stack;
	while (current != NULL)
	{
		current->is_cheap = 0;
		current = current->next;
	}
	cheapest_node = NULL;
	current = l_stack;
	while (current != NULL)
	{
		if (current->total_cost != INT_MAX)
		{
			if (cheapest_node == NULL
				|| current->total_cost < cheapest_node->total_cost)
				cheapest_node = current;
		}
		current = current->next;
	}
	if (cheapest_node)
		cheapest_node->is_cheap = 1;
}
