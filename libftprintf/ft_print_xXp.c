/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xXp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 18:29:51 by gipimpin          #+#    #+#             */
/*   Updated: 2026/05/25 18:29:51 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Stampa N in BASE_16_LOW tramite "putnbr_base_count" */
void	print_x_low(unsigned int n, int *byte)
{
	putnbr_base_count((unsigned long long)n, BASE_16_LOW, byte);
}

/* Stampa N in BASE_16_UP tramite "putnbr_base_count" */
void	print_x_up(unsigned int n, int *byte)
{
	putnbr_base_count((unsigned long long)n, BASE_16_UP, byte);
}

/* Trasforma il pointer (l'indirizzo di memoria) in un usigned long long,
 * per essere sicuri di contenerlo tutto, stampa "0x" literal notation. 
 * Stampa l indirizzo di memoria in BASE_16_LOW tramite "putnbr_base_count" 
 * Se il pointer è NULL chiama "print_s" dandogli valore nill.*/
void	print_p(void *p, int *byte)
{
	unsigned long long	ptr_val;

	if (!p)
	{
		print_s("(nil)", byte);
		return ;
	}
	ptr_val = (unsigned long long) p;
	putchar_count('0', byte);
	putchar_count('x', byte);
	putnbr_base_count(ptr_val, BASE_16_LOW, byte);
}
