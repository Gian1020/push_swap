#include "../push_swap.h"

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

void	set_cheapest(t_stack *l_stack)
{
	t_stack *cheapest_node;
	t_stack *current;

	if (l_stack == NULL)
		return ;
	current = l_stack;
	while (current != NULL)
	{
		current->is_cheap = 0;
		current = current->next;
	}
	cheapest_node = NULL;
	current = l_stack; 
	while (current != NULL)
	{
		if (current->total_cost != INT_MAX)
		{
			if (current->total_cost < cheapest_node->total_cost)
				cheapest_node = current;
		}
		current = current->next;
	}
	if (cheapest_node)
		cheapest_node->is_cheap = 1;
}