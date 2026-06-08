/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecelli <gpecelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 14:07:04 by gpecelli          #+#    #+#             */
/*   Updated: 2026/06/08 14:07:06 by gpecelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		flag_err;
	int		idx;
	t_stack	*l_stack_a;
	t_algo	*algo;

	if (argc < 2)
		return (0);
	flag_err = 0;
	algo = init_algo();
	set_flag_algo(argv[1], algo);
	set_flag_algo(argv[2], algo);
	flag_err = algo_is_valid(algo);
	idx = find_start_idx(argv, algo);
	l_stack_a = argv_to_list(&argv[idx], &flag_err);
	if (!l_stack_a || flag_err || have_duplicate(l_stack_a))
		handle_error(&l_stack_a, NULL, algo);
	fast_sort(l_stack_a);
	if (!is_sorted(l_stack_a))
		sort_stack(&l_stack_a, algo);
	else
	{
		t_data_bench	*data;
		if (algo->bench == 1)
		{
			data = init_bench(compute_disorder(l_stack_a));
			bench_writer(data, algo);
		}
		finish_prog(&l_stack_a, NULL, NULL, algo);
	}
	return (0);
}