/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecelli <gpecelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:57:49 by gipimpin          #+#    #+#             */
/*   Updated: 2026/06/08 17:01:19 by gpecelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*
** Swaps the first and second elements of the stack.
** Updates 'first' and 'last' pointers to maintain doubly linked list
** circularity. Does nothing if the stack has fewer than 2 elements.
**
** @param l_stack Double pointer to the stack to modify.
*/
static void	swap(t_stack **l_stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!l_stack || !*l_stack || !(*l_stack)->next)
		return ;
	first = *l_stack;
	second = first->next;
	if (second->next)
		second->next->prev = first;
	first->prev = second;
	first->next = second->next;
	second->next = first;
	second->prev = NULL;
	*l_stack = second;
}

/*
** Swap A: Swaps the first and second elements of stack A.
**
** @param l_stack_a Double pointer to stack A.
*/
void	sa_b(t_stack **l_stack_a)
{
	swap(l_stack_a);
}

/*
** Swap B: Swaps the first and second elements of stack B.
**
** @param l_stack_b Double pointer to stack B.
*/
void	sb_b(t_stack **l_stack_b)
{
	swap(l_stack_b);
}

/*
** Simultaneous swap of both stack A and stack B.
**
** @param l_stack_a Double pointer to stack A.
** @param l_stack_b Double pointer to stack B.
*/
void	ss_b(t_stack **l_stack_a, t_stack **l_stack_b)
{
	if (!*l_stack_a || !*l_stack_b
		|| !(*l_stack_a)->next || !(*l_stack_b)->next)
		return ;
	swap(l_stack_a);
	swap(l_stack_b);
	return ;
}
