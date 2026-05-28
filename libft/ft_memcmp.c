#include "libft.h"

/* Performs a binary comparison between the first 'n' bytes of 's1' and 's2'.
 * Treats the data as 'unsigned char' to return the difference
 * between their corresponding ASCII values for the first differing bytes
 * or NULL if they are identical. */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	i = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}
