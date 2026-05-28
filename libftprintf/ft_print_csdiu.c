/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_csdiu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 18:29:51 by gipimpin          #+#    #+#             */
/*   Updated: 2026/05/25 18:29:51 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Stampa il carattere chimamndo "putchar_count" */
void	print_c(int c, int *byte)
{
	putchar_count((unsigned char)c, byte);
}

/* Stampa la stringa chiamando "putnstr_count" .
 * se il pointer è NULL str = "(null)" */
void	print_s(char *str, int *byte)
{
	int	i;

	if (!str)
		str = "(null)";
	i = 0;
	while (str[i])
		i++;
	putnstr_count(str, i, byte);
}

/* Se il n è negativo stampa '-'.
 * Poi chiama "putnbr_base_count" per stampare INT */
void	print_di(int n, int *byte)
{
	unsigned long	u_nbr;

	if (n < 0)
		putchar_count('-', byte);
	u_nbr = abs_val(n);
	putnbr_base_count(u_nbr, BASE_10, byte);
}

/* Stampa l'unsigned int passato tramite "putnbr_base_count" */
void	print_u(unsigned int n, int *byte)
{
	putnbr_base_count((unsigned long)n, BASE_10, byte);
}
