/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:18:03 by marvin            #+#    #+#             */
/*   Updated: 2026/06/07 19:57:53 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Deallocates the stacks and structures passed as parameters.
** Prints "Error\n" to the standard error output (file descriptor 2).
** Halts the program execution using exit(1).
**
** @param l_stack_a Double pointer to stack A for deallocation.
** @param l_stack_b Double pointer to stack B for deallocation.
** @param algo Pointer to the algorithm struct for deallocation.
*/
void	handle_error(t_stack **l_stack_a, t_stack **l_stack_b, t_algo *algo)
{
	if (l_stack_a && *l_stack_a)
		list_clear(l_stack_a);
	if (l_stack_b && *l_stack_b)
		list_clear(l_stack_b);
	if (algo)
		free(algo);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

/*
** Clears memory of lists and structures before a successful program exit.
** Halts the program using exit(0).
**
** @param l_stack_a Double pointer to stack A for deallocation.
** @param l_stack_b Double pointer to stack B for deallocation.
** @param data Pointer to the benchmark struct for deallocation.
** @param algo Pointer to the algorithm struct for deallocation.
*/
void	finish_prog(t_stack **l_stack_a, t_stack **l_stack_b,
			t_data_bench *data, t_algo *algo)
{
	if (l_stack_a && *l_stack_a)
		list_clear(l_stack_a);
	if (l_stack_b && *l_stack_b)
		list_clear(l_stack_b);
	if (algo)
		free(algo);
	if (data)
		free(data);
	exit(0);
}
