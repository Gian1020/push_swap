/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecelli <gpecelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 11:48:34 by gpecelli          #+#    #+#             */
/*   Updated: 2026/06/04 14:45:10 by gpecelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

// // passed only the current node

// void	calculate_cost(t_stack *stack_a, t_stack *stack_b)
// {
// 	int	len_a;
// 	int	len_b;
// 	int	above_median;
// 	t_stack	*node_in_a;
// 	t_stack	*target_node;

// 	above_median = 1;
// 	len_a = list_size(stack_a);
// 	len_b = list_size(stack_b);
// 	node_in_a = stack_a;
// 	while (node_in_a != NULL)
// 	{
// 		if (node_in_a->curr_pos < (len_a / 2))
// 			node_in_a->cost_a = node_in_a->curr_pos;
// 		else
// 		{
// 			above_median = -above_median;
// 			node_in_a->cost_a = len_a - node_in_a->curr_pos;
// 		}
		
// 		target_node = stack_a->target;

// 		if (target_node->curr_pos < (len_b / 2))
// 		{
// 			target_node->cost_b = target_node->curr_pos;
// 		}
// 		else
// 		{
// 			above_median = -above_median;
// 			target_node->cost_b = len_b - target_node->curr_pos;
// 		}

// 		node_in_a->total_cost = node_in_a->cost_a + target_node->cost_b;
// 		node_in_a = node_in_a->next;
// 	}
// }

// void execute_and_push(t_stack **stack_a, t_stack **stack_b, t_stack *nodo_piu_economico)
// {
// 	// --- 1. PORTA IL NODO DI A IN CIMA ---
// 	// Finché il nodo più economico non si trova in testa allo stack A
// 	while (*stack_a != nodo_piu_economico)
// 	{
// 		if (nodo_piu_economico->above_median == true)
// 			// Fai ruotare in avanti -> esegui ra()
// 		else
// 			// Fai ruotare all'indietro -> esegui rra()
// 	}

// 	// --- 2. PORTA IL TARGET IN CIMA A B ---
// 	// Finché il target di quel nodo non si trova in testa allo stack B
// 	while (*stack_b != nodo_piu_economico->target_node)
// 	{
// 		if (nodo_piu_economico->target_node->above_median == true)
// 			// Fai ruotare in avanti -> esegui rb()
// 		else
// 			// Fai ruotare all'indietro -> esegui rrb()
// 	}

// 	// --- 3. IL MOMENTO MAGICO ---
// 	// Ora che entrambi sono in cima ai rispettivi stack:
// 	// Esegui pb() per lanciare il nodo da A a B!
// }
