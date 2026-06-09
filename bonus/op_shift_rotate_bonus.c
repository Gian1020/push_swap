/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_shift_rotate_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecelli <gpecelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:57:54 by gipimpin          #+#    #+#             */
/*   Updated: 2026/06/08 17:10:09 by gpecelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*
** Upward rotation: Moves the first stack element to the last position.
** Updates 'first' and 'last' pointers to maintain doubly linked list
** circularity. Does nothing if stack has fewer than 2 elements.
**
** @param l_stack Double pointer to the stack to rotate.
*/
static void	shift_rotate(t_stack **l_stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!l_stack || !*l_stack || !(*l_stack)->next)
		return ;
	first = *l_stack;
	last = list_last(*l_stack);
	*l_stack = first->next;
	first->next->prev = NULL;
	first->prev = last;
	first->next = NULL;
	last->next = first;
}

/*
** Rotate A: Takes the first element of A and moves it to the last position.
**
** @param l_stack_a Double pointer to stack A.
*/
void	ra_b(t_stack **l_stack_a)
{
	shift_rotate(l_stack_a);
}

/*
** Rotate B: Takes the first element of B and moves it to the last position.
**
** @param l_stack_b Double pointer to stack B.
*/
void	rb_b(t_stack **l_stack_b)
{
	shift_rotate(l_stack_b);
}

/*
** Rotates both stack A and stack B simultaneously.
**
** @param l_stack_a Double pointer to stack A.
** @param l_stack_b Double pointer to stack B.
*/
void	rr_b(t_stack **l_stack_a, t_stack **l_stack_b)
{
	if (!*l_stack_a || !*l_stack_b
		|| !(*l_stack_a)->next || !(*l_stack_b)->next)
		return ;
	shift_rotate(l_stack_a);
	shift_rotate(l_stack_b);
}
