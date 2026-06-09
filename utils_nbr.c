/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:10:45 by marvin            #+#    #+#             */
/*   Updated: 2026/06/07 19:57:55 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Returns the absolute value of a given integer.
**
** @param n The integer to convert.
** @return The positive absolute value of n.
*/
int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

/*
** Returns the integer square root of a given number.
** Used primarily for chunk sizing in algorithms.
**
** @param nb The integer to find the square root of.
** @return The truncated integer square root of nb.
*/
int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0)
		return (0);
	i = 1;
	while (i <= nb / i)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (i - 1);
}
