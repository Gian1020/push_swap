/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max_min_extraction.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecelli <gpecelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:39:47 by gpecelli          #+#    #+#             */
/*   Updated: 2026/06/04 14:03:21 by gpecelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back_to_a(t_stack **l_stack_a, t_stack **l_stack_b,
		t_data_bench *data)
{
	if (!l_stack_b || !*l_stack_b)
		return ;
	while (*l_stack_b != NULL)
	{
		pa(l_stack_a, l_stack_b, data);
	}
}

void	sort_max_min_extraction(t_stack **l_stack_a, t_stack **l_stack_b,
		t_data_bench *data)
{
	if (*l_stack_b != NULL)
		list_clear(l_stack_b);
	while (*l_stack_a != NULL)
		push_min_to_b(l_stack_a, l_stack_b, data);
	push_back_to_a(l_stack_a, l_stack_b, data);
}
