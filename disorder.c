/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:37:33 by gipimpin          #+#    #+#             */
/*   Updated: 2026/05/29 18:11:03 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_disorder(float f)
{
	char	c;
	int	i;

	i = 0;
	write(1, "\n", 1);
	while (i < 4)
	{
		f *= 10;
		c = (int)f % 10 + '0';
		write(1, &c, 1);
		if (i == 1)
			write(1, ".", 1);
		i++;
	}
	write(1, "%", 1);
	write(1, "\n", 1);
}


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
	printf("dis.c: %f\n", mistakes / total_pairs);
	fflush(stdout);
	return (mistakes / total_pairs);
}
