/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecelli <gpecelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:19:44 by gpecelli          #+#    #+#             */
/*   Updated: 2026/06/03 17:05:42 by gpecelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int value)
{
	t_stack	*node;

	node = (t_stack *) malloc (sizeof(t_stack));
	if (!node)
		return (NULL);
	node->idx = -1;
	node->value = value;
	node->target = 0;
	node->cost_a = 0;
	node->cost_b = 0;
	node->is_cheap = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_algo	*init_struct_algo(void)
{
	t_algo	*algo_config;

	algo_config = (t_algo *) malloc (sizeof(t_algo));
	if (!algo_config)
		return (NULL);
	algo_config->simple = 0;
	algo_config->medium = 0;
	algo_config->complex = 0;
	algo_config->adaptive = 1;
	algo_config->bench = 0;
	return (algo_config);
}

t_data_bench	*init_data_bench(void)
{
	t_data_bench	*data_bench;

	data_bench = (t_data_bench *) malloc (sizeof(t_data_bench));
	if (!data_bench)
		return (NULL);
	data_bench->total_ops = 0;
	data_bench->sa = 0;
	data_bench->sb = 0;
	data_bench->ss = 0;
	data_bench->pa = 0;
	data_bench->pb = 0;
	data_bench->ra = 0;
	data_bench->rb = 0;
	data_bench->rr = 0;
	data_bench->rra = 0;
	data_bench->rrb = 0;
	data_bench->rrr = 0;
	return (data_bench);
}
