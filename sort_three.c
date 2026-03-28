#include "push_swap.h"

/* Ordina uno stack di 3 elementi in massimo 2 mosse.
 * 1. Identifica e sposta il valore massimo in terza posizione (bottom).
 * 2. Verifica se il valore minimo è in prima posizione. */
void	sort_three(t_stack **l_stack)
{
	int	idx_max;
	int	idx_min;

	if (!l_stack || list_size(*l_stack) != 3)
		return ;
	idx_max = find_pos_idx_max(*l_stack);
	if (idx_max == 0)
		ra(l_stack);
	if (idx_max == 1)
		rra(l_stack);
	idx_min = find_pos_idx_min(*l_stack);
	if (idx_min == 1)
		sa(l_stack);
}
