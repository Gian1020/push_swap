#include "push_swap.h"

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
	pos_min = get_pos_idx_min(*l_stack_a);
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
void	bring_to_top_b(t_stack **l_stack, int target_pos)
{
	int	size;

	if (!l_stack || !*l_stack)
		return ;
	size = list_size(*l_stack);
	if (target_pos <= size / 2)
	{
		while (target_pos > 0)
		{
			rb(l_stack);
			target_pos--;
		}
	}
	else
	{
		while (target_pos < size)
		{
			rrb(l_stack);
			target_pos++;
		}
	}
}

void bring_target_to_top_a(t_stack **l_stack_a, t_stack *target)
{
    int pos;
    int size;
    int moves;

    insert_curr_pos(*l_stack_a);
    pos  = target->curr_pos;
    size = list_size(*l_stack_a);
    if (pos <= size / 2)
    {
        moves = pos;
        while (moves-- > 0)
            ra(l_stack_a);
    }
    else
    {
        moves = size - pos;
        while (moves-- > 0)
            rra(l_stack_a);
    }
}
