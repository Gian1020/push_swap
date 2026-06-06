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

static int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	parse_number(int argc, char **argv, int *flag_err)
{
	if (is_number(argv[1]))
	{
		if (argc >= 3 && !is_number(argv[2]))
			*flag_err = 1;
		return ;
	}
}

static void	parse_flag(int argc, char **argv, t_algo *algo, int *flag_err)
{
	if (argc < 3)
		return ;
	if (ft_strncmp(argv[2], "--simple", 9) == 0
		|| ft_strncmp(argv[2], "--medium", 9) == 0
		|| ft_strncmp(argv[2], "--complex", 10) == 0
		|| ft_strncmp(argv[2], "--bench", 8) == 0)
	{
		if (ft_strncmp(argv[2], "--simple", 9) == 0)
			*flag_err = 1;
		if (ft_strncmp(argv[2], "--medium", 9) == 0)
			*flag_err = 1;
		if (ft_strncmp(argv[2], "--complex", 10) == 0)
			*flag_err = 1;
		if (ft_strncmp(argv[2], "--bench", 8) == 0
			&& ft_strncmp(argv[1], "--bench", 8) != 0)
			algo->bench = 1;
	}
	else
	{
		if (!is_number(argv[2]))
		{
			*flag_err = 1;
			return ;
		}
	}
}

void	check_flag(int argc, char **argv, t_algo *algo, int *flag_err)
{
	if (argc < 2 || !argv || !argv[1])
		return ;
	if (ft_strncmp(argv[1], "--simple", 9) == 0
		|| ft_strncmp(argv[1], "--medium", 9) == 0
		|| ft_strncmp(argv[1], "--complex", 10) == 0
		|| ft_strncmp(argv[1], "--bench", 8) == 0)
	{
		if (ft_strncmp(argv[1], "--simple", 9) == 0)
			algo->simple = 1;
		if (ft_strncmp(argv[1], "--medium", 9) == 0)
			algo->medium = 1;
		if (ft_strncmp(argv[1], "--complex", 10) == 0)
			algo->complex = 1;
		if (ft_strncmp(argv[1], "--bench", 8) == 0)
			algo->bench = 1;
		algo->adaptive = 0;
		if (ft_strncmp(argv[1], "--bench", 8) == 0)
			algo->adaptive = 1;
	}
	parse_flag(argc, argv, algo, flag_err);
	parse_number(argc, argv, flag_err);
}

void	find_start_idx(char **argv, int *start_idx)
{
	start_idx = 1;
	if (argv[1] && ft_strncmp(argv[1], "--", 2) == 0)
	{
		start_idx = 2;
		if (argv[2] && ft_strncmp(argv[2], "--", 2) == 0)
			start_idx = 3;
	}
}