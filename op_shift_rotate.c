/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_shift_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:57:54 by gipimpin          #+#    #+#             */
/*   Updated: 2026/06/07 19:57:54 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Upward rotation: Moves the first stack element to the last position.
** Updates 'first' and 'last' pointers to maintain doubly linked list
** circularity and prints the operation if 'op_name' is provided.
**
** @param l_stack Double pointer to the stack to rotate.
** @param op_name String literal of the operation name to print (e.g. "ra").
** @return 1 on success, 0 if the stack has fewer than 2 elements.
*/
static int	shift_rotate(t_stack **l_stack, char *op_name)
{
	t_stack	*first;
	t_stack	*last;

	if (!l_stack || !*l_stack || !(*l_stack)->next)
		return (0);
	first = *l_stack;
	last = list_last(*l_stack);
	*l_stack = first->next;
	first->next->prev = NULL;
	first->prev = last;
	first->next = NULL;
	last->next = first;
	if (op_name)
	{
		write(1, op_name, 2);
		write(1, "\n", 1);
	}
	return (1);
}

/*
** Rotate A: Takes the first element of A and moves it to the last position.
** Prints "ra\n" to the terminal on success.
**
** @param l_stack_a Double pointer to stack A.
** @param data Pointer to benchmark data to increment instruction counts.
*/
void	ra(t_stack **l_stack_a, t_data_bench *data)
{
	int	r;

	r = shift_rotate(l_stack_a, "ra");
	if (r && data)
	{
		data->total += 1;
		data->ra += 1;
	}
}

/*
** Rotate B: Takes the first element of B and moves it to the last position.
** Prints "rb\n" to the terminal on success.
**
** @param l_stack_b Double pointer to stack B.
** @param data Pointer to benchmark data to increment instruction counts.
*/
void	rb(t_stack **l_stack_b, t_data_bench *data)
{
	int	r;

	r = shift_rotate(l_stack_b, "rb");
	if (r && data)
	{
		data->total += 1;
		data->rb += 1;
	}
}

/*
** Rotates both stack A and stack B simultaneously.
** Prints "rr\n" to the terminal if both succeed.
**
** @param l_stack_a Double pointer to stack A.
** @param l_stack_b Double pointer to stack B.
** @param data Pointer to benchmark data to increment instruction counts.
*/
void	rr(t_stack **l_stack_a, t_stack **l_stack_b, t_data_bench *data)
{
	if (!*l_stack_a || !*l_stack_b
		|| !(*l_stack_a)->next || !(*l_stack_b)->next)
		return ;
	shift_rotate(l_stack_a, NULL);
	shift_rotate(l_stack_b, NULL);
	write(1, "rr\n", 3);
	if (data)
	{
		data->total += 1;
		data->rr += 1;
	}
}
