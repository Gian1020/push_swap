/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 18:29:51 by gipimpin          #+#    #+#             */
/*   Updated: 2026/05/25 18:30:21 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/* Inizializza la struct con le informazioni per la stampa 
 * dei numeri ai valori di default.
 * - prefix è un array di 3 byte per gestire i seguenti casi:
 * - se lo specificatore è %i o %d inseririsco il segno o lo spazio 
 * - se lo specificatore è %x o %p inserisco il prefisso "0x"
 * - se lo specificarore è %X inserisco "0X"*/
t_print_data	init_struct_data(void)
{
	t_print_data	data;

	data.n_digits = 0;
	data.count_zero = 0;
	data.padding = 0;
	data.tot_len = 0;
	data.is_upper_hex = 0;
	data.prefix[0] = '\0';
	data.prefix[1] = '\0';
	data.prefix[2] = '\0';
	return (data);
}

/* Inizializza la struct con tutte le flag e lo
 * specificatore ai valori di default. */
t_flags	init_struct_flags(void)
{
	t_flags	s_flags;

	s_flags.width = 0;
	s_flags.prec = -1;
	s_flags.minus = 0;
	s_flags.zero = 0;
	s_flags.dot = 0;
	s_flags.hash = 0;
	s_flags.space = 0;
	s_flags.plus = 0;
	s_flags.spec = '\0';
	return (s_flags);
}

/* Gestisce: precision Definita dal punto '.' seguito da eventuali cifre.*/
static int	handle_precision(t_flags *s, const char *format, int i)
{
	s->dot = 1;
	s->prec = 0;
	while (isdigit(format[i + 1]))
	{
		i++;
		s->prec = (s->prec * 10) + (format[i] - '0');
	}
	return (i);
}

/* Scansiona la stringa 'format' a partire dall'indice 'i' finché non incontra 
 * uno specificatore di conversione (es. d, s, x).
 * Gestisce:
 * - Flags: '-', '#', '+', ' ', '0'
 * - Width: Larghezza minima del campo.
 * - Precision con la sotto-funzione _handle_precision
 * Restituisce l'indice 'i' posizionato sullo specificatore trovato.*/
int	build_flags(t_flags *s, const char *format, int i)
{
	while (format[i] && !isspecifier(format[i]))
	{
		if (format[i] == '-')
			s->minus = 1;
		else if (format[i] == '#')
			s->hash = 1;
		else if (format[i] == '+')
			s->plus = 1;
		else if (format[i] == ' ')
			s->space = 1;
		else if (format[i] == '0' && !s->width && !s->minus)
			s->zero = 1;
		else if (format[i] == '.')
			i = handle_precision(s, format, i);
		else if (isdigit(format[i]))
			s->width = (s->width * 10) + (format[i] - '0');
		else
			break ;
		i++;
	}
	return (i);
}
