/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:57:49 by gipimpin          #+#    #+#             */
/*   Updated: 2026/06/07 19:57:49 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Sorts stacks of 4 or 5 elements by reducing the problem to a base case of 3.
** Extracts the minimum values from A, temporarily moving them to B,
** sorts the remaining with 'sort_three', and reinserts minimums to A's top.
**
** @param l_stack_a Double pointer to stack A.
** @param l_stack_b Double pointer to stack B.
** @param data Pointer to benchmark data tracking sorting operations.
*/
void	sort_five(t_stack **l_stack_a, t_stack **l_stack_b, t_data_bench *data)
{
	int	size;

	if (!l_stack_a || !*l_stack_a || !l_stack_b)
		return ;
	size = list_size(*l_stack_a);
	if (size < 4 || size > 5)
		return ;
	if (size == 5)
		push_min_to_b(l_stack_a, l_stack_b, data);
	push_min_to_b(l_stack_a, l_stack_b, data);
	sort_three(l_stack_a, data);
	pa(l_stack_a, l_stack_b, data);
	if (size == 5)
		pa(l_stack_a, l_stack_b, data);
}
