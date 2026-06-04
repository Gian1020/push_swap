#include "push_swap.h"

/* Restituisce l'index attuale del nodo con il valore più piccolo della lista.*/
int	get_pos_idx_min(t_stack *l_stack)
{
	int	i;
	int	idx_stack_min;
	int	idx_value_min;

	if (!l_stack)
		return (-1);
	i = 0;
	idx_stack_min = 0;
	idx_value_min = l_stack->idx;
	while (l_stack != NULL)
	{
		if (l_stack->idx < idx_value_min)
		{
			idx_value_min = l_stack->idx;
			idx_stack_min = i;
		}
		i++;
		l_stack = l_stack->next;
	}
	return (idx_stack_min);
}

/* Restituisce l'indice attuale del nodo con il valore più grande della lista.*/
int	get_pos_idx_max(t_stack *l_stack, int target_to_ignore)
{
	int	i;
	int	idx_stack_max;
	int	idx_value_max;

	if (!l_stack)
		return (-1);
	i = 0;
	idx_stack_max = 0;
	idx_value_max = -1;
	while (l_stack != NULL)
	{
		if (l_stack->idx != target_to_ignore && l_stack->idx > idx_value_max)
		{
			idx_value_max = l_stack->idx;
			idx_stack_max = i;
		}
		i++;
		l_stack = l_stack->next;
	}
	return (idx_stack_max);
}

/* Individua il valore min in A inserendolo in B ottimizzando il num di mosse.
 * Calcola l'index del minimo rispetto alla mezzeria dello stack (size/2)
 * per decidere se utilizzare rotazioni dirette (ra) o inverse (rra). 
 * Una volta che il primo elemento è in posizione 0 
 * lo inserisce come primo elemento di B*/
void	push_min_to_b(t_stack **l_stack_a, t_stack **l_stack_b,
		t_data_bench *data)
{
	int	pos_min;
	int	size;

	if (!l_stack_a || !*l_stack_a)
		return ;
	pos_min = get_pos_idx_min(*l_stack_a);
	size = list_size(*l_stack_a);
	if (pos_min <= size / 2)
	{
		while (pos_min > 0)
		{
			ra(l_stack_a, data);
			pos_min--;
		}
	}
	else
	{
		while (pos_min < size)
		{
			rra(l_stack_a, data);
			pos_min++;
		}
	}
	pb(l_stack_a, l_stack_b, data);
}

/* Individua il valore max in B inserendolo in A ottimizzando num di mosse.
 * Calcola l'index del minimo rispetto alla mezzeria dello stack (size/2)
 * per decidere se utilizzare rotazioni dirette (rb) o inverse (rrb).
 * Una volta che il primo elemento è in posizione 0
 * lo inserisce come primo elemento di A*/
void	bring_to_top_b(t_stack **l_stack, int target_pos, t_data_bench *data)
{
	int	size;

	if (!l_stack || !*l_stack)
		return ;
	size = list_size(*l_stack);
	if (target_pos <= size / 2)
	{
		while (target_pos > 0)
		{
			rb(l_stack, data);
			target_pos--;
		}
	}
	else
	{
		while (target_pos < size)
		{
			rrb(l_stack, data);
			target_pos++;
		}
	}
}

void	bring_target_to_top_a(t_stack **l_stack_a, t_stack *target,
        	t_data_bench *data)
{
    int pos;
    int size;

    insert_curr_pos(*l_stack_a);
    pos  = target->curr_pos;
    size = list_size(*l_stack_a);
    if (pos <= size / 2)
        while (pos-- > 0)
            ra(l_stack_a, data);
    else
        while (pos++ < size)
            rra(l_stack_a, data);
}
