/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 18:37:07 by gipimpin          #+#    #+#             */
/*   Updated: 2026/05/25 20:23:11 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# define BASE_10 "0123456789"
# define BASE_16_LOW "0123456789abcdef"
# define BASE_16_UP "0123456789ABCDEF"

# include <unistd.h>
# include <stdarg.h>

typedef struct s_flags
{
	int		width;
	int		prec;
	int		minus;
	int		zero;
	int		dot;
	int		hash;
	int		space;
	int		plus;
	char	spec;
}	t_flags;

typedef struct s_print_data
{
	int		n_digits;
	int		count_zero;
	int		padding;
	int		tot_len;
	int		is_upper_hex;
	char	prefix[3];
}	t_print_data;

int				ft_printf(const char *format, ...);

void			print_c(t_flags flag, int c, int *byte);
void			print_s(t_flags flag, char *str, int *byte);
void			print_di(t_flags flag, int n, int *byte);
void			print_u(t_flags flag, unsigned int n, int *byte);
void			print_p(t_flags flag, void *ptr, int *byte);
void			print_x_low(t_flags flag, unsigned int n, int *byte);
void			print_x_up(t_flags flag, unsigned int n, int *byte);

void			output_hex(t_flags flag, t_print_data data,
					unsigned long long n, int *byte);
void			output_nbr(t_flags flag, t_print_data data,
					unsigned long n, int *byte);
void			putnbr_base_count(unsigned long long n,
					const char *base, int *byte);

int				isdigit(int c);
int				isspecifier(int c);
void			putchar_count(unsigned char c, int *byte);
void			putnstr_count(char *str, int n, int *byte);
void			putnchar_count(unsigned char c, int n, int *byte);

unsigned long	abs_val(long abs);
int				count_digits_base(unsigned long long n, int base_len);

t_print_data	check_flags_hex(t_flags flag, unsigned long long n, int is_up);
int				build_flags(t_flags *s, const char *format, int i);
t_flags			init_struct_flags(void);
t_print_data	init_struct_data(void);
t_print_data	check_flags_nbr(t_flags flag, long n, int is_signed);
#endif
