/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecelli <gpecelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:57:49 by gipimpin          #+#    #+#             */
/*   Updated: 2026/06/08 15:02:44 by gpecelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Trasferisce il nodo in cima a 'l_stack_take' in cima a 'l_stack_push'.
 * Gestisce l'aggiornamento dei puntatori 'next' e 'prev' per mantenere
 * l'integrità della lista doppiamente concatenata. 
 * Ritorna 1 in caso di successo, 0 se lo stack sorgente è vuoto.*/
static int	push(t_stack **l_stack_take, t_stack **l_stack_push)
{
	t_stack	*stack_to_push;

	if (!l_stack_take || !*l_stack_take || !l_stack_push)
		return (0);
	stack_to_push = *l_stack_take;
	if (stack_to_push->next)
	{
		stack_to_push->next->prev = NULL;
		*l_stack_take = stack_to_push->next;
		stack_to_push->next = NULL;
	}
	else
		*l_stack_take = NULL;
	if (!*l_stack_push)
		*l_stack_push = stack_to_push;
	else
	{
		(*l_stack_push)->prev = stack_to_push;
		stack_to_push->next = *l_stack_push;
		*l_stack_push = stack_to_push;
	}
	return (1);
}

/* Push A: Preleva il primo elemento da B e lo inserisce in cima ad A.
 * Scrive "pa\n" nel terminale in caso di successo. */
int	pa(t_stack **l_stack_a, t_stack **l_stack_b,
		t_data_bench *data)
{
	int	flag;

	flag = push(l_stack_b, l_stack_a);
	if (flag)
		write(1, "pa\n", 3);
	if(data)
	{
		data->pa += 1;
		data->total += 1;
	}
	return (flag);
}

/* Push B: Preleva il primo elemento da A e lo inserisce in cima ad B.
 * Scrive "pb\n" nel terminale in caso di successo.*/
int	pb(t_stack **l_stack_a, t_stack **l_stack_b,
		t_data_bench *data)
{
	int	flag;

	flag = push(l_stack_a, l_stack_b);
	if (flag)
		write(1, "pb\n", 3);
	if (data)
	{
		data->pb += 1;
		data->total += 1;
	}
	return (flag);
}
