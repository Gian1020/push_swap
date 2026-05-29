/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_nbr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 18:29:51 by gipimpin          #+#    #+#             */
/*   Updated: 2026/05/25 18:30:21 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/* Return 1 se l'argomento è una cifra*/
int	isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/* Calcola il valore assoluto di un numero 'long'
 * restituendolo come 'unsigned long'.
 * * NOTE TECNICHE:
 * 1. Il ritorno 'unsigned long' è necessario per ospitare il valore positivo 
 * di LONG_MIN (o INT_MIN), che eccederebbe il limite dei tipi signed.
 * 2. L operazione '-(unsigned long)n' previene comportamenti indefiniti:
 * castando a unsigned PRIMA della negazione, sfruttiamo l'aritmetica 
 * modulare (complemento a due) per ottenere il valore assoluto corretto 
 * senza rischiare l'overflow tipico dei numeri signed.
 */
unsigned long	abs_val(long n)
{
	if (n < 0)
		return (-(unsigned long)n);
	return ((unsigned long)n);
}

/* Calcola il numero di cifre di un valore decimale.
 * Riceve un unsigned long long per gestire correttamente il valore assoluto 
 * di qualsiasi intero (incluso INT_MIN) e i numeri unsigned.
 * Fondamentale per determinare padding e precisione.*/
int	count_digits_base(unsigned long long n, int base_len)
{
	int	n_digits;

	if (n == 0)
		return (1);
	n_digits = 0;
	while (n > 0)
	{
		n_digits++;
		n /= base_len;
	}
	return (n_digits);
}

/* Stampa ricorsivamente un numero in una base specifica (es. 10 o 16).
 * L'uso di unsigned long previene overflow e permette di gestire 
 * sia grandi interi che indirizzi di memoria (puntatori).
 * Incrementa il contatore globale per ogni carattere stampato. */
void	putnbr_base_count(
		unsigned long long n,
		const char *base,
		int *byte)
{
	unsigned long	base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	if (n >= base_len)
		putnbr_base_count(n / base_len, base, byte);
	putchar_count(base[n % base_len], byte);
}
