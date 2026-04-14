#include "push_swap.h"

/* Sposta il primo elemento dello stack e il secondo elemento.
 * Aggiorna i puntatori 'first' e 'last' per mantenere la circolarità della lista
 * doppiamente concatenata e scrive l'operazione se 'op_name' è fornito.
 * Ritorna 1 in caso di successo, 0 se lo stack ha meno di 2 elementi. */
static int	swap(t_stack **l_stack, char *op_name)
{
	t_stack	*first;
	t_stack	*second;

	if (!l_stack || !*l_stack || !(*l_stack)->next)
		return (0);
	first = *l_stack;
	second = first->next;
	if (second->next)
		second->next->prev = first;
	first->prev = second;
	first->next = second->next;
	second->next = first;
	second->prev = NULL;
	*l_stack = second;
	if (op_name)
	{
		write(1, op_name, 2);
		write(1, "\n", 1);
	}
	return (1);
}

/* Swap A: sposta il primo elemento di a con il secondo.
 * Stampa "sa\n" nel terminale in caso di successo. */
int	sa(t_stack **l_stack_a)
{
	return (swap(l_stack_a, "sa"));
}

/* Swap B: sposta il primo elemento di a con il secondo.
 * Stampa "sb\n" nel terminale in caso di successo. */
int	sb(t_stack **l_stack_b)
{
	return (swap(l_stack_b, "sb"));
}

/* Swap simultaneo sia dello stack A che lo stack B. .
 * Stampa "ss\n" nel terminale se entrambe vanno a buon fine*/
int	ss(t_stack **l_stack_a, t_stack **l_stack_b)
{
	if (!*l_stack_a || !*l_stack_b
		|| !(*l_stack_a)->next || !(*l_stack_b)->next)
		return (0);
	swap(l_stack_a, NULL);
	swap(l_stack_b, NULL);
	write(1, "ss\n", 3);
	return (1);
}
