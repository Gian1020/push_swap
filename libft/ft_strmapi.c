#include "libft.h"

/* Dynamically allocates and returns a new string resulting 
 * from applying the function 'f()' to each character in 's'.
 * The callback 'f()' receives the current index and the character to be mapped.
 * Includes parameter safety checks and ensures proper termination (‘\0’).
 * Returns NULL on error. */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			len;
	char			*dst;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	dst = (char *) malloc ((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	dst[len] = '\0';
	i = 0;
	while (s[i])
	{
		dst[i] = f(i, s[i]);
		i++;
	}
	return (dst);
}
