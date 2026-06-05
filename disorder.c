/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecelli <gpecelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:37:33 by gipimpin          #+#    #+#             */
/*   Updated: 2026/06/04 15:42:45 by gpecelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_disorder(float f)
{
	char	c;
	int		i;

	i = 0;
	if (f == 1.0)
	{
		c = (int)f % 10 + '0';
		write(2, &c, 1);
	}
	while (i < 4)
	{
		f *= 10;
		c = (int)f % 10 + '0';
		write(2, &c, 1);
		if (i == 1)
			write(2, ".", 1);
		i++;
	}
	write(2, "%", 1);
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
	return (mistakes / total_pairs);
}
