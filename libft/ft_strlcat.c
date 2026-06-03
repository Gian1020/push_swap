/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:23:19 by gpecelli          #+#    #+#             */
/*   Updated: 2026/06/03 17:23:19 by gpecelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Appends 'src' to 'dst', ensuring it ends with '\0'.
 * 1. Calculates 'dst_len', stopping at the first '\0' or when size is reached.
 * 2. If 'dst_len' == 'size' (dst buffer is already full or not terminated), 
 * returns the sum of size and the length of src.
 * 3. Otherwise, copies 'src' to the end of 'dst' as long as there is space 
 * ( "size - dst_len - 1" ) and adds the '\0'.
 * * Returns the total length of the string that was attempted to be created:
 * (initial dst_len + src_len). */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;

	dst_len = 0;
	src_len = ft_strlen(src);
	while (dst[dst_len] && dst_len < size)
		dst_len++;
	if (dst_len == size)
		return (size + src_len);
	i = 0;
	while (src[i] && (dst_len + i + 1) < size)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
