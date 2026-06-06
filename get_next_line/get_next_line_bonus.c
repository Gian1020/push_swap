#include "get_next_line_bonus.h"

/* Calcola la lunghezza di "str", escludendo '\0'.
 * Ritorna 0 se "str" è NULL. */
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

/* Individua la prima occorrenza di 'c' in's'. 
 * Il carattere '\0' terminatore è considerato parte della stringa.
 * Restituisce il puntatore alla posizione trovata, 
 * oppure NULL se il carattere non è presente. */
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

/* Legge una riga da 'fd' gestendo i residui tramite uno stash statico.
 * Supporta chiamate multiple su FD diversi grazie all'indicizzazione dell'array.
 * Valida il descrittore(read check) e i limiti di BUFFER_SIZE prima dell'I/O.*/
char	*ft_get_next_line(int fd)
{
	char		*line;
	static char	*stash[MAX_FD];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD || read(fd, 0, 0) < 0)
	{
		if (fd >= 0 || fd < MAX_FD || stash[fd])
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

	fd1 = open("print.txt", O_RDONLY);
	fd2 = open("limits.txt", O_RDONLY);
	while (1)
	{
		str1 = ft_get_next_line(fd1);
		if (!str1)
			break ;
		i = ft_strlen(str1);
		write(1, str1, i);
		free(str1);
		str2 = ft_get_next_line(fd2);
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
