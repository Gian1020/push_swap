/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_diu_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 18:29:50 by gipimpin          #+#    #+#             */
/*   Updated: 2026/05/25 18:30:20 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/* Coordina la stampa dei specificatori (%d e %i)
 * 1) Calcola i parametri necessari e li inserisce nella struct
 * 2) Affida la stampa a output_nbr */
void	print_di(t_flags flag, int n, int *byte)
{
	t_print_data	data;
	unsigned long	u_nbr;

	u_nbr = abs_val(n);
	data = check_flags_nbr(flag, (long)n, 1);
	output_nbr(flag, data, u_nbr, byte);
}

/* Coordina la stampa dello specificatore (%u)
 * 1) Calcola i parametri necessari e li inserisce nella struct
 * 2) Affida la stampa a output_nbr */
void	print_u(t_flags flag, unsigned int n, int *byte)
{
	t_print_data	data;

	data = check_flags_nbr(flag, (long)n, 0);
	output_nbr(flag, data, (unsigned long)n, byte);
}

/* Analizza le flag e il valore numerico per inserire in data il segno.
 * - se il numero è negativo inserisce '-'
 * - plus: se è 1 inserisce il '+'
 * - space: se è 1 inserisce ' ' */
static void	check_sign(t_flags flag, char *prefix, long n)
{
	if (n < 0)
		prefix[0] = '-';
	else if (flag.plus)
		prefix[0] = '+';
	else if (flag.space)
		prefix[0] = ' ';
}

/* Analizza le flag e il valore numerico per calcolare i parametri di stampa.
 * Determina:
 * - n_digits: Numero di cifre (gestendo il caso %.0d con valore 0).
 * - byte_zero: Zeri aggiuntivi richiesti dalla precisione.
 * - padding: Spazi necessari per rispettare la larghezza minima (width).
 * - tot_len: Lunghezza totale della stringa finale da stampare.
 * - is_signed : Chiama la funzione check_sign.
 * Ritorna una struct t_num_data con tutti i calcoli effettuati. */
t_print_data	check_flags_nbr(t_flags flag, long n, int is_signed)
{
	t_print_data	data;
	unsigned long	u_nbr;

	u_nbr = abs_val(n);
	data = init_struct_data();
	data.n_digits = count_digits_base(u_nbr, 10);
	if (flag.dot && flag.prec == 0 && n == 0)
		data.n_digits = 0;
	data.count_zero = 0;
	if (flag.dot && flag.prec > data.n_digits)
		data.count_zero = flag.prec - data.n_digits;
	data.tot_len = data.n_digits + data.count_zero;
	if (is_signed)
	{
		check_sign(flag, data.prefix, n);
		if (data.prefix[0] != '\0')
			data.tot_len++;
	}
	if (flag.width > data.tot_len)
		data.padding = flag.width - data.tot_len;
	return (data);
}
