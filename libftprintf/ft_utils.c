/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 18:29:51 by gipimpin          #+#    #+#             */
/*   Updated: 2026/05/25 18:29:51 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
