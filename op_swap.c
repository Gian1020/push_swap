/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:57:49 by gipimpin          #+#    #+#             */
/*   Updated: 2026/06/07 19:57:49 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Swaps the first and second elements of the stack.
** Updates 'first' and 'last' pointers to maintain doubly linked list
** circularity and prints the operation if 'op_name' is provided.
**
** @param l_stack Double pointer to the stack to modify.
** @param op_name String literal of the operation name to print (e.g. "sa").
** @return 1 on success, 0 if the stack has fewer than 2 elements.
*/
static int	swap(t_stack **l_stack, char *op_name)
{
	t_stack	*first;
	t_stack	*second;

	if (!l_stack || !*l_stack || !(*l_stack)->next)
		return (0);
	first = *l_stack;
	second = first->next;
	if (second->next)
		second->next->prev = first;
	first->prev = second;
	first->next = second->next;
	second->next = first;
	second->prev = NULL;
	*l_stack = second;
	if (op_name)
	{
		write(1, op_name, 2);
		write(1, "\n", 1);
	}
	return (1);
}

/*
** Swap A: Swaps the first and second elements of stack A.
** Prints "sa\n" to the terminal on success.
**
** @param l_stack_a Double pointer to stack A.
** @param data Pointer to benchmark data to increment instruction counts.
*/
void	sa(t_stack **l_stack_a, t_data_bench *data)
{
	int	r;

	r = swap(l_stack_a, "sa");
	if (r && data)
	{
		data->total += 1;
		data->sa += 1;
	}
}

/*
** Swap B: Swaps the first and second elements of stack B.
** Prints "sb\n" to the terminal on success.
**
** @param l_stack_b Double pointer to stack B.
** @param data Pointer to benchmark data to increment instruction counts.
*/
void	sb(t_stack **l_stack_b, t_data_bench *data)
{
	int	r;

	r = swap(l_stack_b, "sb");
	if (r && data)
	{
		data->total += 1;
		data->sb += 1;
	}
}

/*
** Simultaneous swap of both stack A and stack B.
** Prints "ss\n" to the terminal if both succeed.
**
** @param l_stack_a Double pointer to stack A.
** @param l_stack_b Double pointer to stack B.
** @param data Pointer to benchmark data to increment instruction counts.
*/
void	ss(t_stack **l_stack_a, t_stack **l_stack_b, t_data_bench *data)
{
	if (!*l_stack_a || !*l_stack_b
		|| !(*l_stack_a)->next || !(*l_stack_b)->next)
		return ;
	swap(l_stack_a, NULL);
	swap(l_stack_b, NULL);
	write(1, "ss\n", 3);
	if (data)
	{
		data->total += 1;
		data->ss += 1;
	}
	return ;
}
