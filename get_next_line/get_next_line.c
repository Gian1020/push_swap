/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecelli <gpecelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:59:14 by gipimpin          #+#    #+#             */
/*   Updated: 2026/06/08 16:39:00 by gpecelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// /* Calculates the length of "str", excluding '\0'.
//  * Returns 0 if "str" is NULL. */
// size_t	ft_strlen2(char *str)
// {
// 	size_t	i;

// 	if (!str)
// 		return (0);
// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// /* Locates the first occurrence of 'c' in 's'. 
//  * The terminating '\0' character is considered part of the string.
//  * Returns a pointer to the located character, 
//  * or NULL if the character is not found. */
// char	*ft_strchr2(const char *s, int c)
// {
// 	size_t	i;

// 	if (!s)
// 		return (NULL);
// 	i = 0;
// 	while (s[i])
// 	{
// 		if ((unsigned char)s[i] == (unsigned char)c)
// 			return ((char *)&s[i]);
// 		i++;
// 	}
// 	if ((unsigned char) c == '\0')
// 		return ((char *)&s[i]);
// 	return (NULL);
// }

/* Reads a line from 'fd', managing leftovers via a static stash.
 * Supports multiple calls across different FDs thanks to array indexing.
 * Validates the file descriptor (read check) and 
 * BUFFER_SIZE limits before I/O. */
char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (stash)
		{
			free(stash);
			stash = NULL;
		}
		return (NULL);
	}
	stash = read_and_allocates(fd, stash);
	line = ft_extract_line(stash);
	if (stash)
		stash = ft_clean_stash(stash, 0);
	return (line);
}
