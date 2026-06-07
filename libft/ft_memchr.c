/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:57:43 by gipimpin          #+#    #+#             */
/*   Updated: 2026/06/07 19:58:29 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Performs a linear scan of 'n' bytes in the memory block 's'
 * to locate the first occurrence of the character 'c'. Uses
 * casting to 'unsigned char' to ensure an accurate binary comparison.
 * Returns the address of the found location or NULL.
 * */
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*src;

	i = 0;
	src = (unsigned char *)s;
	while (i < n)
	{
		if (src[i] == (unsigned char)c)
			return ((void *)&src[i]);
		i++;
	}
	return (0);
}
