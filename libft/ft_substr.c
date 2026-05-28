#include "libft.h"

/*
* Extracts a substring from 's' starting at 'start' for a maximum of 'len' bytes
* If 'start' exceeds the length of the source,
* it returns an allocated empty string.
* It resizes 'len' if the request extends beyond the end of the string 
* and ensures it ends with a null byte.
* It returns NULL only if malloc fails.*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*dst;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	dst = (char *) malloc (sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len && s[start])
	{
		dst[i] = s[start];
		i++;
		start++;
	}
	dst[i] = '\0';
	return (dst);
}
