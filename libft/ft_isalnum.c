#include "libft.h"

/* Check if 'c' is a digit or alpha. */
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
