#include "../push_swap.h"

static void	set_calculate_total_cost(t_stack *node_in_a)
{
	if ((node_in_a->cost_a > 0 && node_in_a->cost_b > 0)
				|| (node_in_a->cost_a < 0 && node_in_a->cost_b < 0))
		{
			if (node_in_a->cost_a > node_in_a->cost_b)
				node_in_a->total_cost = node_in_a->cost_a;
			else
				node_in_a->total_cost = node_in_a->cost_b;
		}
		else
        	node_in_a->total_cost = ft_abs(node_in_a->cost_a) + ft_abs(node_in_a->cost_b);
}

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
    		node_in_a->cost_b = 0;
    		node_in_a->total_cost = INT_MAX;
    		node_in_a = node_in_a->next;
    		continue;
		}        
		if (target_node->curr_pos <= (len_b / 2))
            node_in_a->cost_b = target_node->curr_pos;
		else
            node_in_a->cost_b = -(len_b - target_node->curr_pos);
        set_calculate_total_cost(node_in_a);
        node_in_a = node_in_a->next;
    }
}
