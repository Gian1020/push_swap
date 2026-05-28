#include "libft.h"

/*Check if the character 'c' is present in the string 'set'.*/
static int	is_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/*
 *Removes characters present in 'set' from the beginning and end of 's1'.
 *Uses the helper function 'is_in_set' to check for membership.
 *Calculates the 'start' and 'end' indices to isolate the core.
 *Returns a new string allocated with ft_substr within the identified range.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	return (ft_substr(s1, start, end - start));
}
