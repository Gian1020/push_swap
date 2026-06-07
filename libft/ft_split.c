/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:57:45 by gipimpin          #+#    #+#             */
/*   Updated: 2026/06/07 19:58:18 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Systematically frees the memory allocated up to index 'i'
 * and the main vector. Acts as a rollback mechanism to prevent
 * memory leaks in the event of a malloc failure during string extraction. */
static char	**free_all(char **ris, size_t i)
{
	while (i > 0)
	{
		i--;
		free(ris[i]);
	}
	free(ris);
	return (NULL);
}

/* Analyzes the source string to determine the number of segments (words)
 * separated by the character 'c'. Handles consecutive separators 
 * and empty strings, returning the required size for the pointer array. */
static size_t	ft_countwords(char const *s, char c)
{
	size_t	i;
	size_t	count_c;
	size_t	count_w;

	if (!s)
		return (0);
	i = 0;
	count_w = 0;
	count_c = 0;
	while (s[i])
	{
		if (s[i] != c)
			count_c++;
		else if (s[i] == c && count_c > 0)
		{
			count_c = 0;
			count_w++;
		}
		i++;
	}
	if (count_c > 0)
		count_w++;
	return (count_w);
}

/* Populate the 'ris' vector by extracting each word using 'ft_substr()'.
 * Dynamically identify the start and end of each segment, and in the event of 
 * a memory allocation error, terminate the process by calling 'free_all()'. */
static char	**ft_fill_array(char const *s, char c, char **ris)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		ris[j] = ft_substr(s, start, i - start);
		if (!ris[j])
			return (free_all(ris, j));
		j++;
	}
	ris[j] = NULL;
	return (ris);
}

/* Main function that coordinates the decomposition of the string 's'.
 * Allocates the pointer array (including space for the '\0')
 * and delegates the filling to the ft_fill_array logic. */
char	**ft_split(char const *s, char c)
{
	char	**ris;

	if (!s)
		return (NULL);
	ris = (char **) malloc ((ft_countwords(s, c) + 1) * sizeof(char *));
	if (!ris)
		return (NULL);
	return (ft_fill_array(s, c, ris));
}
