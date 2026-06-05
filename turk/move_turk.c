#include "../push_swap.h"

void    no_combo_move_cost_a(t_stack **l_stack_a, t_stack *node_cheap)
{
    if (node_cheap->cost_a > 0)
    {
        while (node_cheap->cost_a > 0)
        {
            ra(l_stack_a);
            node_cheap->cost_a--;
        }
    }
    else if (node_cheap->cost_a < 0)
    {
        while (node_cheap->cost_a < 0)
        {
            rra(l_stack_a);
            node_cheap->cost_a++;
        }
    }
}

void    no_combo_move_cost_b(t_stack **l_stack_b, t_stack *node_cheap)
{
    if (node_cheap->cost_b > 0)
    {
        while (node_cheap->cost_b > 0)
        {
            rb(l_stack_b);
            node_cheap->cost_b--;
        }
    }
    else if (node_cheap->cost_b < 0)
    {
        while (node_cheap->cost_b < 0)
        {
            rrb(l_stack_b);
            node_cheap->cost_b++;
        }
    }
}

void    move_cheap_head_a(t_stack **l_stack_a, t_stack **l_stack_b, t_stack *node_cheap)
{
    if (node_cheap->cost_a > 0 && node_cheap->cost_b > 0)
    {
        while (node_cheap->cost_a > 0 && node_cheap->cost_b > 0)
        {
            rr(l_stack_a, l_stack_b);
            node_cheap->cost_a--;
            node_cheap->cost_b--;
        }
    }
    else if (node_cheap->cost_a < 0 && node_cheap->cost_b < 0)
    {
        while (node_cheap->cost_a < 0 && node_cheap->cost_b < 0)
        {
            rrr(l_stack_a, l_stack_b);
            node_cheap->cost_a++;
            node_cheap->cost_b++;
        }
    }
    no_combo_move_cost_a(l_stack_a, node_cheap);
    no_combo_move_cost_b(l_stack_b, node_cheap);
    pb(l_stack_a, l_stack_b);
}