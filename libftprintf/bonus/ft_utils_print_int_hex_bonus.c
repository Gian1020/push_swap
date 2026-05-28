/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_print_int_hex_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 18:29:51 by gipimpin          #+#    #+#             */
/*   Updated: 2026/05/25 18:30:21 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/* Motore di output per gli specificatori numerici (d, i, u).
 * Coordina la stampa seguendo la gerarchia standard di printf:
 * 1. Padding sinistro (spazi)
 * 2. Segno (se previsto)
 * 3. Zero-padding (flag '0' senza precisione)
 * 4. Precisione (zeri richiesti)
 * 5. Stampa il numero in base 10
 * 6. Padding destro (flag '-') */
void	output_nbr(
		t_flags flag,
		t_print_data data,
		unsigned long n,
		int *byte)
{
	if (!flag.minus && !(flag.zero && !flag.dot))
		putnchar_count(' ', data.padding, byte);
	if (data.prefix[0])
		putchar_count(data.prefix[0], byte);
	if (!flag.minus && !flag.dot && flag.zero)
		putnchar_count('0', data.padding, byte);
	putnchar_count('0', data.count_zero, byte);
	if (data.n_digits > 0)
		putnbr_base_count(n, BASE_10, byte);
	if (flag.minus)
		putnchar_count(' ', data.padding, byte);
}

/* Motore di output per gli specificatori esadecimali.
 * Coordina la stampa seguendo la gerarchia standard di printf:
 * 1. Padding sinistro (spazi)
 * 2. prefix ("0x" o "0X" se previsto)
 * 3. Zero-padding (flag '0' senza precisione)
 * 4. Precisione (zeri richiesti)
 * 5. Stampa il numero in base 16
 * 6. Padding destro (flag '-') */
void	output_hex(
	t_flags flag,
	t_print_data data,
	unsigned long long n,
	int *byte)
{
	if (!flag.minus && !(flag.zero && !flag.dot))
		putnchar_count(' ', data.padding, byte);
	if (data.prefix[0])
		putnstr_count(data.prefix, 2, byte);
	if (!flag.minus && !flag.dot && flag.zero)
		putnchar_count('0', data.padding, byte);
	putnchar_count('0', data.count_zero, byte);
	if (data.n_digits > 0 && data.is_upper_hex)
		putnbr_base_count(n, BASE_16_UP, byte);
	else if (data.n_digits > 0 && !data.is_upper_hex)
		putnbr_base_count(n, BASE_16_LOW, byte);
	if (flag.minus)
		putnchar_count(' ', data.padding, byte);
}
