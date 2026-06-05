#include "push_swap.h"

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

void	bench_writer(t_data_bench *data_bench)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	print_disorder(data_bench->disorder);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	if (data_bench->disorder < 0.2)
		ft_putstr_fd("Simple O(n^2)", 2);
	else if (data_bench->disorder >= 0.2 && data_bench->disorder <= 0.5)
		ft_putstr_fd("Medium O(n sqrt(n))", 2);
	else
		ft_putstr_fd("Complex O(n log n)", 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(data_bench->total, 2);
	ft_putchar_fd('\n', 2);
	bench_writer_row4(data_bench);
	ft_putchar_fd('\n', 2);
	bench_writer_row5(data_bench);
	ft_putchar_fd('\n', 2);
}
