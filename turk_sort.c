#include "push_swap.h"

void    no_combo_move_cost_a(t_stack **l_stack_a, t_stack *node_cheap, t_data_bench *data)
{
    if (node_cheap->cost_a > 0)
    {
        while (node_cheap->cost_a > 0)
        {
            ra(l_stack_a, data);
            node_cheap->cost_a--;
        }
    }
    else if (node_cheap->cost_a < 0)
    {
        while (node_cheap->cost_a < 0)
        {
            rra(l_stack_a, data);
            node_cheap->cost_a++;
        }
    }
}

void    no_combo_move_cost_b(t_stack **l_stack_b, t_stack *node_cheap, t_data_bench *data)
{
    if (node_cheap->cost_b > 0)
    {
        while (node_cheap->cost_b > 0)
        {
            rb(l_stack_b, data);
            node_cheap->cost_b--;
        }
    }
    else if (node_cheap->cost_b < 0)
    {
        while (node_cheap->cost_b < 0)
        {
            rrb(l_stack_b, data);
            node_cheap->cost_b++;
        }
    }
}

void    move_cheap_head_a(t_stack **l_stack_a, t_stack **l_stack_b, t_stack *node_cheap, t_data_bench *data)
{
    if (node_cheap->cost_a > 0 && node_cheap->cost_b > 0)
    {
        while (node_cheap->cost_a > 0 && node_cheap->cost_b > 0)
        {
            rr(l_stack_a, l_stack_b, data);
            node_cheap->cost_a--;
            node_cheap->cost_b--;
        }
    }
    else if (node_cheap->cost_a < 0 && node_cheap->cost_b < 0)
    {
        while (node_cheap->cost_a < 0 && node_cheap->cost_b < 0)
        {
            rrr(l_stack_a, l_stack_b, data);
            node_cheap->cost_a++;
            node_cheap->cost_b++;
        }
    }
    no_combo_move_cost_a(l_stack_a, node_cheap, data);
    no_combo_move_cost_b(l_stack_b, node_cheap, data);
    pb(l_stack_a, l_stack_b, data);
}

void    turk_sort(t_stack **l_stack_a, t_stack **l_stack_b, t_data_bench *data)
{
    t_stack *cheap;

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
    while (list_size(*l_stack_b))
        pa(l_stack_a, l_stack_b, data);
}