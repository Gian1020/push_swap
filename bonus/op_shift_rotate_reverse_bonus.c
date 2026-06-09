/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_shift_rotate_reverse_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecelli <gpecelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:57:49 by gipimpin          #+#    #+#             */
/*   Updated: 2026/06/08 17:01:05 by gpecelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*
** Downward rotation: Moves the last stack element to the first position.
** Updates 'first' and 'last' pointers to maintain doubly linked list
** circularity. Does nothing if stack has fewer than 2 elements.
**
** @param l_stack Double pointer to the stack to rotate.
*/
static void	shift_rotate_reverse(t_stack **l_stack)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*new_last;

	if (!l_stack || !*l_stack || !(*l_stack)->next)
		return ;
	first = *l_stack;
	last = list_last(*l_stack);
	new_last = last->prev;
	new_last->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*l_stack = last;
}

/*
** Reverse Rotate A: Moves the last element of A to the top.
**
** @param l_stack_a Double pointer to stack A.
*/
void	rra_b(t_stack **l_stack_a)
{
	shift_rotate_reverse(l_stack_a);
}

/*
** Reverse Rotate B: Moves the last element of B to the top.
**
** @param l_stack_b Double pointer to stack B.
*/
void	rrb_b(t_stack **l_stack_b)
{
	shift_rotate_reverse(l_stack_b);
}

/*
** Reverse Rotate r: Executes reverse rotation on both stacks simultaneously.
**
** @param l_stack_a Double pointer to stack A.
** @param l_stack_b Double pointer to stack B.
*/
void	rrr_b(t_stack **l_stack_a, t_stack **l_stack_b)
{
	if (!*l_stack_a || !*l_stack_b
		|| !(*l_stack_a)->next || !(*l_stack_b)->next)
		return ;
	shift_rotate_reverse(l_stack_a);
	shift_rotate_reverse(l_stack_b);
}
