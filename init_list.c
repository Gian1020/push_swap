/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 18:47:14 by marvin            #+#    #+#             */
/*   Updated: 2026/06/07 19:57:54 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Creates a new list element using malloc and sets all default values.
** The idx is initialized to -1 because 0 represents the first node.
**
** @param value The integer value to store in the newly created node.
** @return A pointer to the newly allocated node, or NULL on failure.
*/
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

/*
** Initializes the algorithm settings structure with default values (0).
** Used to track which sorting strategies and benchmarks are active.
**
** @return A pointer to the newly allocated t_algo struct, or NULL on failure.
*/
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

/*
** Initializes the benchmark structure to track sorting statistics and disorder.
**
** @param disorder The initial calculated disorder ratio of the stack.
** @return A pointer to the allocated t_data_bench struct, or NULL on failure.
*/
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

/*
** Initializes a structure to track the positions of maximum values.
** Used by specific sorting strategies to optimize move operations.
**
** @return A pointer to the allocated t_pos_max struct, or NULL on failure.
*/
t_pos_max	*init_pos_max(void)
{
	t_pos_max	*s_pos_max;

	s_pos_max = (t_pos_max *) malloc (sizeof(t_pos_max));
	s_pos_max->pos_max = 0;
	s_pos_max->pos_max_1 = 0;
	return (s_pos_max);
}
