/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 18:29:51 by gipimpin          #+#    #+#             */
/*   Updated: 2026/05/25 18:30:21 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/* Return 1 se l'argomento è uno specificatore*/
int	isspecifier(int c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}

/* Stampa il carattere e aumenta count
 * In caso d'errore, setta count a -1 */
void	putchar_count(unsigned char c, int *byte)
{
	if (*byte == -1)
		return ;
	if (write(1, &c, 1) == -1)
		*byte = -1;
	else
		(*byte)++;
}

/* Stampa i primi 'n' caratteri della stringa 'str'
 * Utile per gestire la precisione e la larghezza */
void	putnstr_count(char *str, int n, int *byte)
{
	int	i;

	if (!str || n <= 0)
		return ;
	i = 0;
	while (str[i] && i < n)
	{
		putchar_count((unsigned char)str[i], byte);
		i++;
	}
}

/* Stampa 'c' per 'n' volte
 * Fondamentale per la gestione del padding (spazio o zeri) */
void	putnchar_count(unsigned char c, int n, int *byte)
{
	if (n <= 0)
		return ;
	while (n > 0)
	{
		putchar_count(c, byte);
		n--;
	}
}
