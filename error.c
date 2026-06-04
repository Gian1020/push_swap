#include "push_swap.h"

/* Dealloca la lista come passata come parametro.
 * Stampa "Error\n" nello standard error (2).
 * Blocca il programma con exit(1).*/
void	handle_error(t_stack **l_stack_a, t_stack **l_stack_b)
{
	if (l_stack_a && *l_stack_a)
		list_clear(l_stack_a);
	if (l_stack_b && *l_stack_b)
		list_clear(l_stack_b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	insert_in_algo(t_algo *check_algo, char *s1, char *s2)
{
	int	res_cmp;

	res_cmp = ft_strcmp(s1, s2);
	if (res_cmp == 0)
	{
		if (s1[0] == 's')
		{
			check_algo->simple = 1;
			check_algo->adaptive = 0;
		}
		else if (s1[0] == 'm')
		{
			check_algo->medium = 1;
			check_algo->adaptive = 0;
		}
		else if (s1[0] == 'c')
		{
			check_algo->complex = 1;
			check_algo->adaptive = 0;
		}
		else if (s1[0] == 'b')
			check_algo->bench = 1;
	}
	return (res_cmp);
}

int	check_flag(char	*flag_to_check, t_algo *check_algo)
{
	if (!check_algo)
		return (1);
	if (flag_to_check[0] == '-' && flag_to_check[1] == '-')
	{
		if (flag_to_check[2] == 's')
			return (insert_in_algo(check_algo, &flag_to_check[2], "simple"));
		else if (flag_to_check[2] == 'm')
			return (insert_in_algo(check_algo, &flag_to_check[2], "medium"));
		else if (flag_to_check[2] == 'c')
			return (insert_in_algo(check_algo, &flag_to_check[2], "complex"));
		else if (flag_to_check[2] == 'b')
			return (insert_in_algo(check_algo, &flag_to_check[2], "bench"));
		else if (flag_to_check[2] == 'a')
			return (insert_in_algo(check_algo, &flag_to_check[2], "adaptive"));
	}
	return (1);
}

void	print_algo(t_algo *check_algo)
{
	ft_printf("s = %d ", check_algo->simple);
	ft_printf("m = %d ", check_algo->medium);
	ft_printf("c = %d ", check_algo->complex);
	ft_printf("a = %d ", check_algo->adaptive);
	ft_printf("b = %d \n", check_algo->bench);
}

// TODO non prendere bench bench
