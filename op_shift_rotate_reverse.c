/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_shift_rotate_reverse.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:57:49 by gipimpin          #+#    #+#             */
/*   Updated: 2026/06/07 19:57:49 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Downward rotation: Moves the last stack element to the first position.
** Updates 'first' and 'last' pointers to maintain doubly linked list
** circularity and prints the operation if 'op_name' is provided.
**
** @param l_stack Double pointer to the stack to rotate.
** @param op_name String literal of the operation name to print (e.g. "rra").
** @return 1 on success, 0 if the stack has fewer than 2 elements.
*/
static int	shift_rotate_reverse(t_stack **l_stack, char *op_name)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*new_last;

	if (!l_stack || !*l_stack || !(*l_stack)->next)
		return (0);
	first = *l_stack;
	last = list_last(*l_stack);
	new_last = last->prev;
	new_last->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*l_stack = last;
	if (op_name)
	{
		write(1, op_name, 3);
		write(1, "\n", 1);
	}
	return (1);
}

/*
** Reverse Rotate A: Moves the last element of A to the top.
** Prints "rra\n" to the terminal on success.
**
** @param l_stack_a Double pointer to stack A.
** @param data Pointer to benchmark data to increment instruction counts.
*/
void	rra(t_stack **l_stack_a, t_data_bench *data)
{
	int	r;

	r = shift_rotate_reverse(l_stack_a, "rra");
	if (r && data)
	{
		data->total += 1;
		data->rra += 1;
	}
}

/*
** Reverse Rotate B: Moves the last element of B to the top.
** Prints "rrb\n" to the terminal on success.
**
** @param l_stack_b Double pointer to stack B.
** @param data Pointer to benchmark data to increment instruction counts.
*/
void	rrb(t_stack **l_stack_b, t_data_bench *data)
{
	int	r;

	r = shift_rotate_reverse(l_stack_b, "rrb");
	if (r && data)
	{
		data->total += 1;
		data->rrb += 1;
	}
}

/*
** Reverse Rotate r: Executes reverse rotation on both stacks simultaneously.
** Prints "rrr\n" to the terminal if both succeed.
**
** @param l_stack_a Double pointer to stack A.
** @param l_stack_b Double pointer to stack B.
** @param data Pointer to benchmark data to increment instruction counts.
*/
void	rrr(t_stack **l_stack_a, t_stack **l_stack_b, t_data_bench *data)
{
	if (!*l_stack_a || !*l_stack_b
		|| !(*l_stack_a)->next || !(*l_stack_b)->next)
		return ;
	shift_rotate_reverse(l_stack_a, NULL);
	shift_rotate_reverse(l_stack_b, NULL);
	write(1, "rrr\n", 4);
	if (data)
	{
		data->total += 1;
		data->rr += 1;
	}
}
