#include "../push_swap.h"

/*Analizza la SIZE di A per scegliere un range adeguato.*/
static int	select_range(int size_a)
{
	if (size_a <= 20)
		return (4);
	if (size_a <= 100)
		return (16);
	if (size_a <= 200)
		return (24);
	if (size_a <= 500)
		return (35);
	return (45);
}

static void	do_rr_or_rb(t_stack **l_stack_a, t_stack **l_stack_b,
		int range, int i)
{
	if (*l_stack_a && (*l_stack_a)->idx > (range + i))
		rr(l_stack_a, l_stack_b);
	else
		rb(l_stack_b);
}

/* Funzione che gestisce l ordinamento di A se SIZE > 5.
 * 1) Analizzo SIZE scegliere per un range adeguato tramite selection_range.
 * 2) Inseriamo tutti gli elementi di a in B con una pre-selezione.
 *    - Analizza l'indice di A:
 * 	se l indice fa parte del range corrente, lo inseriamo davanti in a B.
 *    - Altrimenti se fa parte del range subito successivo lo aggiungiamo in B
 * 	ma come ultimo elemento.
 *    - Altrimenti lo mettiamo in fondo ad A.
 * 3) Inseriamo il nodo più grande di B in A fino a che B non è vuoto.
 * */
void	chunk_sort(t_stack **l_stack_a, t_stack **l_stack_b)
{
	int		i;
	int		range;

	if (!l_stack_a || !*l_stack_a || !l_stack_b)
		return ;
	i = 0;
	range = select_range(list_size(*l_stack_a));
	while (*l_stack_a)
	{
		if ((*l_stack_a)->idx <= i)
		{
			pb(l_stack_a, l_stack_b);
			i++;
		}
		else if ((*l_stack_a)->idx <= (range + i))
		{
			pb(l_stack_a, l_stack_b);
			do_rr_or_rb(l_stack_a, l_stack_b, range, i);
			i++;
		}
		else
			ra(l_stack_a);
	}
	while (*l_stack_b)
		push_smart_to_a(l_stack_a, l_stack_b);
}
