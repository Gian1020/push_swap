/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:57:47 by gipimpin          #+#    #+#             */
/*   Updated: 2026/06/07 19:58:21 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Finds the last occurrence of 'c' (to unsigned char) in the 
 * string 's'. The '\0' is considered part of the 
 * string. Returns a pointer to the found position, or NULL 
 * if the character is not present. */
char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if ((unsigned char)s[len] == (unsigned char)c)
		return ((char *)&s[len]);
	while (len > 0)
	{
		len--;
		if ((unsigned char)s[len] == (unsigned char)c)
			return ((char *)&s[len]);
	}
	return (NULL);
}
