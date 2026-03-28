#include "push_swap.h"

/* Rotazione verso il basso.
 * Sposta l'ultimo elemento dello stack in prima posizione 
 * Aggiorna i puntatori 'first' e 'last' per mantenere la circolarità della lista
 * doppiamente concatenata e scrive l'operazione se 'op_name' è fornito.
 * Ritorna 1 in caso di successo, 0 se lo stack ha meno di 2 elementi.*/
static int	shift_rotate_reverse(t_stack **l_stack, char *op_name)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*new_last;

	if (!l_stack || !*l_stack || !(*l_stack)->next)
		return (0);
	first = *l_stack;
	last = list_last(*l_stack);
	new_last = last->prev;
	new_last->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*l_stack = last;
	if (op_name)
	{
		write(1, op_name, 3);
		write(1, "\n", 1);
	}
	return (1);
}

/* Reverse Rotate A: Sposta l'ultimo elemento di A in cima.
 * Stampa "rra\n" nel terminale in caso di successo. */
int	rra(t_stack **l_stack_a)
{
	return (shift_rotate_reverse(l_stack_a, "rra"));
}

/* Reverse Rotate A: Sposta l'ultimo elemento di B in cima.
 * Stampa "rrb\n" nel terminale in caso di successo.*/
int	rrb(t_stack **l_stack_b)
{
	return (shift_rotate_reverse(l_stack_b, "rrb"));
}

/* Reverse Rotate r: Esegue la rotazione inversa su entrambi gli stack.
 * Stampa "rrr\n" se entrambi hanno avuto successo. */
int	rrr(t_stack **l_stack_a, t_stack **l_stack_b)
{
	int	flag;

	flag = 0;
	flag += shift_rotate_reverse(l_stack_a, NULL);
	flag += shift_rotate_reverse(l_stack_b, NULL);
	if (flag == 2)
		write(1, "rrr\n", 4);
	return (flag);
}
