/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecelli <gpecelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:37:33 by gipimpin          #+#    #+#             */
/*   Updated: 2026/06/07 19:57:38 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Prints the computed disorder percentage to the standard error output.
** Multiplies the float to correctly format the decimal output.
**
** @param f The disorder ratio represented as a float.
*/
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

/*
** Computes the disorder ratio of the stack based on misplaced pairs.
** Iterates through the stack comparing each node's index to subsequent ones.
**
** @param a Pointer to the first node of the stack.
** @return A float representing the ratio of misplaced pairs to total pairs.
*/
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
	if (total_pairs == 0)
		return (0.0);
	return (mistakes / total_pairs);
}
