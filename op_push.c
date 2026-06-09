/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecelli <gpecelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:57:49 by gipimpin          #+#    #+#             */
/*   Updated: 2026/06/08 15:02:44 by gpecelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Transfers the top node of 'l_stack_take' to the top of 'l_stack_push'.
** Handles updating the 'next' and 'prev' pointers to maintain
** the integrity of the doubly linked lists.
**
** @param l_stack_take Double pointer to the source stack.
** @param l_stack_push Double pointer to the destination stack.
** @return 1 on success, 0 if the source stack is empty.
*/
static int	push(t_stack **l_stack_take, t_stack **l_stack_push)
{
	t_stack	*stack_to_push;

	if (!l_stack_take || !*l_stack_take || !l_stack_push)
		return (0);
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
	return (1);
}

/*
** Push A: Takes the first element from B and inserts it at the top of A.
** Prints "pa\n" to the terminal on success.
**
** @param l_stack_a Double pointer to stack A.
** @param l_stack_b Double pointer to stack B.
** @param data Pointer to benchmark data to increment instruction counts.
*/
void	pa(t_stack **l_stack_a, t_stack **l_stack_b,
		t_data_bench *data)
{
	int	flag;

	flag = push(l_stack_b, l_stack_a);
	if (flag)
		write(1, "pa\n", 3);
	if (data)
	{
		data->pa += 1;
		data->total += 1;
	}
}

/*
** Push B: Takes the first element from A and inserts it at the top of B.
** Prints "pb\n" to the terminal on success.
**
** @param l_stack_a Double pointer to stack A.
** @param l_stack_b Double pointer to stack B.
** @param data Pointer to benchmark data to increment instruction counts.
*/
void	pb(t_stack **l_stack_a, t_stack **l_stack_b,
		t_data_bench *data)
{
	int	flag;

	flag = push(l_stack_a, l_stack_b);
	if (flag)
		write(1, "pb\n", 3);
	if (data)
	{
		data->pb += 1;
		data->total += 1;
	}
}
