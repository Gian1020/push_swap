/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_shift_rotate_reverse_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecelli <gpecelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:57:49 by gipimpin          #+#    #+#             */
/*   Updated: 2026/06/08 17:01:05 by gpecelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/* Rotazione verso il basso.
 * Sposta l'ultimo elemento dello stack in prima posizione 
 * Aggiorna i puntatori 'first' e 'last' per mantenere la
 * circolarità della lista doppiamente concatenata e scrive
 * l'operazione se 'op_name' è fornito.
 * Ritorna 1 in caso di successo, 0 se lo stack ha meno di
 * 2 elementi.*/
static void	shift_rotate_reverse(t_stack **l_stack)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*new_last;

	if (!l_stack || !*l_stack || !(*l_stack)->next)
		return ;
	first = *l_stack;
	last = list_last(*l_stack);
	new_last = last->prev;
	new_last->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*l_stack = last;
}

/* Reverse Rotate A: Sposta l'ultimo elemento di A in cima.
 * Stampa "rra\n" nel terminale in caso di successo. */
void	rra_b(t_stack **l_stack_a)
{
	shift_rotate_reverse(l_stack_a);
}

/* Reverse Rotate A: Sposta l'ultimo elemento di B in cima.
 * Stampa "rrb\n" nel terminale in caso di successo.*/
void	rrb_b(t_stack **l_stack_b)
{
	shift_rotate_reverse(l_stack_b);
}

/* Reverse Rotate r: Esegue la rotazione inversa su entrambi gli stack.
 * Stampa "rrr\n" se entrambi hanno avuto successo. */
void	rrr_b(t_stack **l_stack_a, t_stack **l_stack_b)
{
	if (!*l_stack_a || !*l_stack_b
		|| !(*l_stack_a)->next || !(*l_stack_b)->next)
		return ;
	shift_rotate_reverse(l_stack_a);
	shift_rotate_reverse(l_stack_b);
}
