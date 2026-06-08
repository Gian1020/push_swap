/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecelli <gpecelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:57:49 by gipimpin          #+#    #+#             */
/*   Updated: 2026/06/08 17:01:19 by gpecelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/* Sposta il primo elemento dello stack e il secondo elemento.
 * Aggiorna i puntatori 'first' e 'last' per mantenere
 * la circolarità della lista doppiamente concatenata e
 * scrive l'operazione se 'op_name' è fornito.
 * Ritorna 1 in caso di successo, 0 se lo stack ha meno di
 * 2 elementi. */
static void	swap(t_stack **l_stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!l_stack || !*l_stack || !(*l_stack)->next)
		return ;
	first = *l_stack;
	second = first->next;
	if (second->next)
		second->next->prev = first;
	first->prev = second;
	first->next = second->next;
	second->next = first;
	second->prev = NULL;
	*l_stack = second;
}

/* Swap A: sposta il primo elemento di a con il secondo.
 * Stampa "sa\n" nel terminale in caso di successo. */
void	sa_b(t_stack **l_stack_a)
{
	swap(l_stack_a);
}

/* Swap B: sposta il primo elemento di a con il secondo.
 * Stampa "sb\n" nel terminale in caso di successo. */
void	sb_b(t_stack **l_stack_b)
{
	swap(l_stack_b);
}

/* Swap simultaneo sia dello stack A che lo stack B. .
 * Stampa "ss\n" nel terminale se entrambe vanno a buon fine*/
void	ss_b(t_stack **l_stack_a, t_stack **l_stack_b)
{
	if (!*l_stack_a || !*l_stack_b
		|| !(*l_stack_a)->next || !(*l_stack_b)->next)
		return ;
	swap(l_stack_a);
	swap(l_stack_b);
	return ;
}
