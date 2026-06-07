#include "push_swap.h"

/* Dealloca la lista come passata come parametro.
 * Stampa "Error\n" nello standard error (2).
 * Blocca il programma con exit(1).*/
void	handle_error(t_stack **l_stack_a, t_stack **l_stack_b, t_algo *algo)
{
	if (l_stack_a && *l_stack_a)
		list_clear(l_stack_a);
	if (l_stack_b && *l_stack_b)
		list_clear(l_stack_b);
	if (algo)
		free(algo);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	finish_prog(t_stack **l_stack_a, t_stack **l_stack_b,
			t_data_bench *data, t_algo *algo)
{
	if (l_stack_a && *l_stack_a)
		list_clear(l_stack_a);
	if (l_stack_b && *l_stack_b)
		list_clear(l_stack_b);
	if (algo)
		free(algo);
	if (data)
		free(data);
	exit(0);
}
