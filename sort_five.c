#include "push_swap.h"

/* Ordina stack di 4 o 5 elementi riducendo il problema a un caso base di 3.
 * Estrae i valori minimi da A e li sposta temporaneamente in B, 
 * ordina i restanti con 'sort_three' e reinserisce i minimi in testa ad A.*/
void	sort_five(t_stack **l_stack_a, t_stack **l_stack_b)
{
	int	size;

	size = list_size(*l_stack_a);
	if (!l_stack_a || !*l_stack_a || !l_stack_b)
		return;
	if (size < 4 || size > 5)
		return;
	if(size == 5)
		push_min_to_b(l_stack_a, l_stack_b);
	push_min_to_b(l_stack_a, l_stack_b);
	sort_three(l_stack_a);
	pa(l_stack_a, l_stack_b);
	pa(l_stack_a, l_stack_b);
}
