/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 18:29:50 by gipimpin          #+#    #+#             */
/*   Updated: 2026/05/25 18:30:20 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/* Gestisce lo specificatore '%c'
 * Applica la larghezza (width) minima
 * e l allineamento a sinistra se c'è il flag '-'*/
void	print_c(t_flags flag, int c, int *byte)
{
	int	padding;

	padding = 0;
	if (flag.width > 1)
		padding = flag.width - 1;
	if (flag.minus)
	{
		putchar_count((unsigned char)c, byte);
		putnchar_count(' ', padding, byte);
	}
	else
	{
		putnchar_count(' ', padding, byte);
		putchar_count((unsigned char)c, byte);
	}
}
