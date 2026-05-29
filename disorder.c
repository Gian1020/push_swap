/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:37:33 by gipimpin          #+#    #+#             */
/*   Updated: 2026/05/29 17:50:32 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

float	compute_disorder(t_stack *a)
{
	float	mistakes;
	float	total_pairs;
	t_stack	*next;

	mistakes = 0;
	total_pairs = 0;
	while (a->next != NULL)
	{
		next = a->next;
		while (next != NULL)
		{
			total_pairs++;
			if (a->idx > next->idx)
				mistakes++;
			next = next->next;
		}
		a = a->next;
	}
	return (mistakes / total_pairs);
}
