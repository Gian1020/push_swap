/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_shift_rotate_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecelli <gpecelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:57:54 by gipimpin          #+#    #+#             */
/*   Updated: 2026/06/08 17:10:09 by gpecelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/* Rotazione verso l'alto
 * Sposta il primo elemento dello stack in ultima posizione 
 * Aggiorna i puntatori 'first' e 'last' per mantenere la circolarità
 * della lista doppiamente concatenata e scrive l'operazione se
 * 'op_name' è fornito.
 * Ritorna 1 in caso di successo, 0 se lo stack ha meno di 2 elementi.*/
static void	shift_rotate(t_stack **l_stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!l_stack || !*l_stack || !(*l_stack)->next)
		return ;
	first = *l_stack;
	last = list_last(*l_stack);
	*l_stack = first->next;
	first->next->prev = NULL;
	first->prev = last;
	first->next = NULL;
	last->next = first;
}

/* Rotate A: Prende il primo elemento di A e lo sposta all'ultima posizione.
 * Stampa "ra\n" nel terminale in caso di successo.*/
void	ra_b(t_stack **l_stack_a)
{
	shift_rotate(l_stack_a);
}

/* Rotate B: Prende il primo elemento di B e lo sposta all'ultima posizione.
 * Stampa "rb\n" nel terminale in caso di successo.*/
void	rb_b(t_stack **l_stack_b)
{
	shift_rotate(l_stack_b);
}

/* Rotate simultaneamente sia lo stack A che lo stack B.
 * Stampa "rr\n" nel terminale se entrambe vanno a buon fine.*/
void	rr_b(t_stack **l_stack_a, t_stack **l_stack_b)
{
	if (!*l_stack_a || !*l_stack_b
		|| !(*l_stack_a)->next || !(*l_stack_b)->next)
		return ;
	shift_rotate(l_stack_a);
	shift_rotate(l_stack_b);
}
