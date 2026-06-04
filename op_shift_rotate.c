#include "push_swap.h"

/* Rotazione verso l'alto
 * Sposta il primo elemento dello stack in ultima posizione 
 * Aggiorna i puntatori 'first' e 'last' per mantenere la circolarità della lista
 * doppiamente concatenata e scrive l'operazione se 'op_name' è fornito.
 * Ritorna 1 in caso di successo, 0 se lo stack ha meno di 2 elementi.*/
static int	shift_rotate(t_stack **l_stack, char *op_name)
{
	t_stack	*first;
	t_stack	*last;

	if (!l_stack || !*l_stack || !(*l_stack)->next)
		return (0);
	first = *l_stack;
	last = list_last(*l_stack);
	*l_stack = first->next;
	first->next->prev = NULL;
	first->prev = last;
	first->next = NULL;
	last->next = first;
	if (op_name)
	{
		write(1, op_name, 2);
		write(1, "\n", 1);
	}
	return (1);
}

/* Rotate A: Prende il primo elemento di A e lo sposta all'ultima posizione.
 * Stampa "ra\n" nel terminale in caso di successo.*/
int	ra(t_stack **l_stack_a, t_data_bench *data)
{
	int	r;

	r = shift_rotate(l_stack_a, "ra");
	if (r && data)
	{
		data->total += 1;
		data->ra += 1;
	}
	return (r);
}

/* Rotate B: Prende il primo elemento di B e lo sposta all'ultima posizione.
 * Stampa "rb\n" nel terminale in caso di successo.*/
int	rb(t_stack **l_stack_b, t_data_bench *data)
{
	int	r;

	r = shift_rotate(l_stack_b, "rb");
	if (r && data)
	{
		data->total += 1;
		data->rb += 1;
	}
	return (r);
}

/* Rotate simultaneamente sia lo stack A che lo stack B.
 * Stampa "rr\n" nel terminale se entrambe vanno a buon fine.*/
int	rr(t_stack **l_stack_a, t_stack **l_stack_b, t_data_bench *data)
{
	if (!*l_stack_a || !*l_stack_b
		|| !(*l_stack_a)->next || !(*l_stack_b)->next)
		return (0);
	shift_rotate(l_stack_a, NULL);
	shift_rotate(l_stack_b, NULL);
	write(1, "rr\n", 3);
	if (data)
	{
		data->total += 1;
		data->rr += 1;
	}
	return (1);
}
