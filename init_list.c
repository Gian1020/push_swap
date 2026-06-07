/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 18:47:14 by marvin            #+#    #+#             */
/*   Updated: 2026/06/07 18:47:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Crea un nuovo elemento della lista usando malloc,
 * setta tutti i valori di default.
 * idx -> -1 perché 0 rappresenta il primo nodo della lista.*/
t_stack	*new_node(int value)
{
	t_stack	*node;

	node = (t_stack *) malloc (sizeof(t_stack));
	if (!node)
		return (NULL);
	node->idx = -1;
	node->value = value;
	node->cost_a = 0;
	node->cost_b = 0;
	node->total_cost = 0;
	node->prev = NULL;
	node->next = NULL;
	node->target = NULL;
	return (node);
}

t_algo	*init_algo(void)
{
	t_algo	*algo;

	algo = (t_algo *) malloc (sizeof(t_algo));
	if (!algo)
		return (NULL);
	algo->simple = 0;
	algo->medium = 0;
	algo->complex = 0;
	algo->adaptive = 0;
	algo->bench = 0;
	return (algo);
}

t_data_bench	*init_bench(float disorder)
{
	t_data_bench	*bench;

	bench = (t_data_bench *) malloc (sizeof(t_data_bench));
	bench->disorder = disorder;
	bench->total = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	return (bench);
}
