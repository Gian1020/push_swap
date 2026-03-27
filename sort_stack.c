#include "push_swap.h"

/* Coordina la strategia di ordinamento in base al numero di elementi.
 * Verifica se lo stack è già ordinato o troppo piccolo, quindi delega 
 * l'esecuzione ad algoritmi specializzati per gestire i vari casi.*/
void	sort_stack(t_stack **l_stack_a)
{
	int	size;
	t_stack *l_stack_b;

	size = list_size(*l_stack_a);
	if (!l_stack_a || size < 2 || is_sorted(*l_stack_a))
		return ;
	l_stack_b = NULL;
	if (size == 2)
		sa(l_stack_a);
	else if (size == 3)
		sort_three(l_stack_a);
	else if (size <= 5)
		sort_five(l_stack_a, &l_stack_b);
}
