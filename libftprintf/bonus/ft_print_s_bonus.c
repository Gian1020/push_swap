/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 18:29:50 by gipimpin          #+#    #+#             */
/*   Updated: 2026/05/25 18:30:21 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/* Gestisce il caso in cuila stringa passata a %s è NULL
 * Se la precisione è attiva e inferiore a 6, str = ""
 * altrimenti sarà "(null)" */
static char	*handle_str_null(t_flags flag)
{
	if (flag.dot && flag.prec < 6)
		return ("");
	return ("(null)");
}

/* Gestisce lo specificatore %s
 * Calcola la lunghezza da stampare in base alla precisione (.dot)
 * Applica il padding della width e l'allineamento a sinistra (-) */
void	print_s(t_flags flag, char *str, int *byte)
{
	int	i;
	int	padding;

	if (!str)
		str = handle_str_null(flag);
	i = 0;
	while (str[i])
		i++;
	if (flag.dot && flag.prec < i)
		i = flag.prec;
	padding = 0;
	if (flag.width > i)
		padding = flag.width - i;
	if (flag.minus)
	{
		putnstr_count(str, i, byte);
		putnchar_count(' ', padding, byte);
	}
	else
	{
		putnchar_count(' ', padding, byte);
		putnstr_count(str, i, byte);
	}
}
