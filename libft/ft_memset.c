#include "libft.h"

/*
 * Fills the first 'n' bytes of the memory area 's' with the value 'c'.
 * Converts 'c' to 'unsigned char' to operate on raw memory
 * and returns the original pointer 's' to allow for concatenation.*/
void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *) s;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
