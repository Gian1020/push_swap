/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:05:32 by marvin            #+#    #+#             */
/*   Updated: 2026/06/07 19:57:55 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Ordina uno stack di 3 elementi in massimo 2 mosse.
 * 1. Identifica e sposta il valore massimo in terza posizione (bottom).
 * 2. Verifica se il valore minimo è in prima posizione. */
void	sort_three(t_stack **l_stack, t_data_bench *data)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*c;

	if (!l_stack || list_size(*l_stack) != 3)
		return ;
	a = *l_stack;
	b = a->next;
	c = b->next;
	if (a->idx > b->idx && b->idx < c->idx && a->idx < c->idx)
		sa(l_stack, data);
	else if (a->idx > b->idx && b->idx > c->idx)
	{
		sa(l_stack, data);
		rra(l_stack, data);
	}
	else if (a->idx > b->idx && b->idx < c->idx && a->idx > c->idx)
		ra(l_stack, data);
	else if (a->idx < b->idx && b->idx > c->idx && a->idx < c->idx)
	{
		sa(l_stack, data);
		ra(l_stack, data);
	}
	else if (a->idx < b->idx && b->idx > c->idx && a->idx > c->idx)
		rra(l_stack, data);
}
