/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 18:34:35 by gipimpin          #+#    #+#             */
/*   Updated: 2026/05/25 20:20:43 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BASE_10 "0123456789"
# define BASE_16_LOW "0123456789abcdef"
# define BASE_16_UP "0123456789ABCDEF"

# include <unistd.h>
# include <stdarg.h>

int				ft_printf(const char *format, ...);

void			print_c(int c, int *byte);
void			print_s(char *str, int *byte);
void			print_di(int n, int *byte);
void			print_u(unsigned int n, int *byte);
void			print_p(void *ptr, int *byte);
void			print_x_low(unsigned int n, int *byte);
void			print_x_up(unsigned int n, int *byte);

void			putnbr_base_count(unsigned long long n,
					const char *base, int *byte);
unsigned long	abs_val(long abs);
void			putchar_count(unsigned char c, int *byte);
void			putnstr_count(char *str, int n, int *byte);

#endif
