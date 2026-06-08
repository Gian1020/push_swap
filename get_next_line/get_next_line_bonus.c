/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 12:43:28 by gipimpin          #+#    #+#             */
/*   Updated: 2026/05/25 16:59:30 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* Calculates the length of "str", excluding '\0'.
 * Returns 0 if "str" is NULL. */
size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

/* Locates the first occurrence of 'c' in 's'. 
 * The terminating '\0' character is considered part of the string.
 * Returns a pointer to the located character, 
 * or NULL if the character is not found. */
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char) c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

/* Reads a line from 'fd', managing leftovers via a static stash.
 * Supports multiple calls across different FDs thanks to array indexing.
 * Validates the file descriptor (read check)
 * and BUFFER_SIZE limits before I/O. */
char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[MAX_FD];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
	{
		if ((fd >= 0 && fd < MAX_FD) || stash[fd])
		{
			free(stash[fd]);
			stash[fd] = NULL;
		}
		return (NULL);
	}
	stash[fd] = read_and_allocates(fd, stash[fd]);
	line = ft_extract_line(stash[fd]);
	if (stash[fd])
		stash[fd] = ft_clean_stash(stash[fd], 0);
	return (line);
}
/*
int	main(void)
{
	int		i;
	int		fd1;
	int		fd2;
	char	*str1;
	char	*str2;

	fd1 = open("printf.txt", O_RDONLY);
	fd2 = open("limits.txt", O_RDONLY);
	while (1)
	{
		str1 = get_next_line(fd1);
		if (!str1)
			break ;
		i = ft_strlen(str1);
		write(1, str1, i);
		free(str1);
		str2 = get_next_line(fd2);
		if (!str2)
			break;
		i = ft_strlen(str2);
		write(1, str2, i);
		free(str2);
	}
	close(fd1);
	close(fd2);
	return (0);
}*/
