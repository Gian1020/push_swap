/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 12:43:28 by gipimpin          #+#    #+#             */
/*   Updated: 2026/05/22 19:18:29 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Allocates the necessary memory to join 'buffer' and 'stash'. 
 * Note: Returns NULL in case of allocation failure and frees 'stash'. */
static char	*ft_join_allocate(char *buffer, char *stash)
{
	size_t	len;
	char	*new_stash;

	if (!buffer)
		return (NULL);
	len = ft_strlen(buffer) + ft_strlen(stash) + 1;
	new_stash = (char *) malloc ((len) * sizeof(char));
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	return (new_stash);
}

/* Concatenates 'buffer' and 'stash' into a new string and frees the memory 
 * of the old 'stash'. Returns a pointer to the newly allocated area. */
static char	*ft_join_and_free(char *buffer, char *stash)
{
	size_t	i;
	size_t	j;
	char	*new_stash;

	new_stash = ft_join_allocate(buffer, stash);
	if (!new_stash)
		return (NULL);
	i = 0;
	if (stash)
	{
		while (stash[i])
		{
			new_stash[i] = stash[i];
			i++;
		}
	}
	j = 0;
	while (buffer[j])
	{
		new_stash[i + j] = buffer[j];
		j++;
	}
	new_stash[i + j] = '\0';
	free(stash);
	return (new_stash);
}

/* Reads from the file descriptor until a newline ('\n') 
 * is found or EOF is reached. 
 * Accumulates the read data into 'stash' by calling ft_join_and_free. */
char	*read_and_allocates(int fd, char *stash)
{
	int			bytes_read;
	char		*buffer;

	buffer = (char *) malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			if (stash)
				free(stash);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = ft_join_and_free(buffer, stash);
	}
	free(buffer);
	return (stash);
}

/* Extracts and allocates a single line from 'stash' 
 * (up to the first '\n' inclusive). 
 * Returns NULL if the stash is empty or not allocated. */
char	*ft_extract_line(char *stash)
{
	int		i;
	int		len;
	char	*ris;

	if (!stash || stash[0] == '\0')
		return (NULL);
	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	ris = (char *) malloc ((len + 1) * sizeof(char));
	if (!ris)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ris[i] = stash[i];
		i++;
	}
	ris[i] = '\0';
	return (ris);
}

/* Removes the already extracted line from 'stash'
 * and reallocates memory for the 
 * remaining characters. P.S. Parameter 'i' is used for indexing. */
char	*ft_clean_stash(char *stash, int i)
{
	int		j;
	char	*new_stash;

	j = 0;
	while (stash[j] && stash[j] != '\n')
		j++;
	if (!stash[j] || !stash[j + 1])
	{
		free(stash);
		return (NULL);
	}
	new_stash = (char *) malloc ((ft_strlen(stash) - j) * sizeof(char));
	if (!new_stash)
		return (NULL);
	j++;
	while (stash[j])
	{
		new_stash[i] = stash[j];
		i++;
		j++;
	}
	new_stash[i] = '\0';
	free(stash);
	return (new_stash);
}
