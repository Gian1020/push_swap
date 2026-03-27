#include "push_swap.h"

/* Verifica se la lista è ordinata in ordine crescente.
 * Se lo è torna 1 altrimenti 0.*/
int	is_sorted(t_stack *l_stack)
{
	if(!l_stack)
		return (1);
	while (l_stack && l_stack->next)
	{
		if (l_stack->idx > l_stack->next->idx)
			return (0);
		l_stack = l_stack->next;
	}
	return (1);
}

/* Restituisce l'indice attuale del nodo con il valore più piccolo della lista.*/
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
	while(l_stack != NULL)
	{
		if(l_stack->idx < idx_value_min)
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
	while(l_stack != NULL)
	{
		if(l_stack->idx > idx_value_max)
		{
			idx_value_max = l_stack->idx;
			idx_stack_max = i;
		}
		i++;
		l_stack = l_stack->next;
	}
	return (idx_stack_max);
}

int	find_pos_in_stack(t_stack *l_stack, int idx_to_find)
{
	int	i;

	i = 0;
	while(l_stack != NULL)
	{
		if(l_stack->idx == idx_to_find)
			return (i);
		i++;
		l_stack = l_stack->next;
	}
	return (-1);
}

/* Individua il valore minimo in A e lo sposta in B ottimizzando il numero di mosse.
 * Calcola la posizione (index) del minimo rispetto alla mezzeria dello stack (size/2)
 * per decidere se utilizzare rotazioni dirette (ra) o inverse (rra). 
 * Una volta che il primo elemento è in posizione 0 
 *  -la
 *  o inserisce come primo elemento di B*/
void	push_min_to_b(t_stack **l_stack_a, t_stack **l_stack_b)
{
	int	idx_min;
	int	size;

	if (!l_stack_a || !*l_stack_a)
		return ;
	idx_min = find_pos_idx_min(*l_stack_a);
	size = list_size(*l_stack_a);
	if (idx_min <= size / 2)
	{
		while (idx_min > 0)
		{
			ra(l_stack_a);
			idx_min--;
		}
	}
	else
	{
		while (idx_min < size)
		{
			rra(l_stack_a);
			idx_min++;
		}
	}
	pb(l_stack_a, l_stack_b);
}
