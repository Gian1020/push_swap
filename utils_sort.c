#include "push_swap.h"

/* Restituisce l'index attuale del nodo con il valore più piccolo della lista.*/
int	find_pos_idx_min(t_stack *l_stack)
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
int	find_pos_idx_max(t_stack *l_stack)
{
	int	i;
	int	idx_stack_max;
	int	idx_value_max;

	if (!l_stack)
		return (-1);
	i = 0;
	idx_stack_max = 0;
	idx_value_max = l_stack->idx;
	while (l_stack != NULL)
	{
		if (l_stack->idx > idx_value_max)
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
void	push_min_to_b(t_stack **l_stack_a, t_stack **l_stack_b)
{
	int	pos_min;
	int	size;

	if (!l_stack_a || !*l_stack_a)
		return ;
	pos_min = find_pos_idx_min(*l_stack_a);
	size = list_size(*l_stack_a);
	if (pos_min <= size / 2)
	{
		while (pos_min > 0)
		{
			ra(l_stack_a);
			pos_min--;
		}
	}
	else
	{
		while (pos_min < size)
		{
			rra(l_stack_a);
			pos_min++;
		}
	}
	pb(l_stack_a, l_stack_b);
}

/* Individua il valore max in B inserendolo in A ottimizzando num di mosse.
 * Calcola l'index del minimo rispetto alla mezzeria dello stack (size/2)
 * per decidere se utilizzare rotazioni dirette (rb) o inverse (rrb).
 * Una volta che il primo elemento è in posizione 0
 * lo inserisce come primo elemento di A*/
void	push_max_to_a(t_stack **l_stack_a, t_stack **l_stack_b)
{
	int	pos_max;
	int	size;

	if (!l_stack_b || !*l_stack_b || !l_stack_a)
		return ;
	pos_max = find_pos_idx_max(*l_stack_b);
	size = list_size(*l_stack_b);
	if (pos_max <= size / 2)
	{
		while (pos_max > 0)
		{
			rb(l_stack_b);
			pos_max--;
		}
	}
	else
	{
		while (pos_max < size)
		{
			rrb(l_stack_b);
			pos_max++;
		}
	}
	pa(l_stack_a, l_stack_b);
}
