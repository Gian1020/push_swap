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

#include "push_swap.h"

void    calculate_cost(t_stack *stack_a, t_stack *stack_b)
{
    int len_a;
    int len_b;
    t_stack *node_in_a;
    t_stack *target_node;

    len_a = list_size(stack_a);
    len_b = list_size(stack_b);
    node_in_a = stack_a;
    while (node_in_a != NULL)
    {
        if (node_in_a->curr_pos <= (len_a / 2))
            node_in_a->cost_a = node_in_a->curr_pos;
        else
            node_in_a->cost_a = -(len_a - node_in_a->curr_pos);
        target_node = node_in_a->target;
        if (!target_node)
        {
            node_in_a = node_in_a->next;
            continue;
        }
        if (target_node->curr_pos <= (len_b / 2))
            node_in_a->cost_b = target_node->curr_pos;
        else
            node_in_a->cost_b = -(len_b - target_node->curr_pos);
        node_in_a->total_cost = ft_abs(node_in_a->cost_a) + ft_abs(node_in_a->cost_b);
        node_in_a = node_in_a->next;
    }
}

t_stack *find_cheap(t_stack *l_stack)
{
    t_stack *temp;

    temp = l_stack;
    while(temp != NULL)
    {
        if (temp->is_cheap)
            return (temp);
        temp = temp->next;
    }
    return (NULL);
}

void set_cheapest(t_stack *l_stack)
{
    t_stack *cheapest_node;
    t_stack *current;

    if (l_stack == NULL)
        return ;
    cheapest_node = l_stack;
    current = l_stack;
    while (current != NULL)
    {
        current->is_cheap = 0;
        if (current->total_cost < cheapest_node->total_cost)
            cheapest_node = current;
        current = current->next;
    }
    cheapest_node->is_cheap = 1;
}

void    insert_curr_pos(t_stack *l_stack)
{
    int     i;
    t_stack *temp;

    if (!l_stack)
        return ;
    i = 0;
    temp = l_stack;
    while (temp != NULL)
    {
        temp->curr_pos = i;
        i++;
        temp = temp->next;
    }
}