#include "push_swap.h"

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while ((i * i) < nb + 1)
	{
		if ((i * i) == nb)
			return (i);
		i++;
	}
	return (0);
}

/*Analizza la SIZE di A per scegliere un range adeguato.*/
static int	select_range(int size_a)
{
	int	range;

	range = ft_sqtr(size_a);
	return (range);
}

static void	do_rr_or_rb(t_stack **l_stack_a, t_stack **l_stack_b,
		int range, int i, t_data_bench *data)
{
	if (*l_stack_a && (*l_stack_a)->idx > (range + i))
		rr(l_stack_a, l_stack_b, data);
	else
		rb(l_stack_b, data);
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
void	sort_big(t_stack **l_stack_a, t_stack **l_stack_b, t_data_bench *data)
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
			pb(l_stack_a, l_stack_b, data);
			i++;
		}
		else if ((*l_stack_a)->idx <= (range + i))
		{
			pb(l_stack_a, l_stack_b, data);
			do_rr_or_rb(l_stack_a, l_stack_b, range, i, data);
			i++;
		}
		else
			ra(l_stack_a, data);
	}
	while (*l_stack_b)
		push_smart_to_a(l_stack_a, l_stack_b, data);
}

/* Coordina la strategia di ordinamento in base al numero di elementi.
 * Verifica se lo stack è già ordinato o troppo piccolo, quindi delega 
 * l'esecuzione ad algoritmi specializzati per gestire i vari casi. */
void	sort_stack(t_stack **l_stack_a, t_data_bench *data)
{
	int		size;
	t_stack	*l_stack_b;

	size = list_size(*l_stack_a);
	if (!l_stack_a || size < 2 || is_sorted(*l_stack_a))
		return ;
	l_stack_b = NULL;
	if (size == 2)
		sort_two(l_stack_a, data);
	else if (size == 3)
		sort_three(l_stack_a, data);
	else if (size <= 5)
		sort_five(l_stack_a, &l_stack_b, data);
	else
		sort_big(l_stack_a, &l_stack_b, data);
		//sort_max_min_extraction(l_stack_a, &l_stack_b);
	list_clear(&l_stack_b);
}
