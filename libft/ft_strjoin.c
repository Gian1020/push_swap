/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:23:19 by gpecelli          #+#    #+#             */
/*   Updated: 2026/06/03 17:23:19 by gpecelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Allocates and returns a string resulting from the concatenation of 's1' + 's2'
 *Handles NULL parameters by duplicating them or returning NULL.
 *Calculates lengths and allocates memory using 'ft_calloc()'.
 *Uses ft_strlcat to safely concatenate strings.*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*dst;	

	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		return (ft_strdup(s1));
	if (!s1)
		return (ft_strdup(s2));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dst = (char *) ft_calloc ((s1_len + s2_len + 1), sizeof(char));
	if (!dst)
		return (NULL);
	ft_strlcat(dst, s1, s1_len + s2_len + 1);
	ft_strlcat(dst, s2, s1_len + s2_len + 1);
	return (dst);
}
