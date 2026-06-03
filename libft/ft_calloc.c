/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:23:16 by gpecelli          #+#    #+#             */
/*   Updated: 2026/06/03 17:23:16 by gpecelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * Allocates memory for 'num' elements of 'size', initializing them to zero.
 * Protects against overflow by checking whether the product exceeds 'SIZE_MAX'.
 * Uses ft_bzero() to zero out the area and remove any residual data.
 * Returns a pointer to the allocated memory or NULL on failure.
 */
void	*ft_calloc(size_t num, size_t size)
{
	void	*dst;

	if (num != 0 && size > SIZE_MAX / num)
		return (NULL);
	dst = (void *)malloc (size * num);
	if (!dst)
		return (NULL);
	ft_bzero(dst, num * size);
	return (dst);
}
