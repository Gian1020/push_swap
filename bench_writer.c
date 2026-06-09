/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_writer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecelli <gpecelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:57:52 by gipimpin          #+#    #+#             */
/*   Updated: 2026/06/08 12:39:56 by gpecelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Prints the operation counts for swap and push instructions.
**
** @param data_bench Pointer to the struct holding the benchmark data.
*/
static void	bench_writer_row4(t_data_bench *data_bench)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(data_bench->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(data_bench->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(data_bench->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(data_bench->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(data_bench->pb, 2);
}

/*
** Prints the operation counts for rotate and reverse rotate instructions.
**
** @param data_bench Pointer to the struct holding the benchmark data.
*/
static void	bench_writer_row5(t_data_bench *data_bench)
{
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(data_bench->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(data_bench->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(data_bench->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(data_bench->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(data_bench->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(data_bench->rrr, 2);
}

/*
** Prints the algorithm complexity class based on flags or disorder ratio.
**
** @param data_bench Pointer to the struct holding benchmark data.
** @param algo Pointer to the struct storing active algorithm flags.
*/
static void	print_complex(t_data_bench *data_bench, t_algo *algo)
{
	if (algo->simple)
		ft_putstr_fd("Simple O(n^2)", 2);
	else if (algo->medium)
		ft_putstr_fd("Medium O(n sqrt(n))", 2);
	else if (algo->complex)
		ft_putstr_fd("Complex O(n log n)", 2);
	else if (data_bench->disorder < 0.2)
		ft_putstr_fd("Adaptive / O(n^2)", 2);
	else if (data_bench->disorder >= 0.2 && data_bench->disorder <= 0.5)
		ft_putstr_fd("Adaptive / O(n sqrt(n))", 2);
	else
		ft_putstr_fd("Adaptive / O(n log n)", 2);
}

/*
** Prints a comprehensive benchmark summary of operations and strategy.
** Calls helper functions to print disorder, complexity, and specific
** instruction counts.
**
** @param data_bench Pointer to the struct holding benchmark data.
** @param algo Pointer to the struct storing active algorithm flags.
*/
void	bench_writer(t_data_bench *data_bench, t_algo *algo)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	print_disorder(data_bench->disorder);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	print_complex(data_bench, algo);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(data_bench->total, 2);
	ft_putchar_fd('\n', 2);
	bench_writer_row4(data_bench);
	ft_putchar_fd('\n', 2);
	bench_writer_row5(data_bench);
	ft_putchar_fd('\n', 2);
}
