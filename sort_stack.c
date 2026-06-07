/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 19:33:29 by marvin            #+#    #+#             */
/*   Updated: 2026/06/06 19:33:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort_by_size(t_stack **l_stack_a, t_stack **l_stack_b,
		int size, t_data_bench *data)
{
	if (!l_stack_a || size < 2 || is_sorted(*l_stack_a))
		return ;
	if (size == 2)
		sa(l_stack_a, data);
	else if (size == 3)
		sort_three(l_stack_a, data);
	else if (size <= 5)
		sort_five(l_stack_a, l_stack_b, data);
	list_clear(l_stack_b);
}

/* Coordina la strategia di ordinamento in base al numero di elementi.
 * Verifica se lo stack è già ordinato o troppo piccolo, quindi delega 
 * l'esecuzione ad algoritmi specializzati per gestire i vari casi. */
void	sort_stack(t_stack **l_stack_a, t_algo *algo)
{
	t_data_bench	*data;
	t_stack			*l_stack_b;
	int				size;
	
	l_stack_b = NULL;
	size = list_size(*l_stack_a);
	data = init_bench(compute_disorder(*l_stack_a));
	if (size <= 5)
	{
		sort_by_size(l_stack_a, &l_stack_b, size, data);
		if (algo->bench == 1)
			bench_writer(data);
		finish_prog(l_stack_a, &l_stack_b, data, algo);
	}
	else if (algo->simple == 1 && size > 5)
	{
		sort_max_min_extraction(l_stack_a, &l_stack_b, data);
		printf("simple");
	}
	else if (algo->medium == 1 && size > 5 )
	{
		chunk_sort(l_stack_a, &l_stack_b, data);
		printf("medium");
	}	
	else if(algo->complex == 1 && size > 5)
	{
		turk_sort(l_stack_a, &l_stack_b, data);
		printf("complex");
	}
		
	else
	{
		if (data->disorder < 0.2)
			sort_max_min_extraction(l_stack_a, &l_stack_b, data);
		else if (data->disorder >= 0.2 && data->disorder < 0.5)
			chunk_sort(l_stack_a, &l_stack_b, data);
		else if (data->disorder >= 0.5)
			turk_sort(l_stack_a, &l_stack_b, data);
		printf("adaptive");
	}
	if (algo->bench == 1)
		bench_writer(data);
	finish_prog(l_stack_a, &l_stack_b, data, algo);
}
