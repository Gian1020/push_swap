#include "libft.h"

/* 
 * Determines the buffer size required for the resulting string.
 * Uses a 'long' type to handle the minimum integer value without
 * causing an overflow during conversion to a positive number. Includes in
 * the count the space for a potential negative sign and the zero character. */
static int	count_digits(long n)
{
	int	n_digits;

	n_digits = 0;
	if (n <= 0)
	{
		n *= -1;
		n_digits++;
	}
	while (n > 0)
	{
		n /= 10;
		n_digits++;
	}
	return (n_digits);
}

/* 
 * Converts an integer 'n' into a dynamically allocated string.
 * Implements the use of a 'bank' (long) to safely process INT_MIN.
 * Fills the buffer backwards, extracting individual digits using the
 * op. '%' (base 10) and converting them to the corresponding ASCII character.*/
char	*ft_itoa(int n)
{
	int		n_digits;
	long	bank;
	char	*dst;

	bank = n;
	n_digits = count_digits(bank);
	dst = malloc ((n_digits + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	dst[n_digits] = '\0';
	if (n == 0)
		dst[0] = '0';
	else if (n < 0)
	{
		bank *= -1;
		dst[0] = '-';
	}
	while (bank > 0)
	{
		n_digits--;
		dst[n_digits] = bank % 10 + '0';
		bank /= 10;
	}
	return (dst);
}
