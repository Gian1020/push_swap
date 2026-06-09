/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecelli <gpecelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:58:39 by gpecelli          #+#    #+#             */
/*   Updated: 2026/06/08 17:02:37 by gpecelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	result(t_stack **l_stack_a, t_stack **l_stack_b, char *line,
		char *msg)
{
	if (!msg)
	{
		if (is_sorted(*l_stack_a) || list_size(*l_stack_b))
			result(l_stack_a, l_stack_b, line, "OK\n");
		else
			result(l_stack_a, l_stack_b, line, "KO\n");
	}
	if (l_stack_a)
		list_clear(l_stack_a);
	if (l_stack_b)
		list_clear(l_stack_b);
	if (line)
		free(line);
	if (msg)
		ft_putstr_fd(msg, 1);
}

int	is_move(char *line)
{
	if (!line)
		return (0);
	if (ft_strcmp(line, "pa\n") == 0 || ft_strcmp(line, "pb\n") == 0
		|| ft_strcmp(line, "sa\n") == 0 || ft_strcmp(line, "sb\n") == 0
		|| ft_strcmp(line, "ra\n") == 0 || ft_strcmp(line, "rb\n") == 0
		|| ft_strcmp(line, "rra\n") == 0 || ft_strcmp(line, "rrb\n") == 0
		|| ft_strcmp(line, "rrr\n") == 0 || ft_strcmp(line, "rr\n") == 0
		|| ft_strcmp(line, "ss\n") == 0)
		return (1);
	else
		return (0);
}

void	select_move(t_stack **l_stack_a, t_stack **l_stack_b, char *line)
{
	if (ft_strcmp(line, "pa\n") == 0)
		pa_b(l_stack_a, l_stack_b);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb_b(l_stack_a, l_stack_b);
	else if (ft_strcmp(line, "sa\n") == 0)
		sa_b(l_stack_a);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb_b(l_stack_b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss_b(l_stack_a, l_stack_b);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra_b(l_stack_a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb_b(l_stack_b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr_b(l_stack_a, l_stack_b);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra_b(l_stack_a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb_b(l_stack_b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr_b(l_stack_a, l_stack_b);
}

int	main(int argc, char **argv)
{
	int		flag_err;
	t_stack	*l_stack_a;
	t_stack	*l_stack_b;
	char	*line;

	if (argc < 2)
		return (0);
	flag_err = 0;
	l_stack_a = argv_to_list(&argv[1], &flag_err);
	fast_sort(l_stack_a);
	if (!l_stack_a || flag_err == 1 || have_duplicate(l_stack_a))
		return (result(&l_stack_a, NULL, NULL, "Error\n"), 1);
	l_stack_b = NULL;
	line = get_next_line(0);
	while (line != NULL)
	{
		if (is_move(line))
			select_move(&l_stack_a, &l_stack_b, line);
		else
			return (result(&l_stack_a, &l_stack_b, line, "Error\n"), 1);
		free(line);
		line = get_next_line(0);
	}
	result(&l_stack_a, &l_stack_b, line, NULL);
}
