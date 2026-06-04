#include "push_swap.h"

int ft_abs(int n)
{
    if (n < 0)
        return (-n);
    return (n);
}

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while ((i * i) < nb + 1)
	{
		if ((i * i) == nb)
			return (i);
		i++;
	}
	return (0);
}