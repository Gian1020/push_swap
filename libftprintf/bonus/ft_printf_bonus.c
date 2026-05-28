/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 18:29:51 by gipimpin          #+#    #+#             */
/*   Updated: 2026/05/25 18:30:21 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/* Reindirizza l'argomento alla funzione specifica in base
 * allo specificatore contenuto nella struct*/
static void	check_spec(t_flags flag, va_list args, int *byte)
{
	if (flag.spec == 'c')
		print_c(flag, va_arg(args, int), byte);
	else if (flag.spec == 's')
		print_s(flag, va_arg(args, char *), byte);
	else if (flag.spec == 'p')
		print_p(flag, va_arg(args, void *), byte);
	else if (flag.spec == 'd' || flag.spec == 'i')
		print_di(flag, va_arg(args, int), byte);
	else if (flag.spec == 'u')
		print_u(flag, va_arg(args, unsigned int), byte);
	else if (flag.spec == 'x')
		print_x_low(flag, va_arg(args, unsigned int), byte);
	else if (flag.spec == 'X')
		print_x_up(flag, va_arg(args, unsigned int), byte);
	else if (flag.spec == '%')
		print_c(flag, '%', byte);
}

/* Gestisce la sequenza di formattazione dopo un carattere '%'.
 * Tenta di costruire una struct di flag e di eseguire la conversione.
 * Se lo specificatore non è valido (es. %30z), esegue un "fallback"
 * stampando '%' e resettando l'indice per trattare i caratteri 
 * successivi come testo normale.
 */
static void	handle_spec(
		const char *format,
		va_list args,
		int *i,
		int *byte)
{
	t_flags	flag;
	int		start;

	flag = init_struct_flags();
	start = *i;
	*i = build_flags(&flag, format, *i);
	if (format[*i] && isspecifier(format[*i]))
	{
		flag.spec = format[*i];
		check_spec(flag, args, byte);
	}
	else
	{
		putchar_count('%', byte);
		*i = start -1;
	}
}

static int	format_terminate_x100(const char *format)
{
	int	i;

	i = 0;
	while (format[i])
		i++;
	if (i == 1 && format[0])
		return (1);
	if (i > 1 && format[i - 1] == '%' && format[i - 2] != '%')
		return (1);
	else
		return (0);
}

/* Analizza la stringa 'format' e gestisce i parametri variabili (va_list)
 * Se trova un '%', delega l analisi a  handle_specifier,
 * Altrimenti stampa il carattere corrente
 * restituisce il numero totale di byte stampati o -1 in caso d'errore */
int	ft_printf(const char *format, ...)
{
	int					i;
	int					byte;
	va_list				args;

	if (!format || format_terminate_x100(format))
		return (-1);
	i = 0;
	byte = 0;
	va_start(args, format);
	while (format[i] && byte != -1)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				break ;
			i++;
			handle_spec(format, args, &i, &byte);
		}
		else
			putchar_count(format[i], &byte);
		i++;
	}
	va_end(args);
	return (byte);
}
