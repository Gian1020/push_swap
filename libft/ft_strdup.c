#include "libft.h"

/* Creates an independent copy of the string 's' using dynamic allocation.
 * Calculates the required size, including the '\0'.
 * Protects against counter overflow and handles malloc failures.
 * Copies the data byte by byte and returns a pointer to the new memory. */
char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dst;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	if (i == SIZE_MAX)
		return (NULL);
	dst = (char *) malloc ((i + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
