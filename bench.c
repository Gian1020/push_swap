/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecelli <gpecelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 16:40:21 by gpecelli          #+#    #+#             */
/*   Updated: 2026/06/03 17:21:03 by gpecelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bench_writer(t_data_bench *data_bench, t_algo *algo_config, float f)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	print_disorder(f);
	ft_putchar_fd('\n', 2);

	ft_putstr_fd("[bench] strategy: ", 2);
// manca qualcosa
	ft_putchar_fd('\n', 2);

	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(data_bench->total_ops, 2);
	ft_putchar('\n', 2);
	bench_writer_row4(data_bench, algo_config, f);
	ft_putchar_fd('\n', 2);
	bench_writer_row5(data_bench, algo_config, f);
	ft_putchar_fd('\n', 2);
}

void	bench_writer_row4(t_data_bench *data_bench, t_algo *algo_config, float f)
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

void	bench_writer_row5(t_data_bench *data_bench, t_algo *algo_config, float f)
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