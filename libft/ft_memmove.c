/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:57:43 by gipimpin          #+#    #+#             */
/*   Updated: 2026/06/07 19:58:16 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Copies the bytes physically, choosing the direction (forward or backward).
* This flexibility prevents data loss: if the memory areas
* overlap, changing direction prevents the source bytes from being overwritten
* before they have actually been moved.*/
static void	ft_insert(unsigned char *dst, unsigned char *src,
				size_t n, int flag)
{
	size_t	i;

	if (flag)
	{
		i = 0;
		while (i < n)
		{
			dst[i] = src[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			n--;
			dst[n] = src[n];
		}
	}
}

/*Copy 'n' bytes from 'src' to 'dst', safely handling overlaps.
* Determine the direction of movement by comparing the addresses ( 's' > 'd' ):
* - If the source is after the destination, copy forward.
* - If the source is before the destination, copy backward starting 
* from the end so as not to "overwrite" the original data during the move.*/
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			flag;
	unsigned char	*s;
	unsigned char	*d;

	if (!dst && !src)
		return (0);
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	flag = s > d;
	ft_insert(d, s, n, flag);
	return (dst);
}
