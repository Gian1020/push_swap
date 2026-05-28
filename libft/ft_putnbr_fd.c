#include "libft.h"

/* Converts and writes 'n' to file descriptor 'fd'.
 * Uses a 'long' type to safely handle the minimum integer value
 * (INT_MIN), preventing overflow during conversion to a positive number.
 * Uses recursion to break down the number, processing the digits through
 * successive divisions and printing them in order using the modulo operator. */
void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd((nb % 10) + '0', fd);
}
