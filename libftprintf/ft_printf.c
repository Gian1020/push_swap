/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 18:29:51 by gipimpin          #+#    #+#             */
/*   Updated: 2026/05/25 18:29:51 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Reindirizza l'argomento alla funzione specifica in base
 * allo specificatore*/
static void	check_spec(int spec, va_list args, int *byte)
{
	if (spec == 'c')
		print_c(va_arg(args, int), byte);
	else if (spec == 's')
		print_s(va_arg(args, char *), byte);
	else if (spec == 'p')
		print_p(va_arg(args, void *), byte);
	else if (spec == 'd' || spec == 'i')
		print_di(va_arg(args, int), byte);
	else if (spec == 'u')
		print_u(va_arg(args, unsigned int), byte);
	else if (spec == 'x')
		print_x_low(va_arg(args, unsigned int), byte);
	else if (spec == 'X')
		print_x_up(va_arg(args, unsigned int), byte);
	else if (spec == '%')
		print_c('%', byte);
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
 * Se trova un '%', delega l'analisi a check_spec il quale controlla se
 * format[i] è un carattere idoneo ai nostri specificatori.
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
			check_spec(format[i], args, &byte);
		}
		else
			putchar_count(format[i], &byte);
		i++;
	}
	va_end(args);
	return (byte);
}
