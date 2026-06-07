/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:57:39 by gipimpin          #+#    #+#             */
/*   Updated: 2026/06/07 19:58:23 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
 * Converts a string to int.
 * 1. Skips the characters specified by isspace() (ASCII 9–13 and 32).
 * 2. Handles a single optional sign (+ or -).
 * 3. Converts the numeric sequence to an integer value using an accumulator.
 * 4. Returns the result multiplied by the sign.
 */
int	ft_atoi(char const *str)
{
	int	i;
	int	sign;
	int	n;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * sign);
}
