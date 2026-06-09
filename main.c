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

/*
** Handles the scenario where the stack is already sorted at initialization.
** Writes benchmarks if requested and safely exits the program.
**
** @param l_stack_a Pointer to the fully sorted stack A.
** @param algo Pointer to the algorithm settings struct.
*/
static void	stack_already_sorted(t_stack *l_stack_a, t_algo *algo)
{
	t_data_bench	*data;

	if (algo->bench == 1)
	{
		data = init_bench(compute_disorder(l_stack_a));
		bench_writer(data, algo);
	}
	finish_prog(&l_stack_a, NULL, NULL, algo);
}

/*
** Main entry point of the push_swap program.
** Parses arguments, handles errors, and executes the appropriate algorithm.
**
** @param argc The number of command line arguments.
** @param argv Array of strings representing the arguments.
** @return 0 upon successful completion.
*/
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
		stack_already_sorted(l_stack_a, algo);
	return (0);
}
