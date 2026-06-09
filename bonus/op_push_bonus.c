/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecelli <gpecelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:57:49 by gipimpin          #+#    #+#             */
/*   Updated: 2026/06/08 17:01:49 by gpecelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*
** Transfers the top node of 'l_stack_take' to the top of 'l_stack_push'.
** Handles updating the 'next' and 'prev' pointers to maintain
** the integrity of the doubly linked lists.
**
** @param l_stack_take Double pointer to the source stack.
** @param l_stack_push Double pointer to the destination stack.
*/
static void	push(t_stack **l_stack_take, t_stack **l_stack_push)
{
	t_stack	*stack_to_push;

	if (!l_stack_take || !*l_stack_take || !l_stack_push)
		return ;
	stack_to_push = *l_stack_take;
	if (stack_to_push->next)
	{
		stack_to_push->next->prev = NULL;
		*l_stack_take = stack_to_push->next;
		stack_to_push->next = NULL;
	}
	else
		*l_stack_take = NULL;
	if (!*l_stack_push)
		*l_stack_push = stack_to_push;
	else
	{
		(*l_stack_push)->prev = stack_to_push;
		stack_to_push->next = *l_stack_push;
		*l_stack_push = stack_to_push;
	}
	return ;
}

/*
** Push A: Takes the first element from B and inserts it at the top of A.
**
** @param l_stack_a Double pointer to stack A.
** @param l_stack_b Double pointer to stack B.
*/
void	pa_b(t_stack **l_stack_a, t_stack **l_stack_b)
{
	push(l_stack_b, l_stack_a);
}

/*
** Push B: Takes the first element from A and inserts it at the top of B.
**
** @param l_stack_a Double pointer to stack A.
** @param l_stack_b Double pointer to stack B.
*/
void	pb_b(t_stack **l_stack_a, t_stack **l_stack_b)
{
	push(l_stack_a, l_stack_b);
}
