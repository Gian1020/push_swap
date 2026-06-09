/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecelli <gpecelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:57:38 by gipimpin          #+#    #+#             */
/*   Updated: 2026/06/08 11:22:11 by gpecelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_i_range	*init_i_range(void)
{
	t_i_range	*s_i_range;

	s_i_range = (t_i_range *) malloc (sizeof(t_i_range));
	s_i_range->i = 0;
	s_i_range->range = 0;
	return (s_i_range);
}

/*Analizza la SIZE di A per scegliere un range adeguato.*/
static int	select_range(int size_a)
{
	return (ft_sqrt(size_a));
}

static int	do_rr_or_rb(t_stack **l_stack_a, t_stack **l_stack_b,
		t_i_range	*s_i_range, t_data_bench *data)
{
	if (*l_stack_a && (*l_stack_a)->idx > (s_i_range->i + s_i_range->range))
	{
		rr(l_stack_a, l_stack_b, data);
		return (0);
	}
	else
	{
		rb(l_stack_b, data);
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
	t_i_range	*s_i_range;

	s_i_range = init_i_range();
	s_i_range->i = 0;
	s_i_range->range = select_range(list_size(*l_stack_a));
	while (*l_stack_a)
	{
		if ((*l_stack_a)->idx <= s_i_range->i)
		{
			pb(l_stack_a, l_stack_b, data);
			s_i_range->i++;
		}
		else if ((*l_stack_a)->idx <= (s_i_range->range + s_i_range->i))
		{
			pb(l_stack_a, l_stack_b, data);
			do_rr_or_rb(l_stack_a, l_stack_b, s_i_range, data);
			s_i_range->range++;
		}
		else
			ra(l_stack_a, data);
	}
	while (*l_stack_b)
		push_smart_to_a(l_stack_a, l_stack_b, data);
	free(s_i_range);
}
