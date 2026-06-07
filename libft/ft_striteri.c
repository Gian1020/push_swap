/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:57:45 by gipimpin          #+#    #+#             */
/*   Updated: 2026/06/07 19:58:19 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Itera sulla stringa 's' applicando la funzione 'f()' a ogni carattere
 * direttamente in memoria (in-place). Passa alla funzione di callbacki
 * sia l'indice corrente che l'indirizzo del carattere ( '&s[i]' ),
 * consentendo modifiche puntuali alla stringa originale. Include un
 * controllo di sicurezza sui puntatori per prevenire operazioni illegali. */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
