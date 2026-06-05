/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:44:47 by marvin            #+#    #+#             */
/*   Updated: 2026/06/05 16:44:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	turk_push_back(t_stack **l_stack_a, t_stack **l_stack_b, t_data_bench *data)
{
	t_stack	*target;

	while (list_size(*l_stack_b) > 0)
	{
		target = get_target_in_a(*l_stack_b, *l_stack_a);
		bring_target_to_top_a(l_stack_a, target, data);
		pa(l_stack_a, l_stack_b, data);
	}
	bring_target_to_top_a(l_stack_a, find_min(*l_stack_a), data);
}

void	turk_sort(t_stack **l_stack_a, t_stack **l_stack_b, t_data_bench *data)
{
	t_stack	*cheap;

	pb(l_stack_a, l_stack_b, data);
	pb(l_stack_a, l_stack_b, data);
	while (list_size(*l_stack_a) > 3)
	{
		insert_curr_pos(*l_stack_a);
		insert_curr_pos(*l_stack_b);
		set_all_target(*l_stack_a, *l_stack_b);
		calculate_cost(*l_stack_a, *l_stack_b);
		set_cheapest(*l_stack_a);
		cheap = find_cheap(*l_stack_a);
		move_cheap_head_a(l_stack_a, l_stack_b, cheap, data);
	}
	sort_three(l_stack_a, data);
	turk_push_back(l_stack_a, l_stack_b, data);
}
