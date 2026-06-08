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
#include <stdio.h>

void	select_move(t_stack **l_stack_a, t_stack **l_stack_b, char *line)
{
	if (ft_strcmp(line, "pa\n"))
		pa_b(l_stack_a, l_stack_b);
	else if (ft_strcmp(line, "pb\n"))
		pb_b(l_stack_a, l_stack_b);
	else if (ft_strcmp(line, "sa\n"))
		sa_b(l_stack_a);
	else if (ft_strcmp(line, "sb\n"))
		sb_b(l_stack_b);
	else if (ft_strcmp(line, "ss\n"))
		ss_b(l_stack_a, l_stack_b);
	else if (ft_strcmp(line, "ra\n"))
		ra_b(l_stack_a);
	else if (ft_strcmp(line, "rb\n"))
		rb_b(l_stack_b);
	else if (ft_strcmp(line, "rr\n"))
		rr_b(l_stack_a, l_stack_b);
	else if (ft_strcmp(line, "rra\n"))
		rra_b(l_stack_a);
	else if (ft_strcmp(line, "rrb\n"))
		rrb_b(l_stack_a);
	else if (ft_strcmp(line, "rrr\n"))
		rrr_b(l_stack_a, l_stack_b);
}

int	is_move(char *line)
{
	if (ft_strcmp(line, "pa\n") || ft_strcmp(line, "pb\n")
		|| ft_strcmp(line, "sa\n") || ft_strcmp(line, "sb\n")
		|| ft_strcmp(line, "ra\n") || ft_strcmp(line, "rb\n")
		|| ft_strcmp(line, "rra\n") || ft_strcmp(line, "rrb\n")
		|| ft_strcmp(line, "rrr\n") || ft_strcmp(line, "rr\n")
		|| ft_strcmp(line, "ss\n"))
		return (1);
	else
		return (0);
}

int	ft_what_in_line(t_stack **l_stack_a, t_stack **l_stack_b,char *line)
{	
	if (is_move(line) != 1)
		return (0);
	select_move(l_stack_a, l_stack_b, line);
	return (1);
}

int	main(int argc, char **argv)
{
	int		flag_err;
	int		flag_is_move;
	t_stack	*l_stack_a;
	t_stack	*l_stack_b;
	char	*line;

	if (argc < 2)
		return (0);
	flag_err = 0;
	l_stack_a = argv_to_list(&argv[1], &flag_err);
	l_stack_b = (t_stack *) malloc (sizeof(t_stack));
	if (!l_stack_a || flag_err == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	while (1)
	{
		line = get_next_line(0);
		//printf("%s", line);
		if(!line)
			break;
		if (line)
			flag_is_move = ft_what_in_line(&l_stack_a, &l_stack_b, line);
		else
		{
			if(is_sorted(l_stack_a) && l_stack_b == NULL)
			{
				free(l_stack_a);
				free(l_stack_b);
				ft_putstr_fd("OK", 1);
				return (0);
			}
			else
			{
				free(l_stack_a);
				free(l_stack_b);
				ft_putstr_fd("KO", 1);
				return (1);
			}
		}
	}
}
