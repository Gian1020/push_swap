/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:57:47 by gipimpin          #+#    #+#             */
/*   Updated: 2026/06/07 19:58:21 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Restores the search indexes in case of a partial mismatch.
* Allows backtracking of the main index to avoid skipping
* possible overlapping occurrences of the string 'little'.*/
void	ft_reset(size_t *i, size_t *j)
{
	*i -= *j;
	*j = 0;
}

/* Searches for the first occurrence of 'little' within 'big', 
 * up to the limit 'len'. If 'little' is empty, returns 'big'. 
 * Implements index backtracking in case of a partial mismatch
 * to avoid skipping possible overlapping matches.
 * Returns the start pointer calculated as 'i - j + 1' 
 * (where 'i - j' is the character preceding the match 
 * and '+ 1' is the actual start).*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	l_len;

	if (*little == '\0')
		return ((char *)big);
	l_len = ft_strlen(little);
	if (l_len > len)
		return (NULL);
	i = 0;
	j = 0;
	while (big[i] && i < len)
	{
		if (big[i] == little[j])
		{
			j++;
			if (little[j] == '\0')
				return ((char *)&big[i - j + 1]);
		}
		else if (j > 0)
			ft_reset(&i, &j);
		i++;
	}
	return (NULL);
}
