#include "push_swap.h"

t_stack	*find_min(t_stack *l_stack)
{
	t_stack	*min;

	if (!l_stack)
		return (NULL);
	min = l_stack;
	while (l_stack != NULL)
	{
		if (l_stack->idx < min->idx)
			min = l_stack;
		l_stack = l_stack->next;
	}
	return (min);
}

t_stack	*find_max(t_stack *l_stack)
{
	t_stack	*max;

	max = l_stack;
	while (l_stack != NULL)
	{
		if (l_stack->idx > max->idx)
			max = l_stack;
		l_stack = l_stack->next;
	}
	return (max);
}

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
