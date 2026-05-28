#include "libft.h"

/* Clears the first 'n' bytes of a memory area. */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
