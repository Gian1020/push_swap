#include "libft.h"

/* Copies 'n' bytes from 'src' to 'dst' using a linear binary scan.
 * Protects against NULL input and uses casting to 'unsigned char' to
 * ensure data integrity. Does not handle overlapping areas.*/
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (!dst && !src)
		return (0);
	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
