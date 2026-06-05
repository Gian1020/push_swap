#include "../push_swap.h"

/*Analizza la SIZE di A per scegliere un range adeguato.*/
static int	select_range(int size_a)
{
	return (ft_sqrt(size_a));
}

static int	do_rr_or_rb(t_stack **l_stack_a, t_stack **l_stack_b,
		int range, int i)
{
	if (*l_stack_a && (*l_stack_a)->idx > (range + i))
	{
		rr(l_stack_a, l_stack_b, NULL);
		return (0);
	}
	else
	{
		rb(l_stack_b, NULL);
		return (1);
	}
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
void	chunk_sort(t_stack **l_stack_a, t_stack **l_stack_b, t_data_bench *data)
{
	int		i;
	int		range;
	int		flag;

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
			flag = do_rr_or_rb(l_stack_a, l_stack_b, range, i);
			if (flag)
				data->rb += 1;
			else
				data->rr += 1;
			data->total += 1;
			i++;
		}
		else
			ra(l_stack_a, data);
	}
	while (*l_stack_b)
		push_smart_to_a(l_stack_a, l_stack_b, data);
}
