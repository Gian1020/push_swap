/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:57:45 by gipimpin          #+#    #+#             */
/*   Updated: 2026/06/07 19:58:17 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Sends 's' to file descriptor 'fd' using the 'write()' system call.
 * Performs a preemptive check on the validity of the pointer 's' to prevent
 * illegal dereferencing. Dynamically calculates the buffer size
 * using 'ft_strlen' to ensure atomic and complete output. */
void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}
