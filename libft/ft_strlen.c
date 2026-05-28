#include "libft.h"

/* Returns length of 'str' (no '\0'). */
size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
