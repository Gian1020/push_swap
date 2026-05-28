/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xX_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 18:29:51 by gipimpin          #+#    #+#             */
/*   Updated: 2026/05/25 18:30:21 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/* Inserisce il prefisso negli esadecimali: ("0x" o "0X")
 * is_upper determina se il carattere 'x' è maiuscolo */
static void	insert_prefix(char *prefix, int is_up)
{
	prefix[0] = '0';
	if (is_up)
		prefix[1] = 'X';
	else
		prefix[1] = 'x';
}

/* Gestisce lo specificatore '%x' (esadecimale minuscolo).
 * 1. Calcola i parametri di stampa  via check_flags_hex.
 * 2. Passa il valore n castato a 'unsigned long long' per uniformità di calcolo.
 * 3. Affida la stampa fisica al motore output_hex. */
void	print_x_low(t_flags flag, unsigned int n, int *byte)
{
	t_print_data	data;

	data = check_flags_hex(flag, n, 0);
	output_hex(flag, data, (unsigned long long)n, byte);
}

/* Gestisce lo specificatore '%X' (esadecimale maiuscolo).
 * 1. Uguale %x, ma il flag 'is_up' a 1 per il prefisso e il case dei digit.
 * 2. La logica di output_hex userà BASE_16_UP se data.is_upper_hex è attivo. */
void	print_x_up(t_flags flag, unsigned int n, int *byte)
{
	t_print_data	data;

	data = check_flags_hex(flag, n, 1);
	output_hex(flag, data, (unsigned long long)n, byte);
}

t_print_data	check_flags_hex(t_flags flag, unsigned long long n, int is_up)
{
	t_print_data	data;

	data = init_struct_data();
	data.n_digits = count_digits_base(n, 16);
	if (flag.dot && flag.prec == 0 && n == 0)
		data.n_digits = 0;
	data.count_zero = 0;
	if (flag.dot && flag.prec > data.n_digits)
		data.count_zero = flag.prec - data.n_digits;
	data.tot_len = data.n_digits + data.count_zero;
	if (is_up)
		data.is_upper_hex = 1;
	if ((flag.hash && n != 0) || flag.spec == 'p')
	{
		insert_prefix(data.prefix, is_up);
		data.tot_len += 2;
	}
	if (flag.width > data.tot_len)
		data.padding = flag.width - data.tot_len;
	return (data);
}
