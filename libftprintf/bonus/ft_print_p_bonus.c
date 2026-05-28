/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 18:29:50 by gipimpin          #+#    #+#             */
/*   Updated: 2026/05/25 18:30:20 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/* Gestisce lo specificatore '%p' (puntatore).
 * 1. Se il puntatore è NULL, stampa "(nil)" (comportamento standard su Linux).
 * 2. Converte l'indirizzo in 'unsigned long long' per gestirne l'ampiezza.
 * 3. Sfrutta la logica degli esadecimali (check_flags_hex) poiché un 
 * indirizzo di memoria è rappresentato in base 16 con prefisso '0x'.
 * 4. Affida la stampa finale a output_hex. */
void	print_p(t_flags flag, void *p, int *byte)
{
	t_print_data		data;
	unsigned long long	ptr_val;

	if (!p)
	{
		print_s(flag, "(nil)", byte);
		return ;
	}
	ptr_val = (unsigned long long) p;
	data = check_flags_hex(flag, ptr_val, 0);
	output_hex(flag, data, ptr_val, byte);
}
