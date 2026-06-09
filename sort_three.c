/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:05:32 by marvin            #+#    #+#             */
/*   Updated: 2026/06/07 19:57:55 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Sorts a stack of 3 elements in a maximum of 2 moves.
** Identifies the highest value to move to the bottom, then handles the rest.
**
** @param l_stack Double pointer to the stack to be sorted.
** @param data Pointer to the benchmark tracking struct.
*/
void	sort_three(t_stack **l_stack, t_data_bench *data)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*c;

	if (!l_stack || list_size(*l_stack) != 3)
		return ;
	a = *l_stack;
	b = a->next;
	c = b->next;
	if (a->idx > b->idx && b->idx < c->idx && a->idx < c->idx)
		sa(l_stack, data);
	else if (a->idx > b->idx && b->idx > c->idx)
	{
		sa(l_stack, data);
		rra(l_stack, data);
	}
	else if (a->idx > b->idx && b->idx < c->idx && a->idx > c->idx)
		ra(l_stack, data);
	else if (a->idx < b->idx && b->idx > c->idx && a->idx < c->idx)
	{
		sa(l_stack, data);
		ra(l_stack, data);
	}
	else if (a->idx < b->idx && b->idx > c->idx && a->idx > c->idx)
		rra(l_stack, data);
}
