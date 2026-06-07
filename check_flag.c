/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 18:01:39 by marvin            #+#    #+#             */
/*   Updated: 2026/06/06 18:01:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_a_flag(char *s)
{
	if (ft_strcmp(s, "--simple") == 0 ||
		ft_strcmp(s, "--medium") == 0 ||
		ft_strcmp(s, "--complex") == 0 ||
		ft_strcmp(s, "--bench") == 0 ||
		ft_strcmp(s, "--adaptive") == 0)
		return (1);
	return (0);
}


int	algo_is_valid(t_algo *algo)
{
	int	s_flag;

	s_flag = algo->simple + algo->medium + algo->complex + algo->adaptive;
	if (s_flag == 1)
		return (0);
	return (1);
}

void	set_flag_algo(char *argv, t_algo *algo)
{
	if (!argv)
		return;
	if (ft_strcmp(argv, "--simple") == 0)
		algo->simple += 1;
	else if (ft_strcmp(argv, "--medium") == 0)
		algo->medium += 1;
	else if (ft_strcmp(argv, "--complex") == 0)
		algo->complex += 1;
	else if (ft_strcmp(argv, "--adaptive") == 0)
		algo->adaptive += 1;
	if (ft_strcmp(argv, "--bench") == 0)
		algo->bench = 1;
}

int	find_start_idx(char **argv)
{
	int	start_idx;

	start_idx = 1;
	if (argv[1] && is_a_flag(argv[1]))
	{
		start_idx = 2;
		if (argv[2] && is_a_flag(argv[2]))
			start_idx = 3;
	}
	return (start_idx);
}