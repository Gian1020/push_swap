/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 18:01:39 by marvin            #+#    #+#             */
/*   Updated: 2026/06/07 19:57:52 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Checks if a given string matches any valid algorithm or benchmark flag.
**
** @param s The string to check against known flags.
** @return 1 if it is a valid flag, otherwise 0.
*/
int	is_a_flag(char *s)
{
	if (ft_strcmp(s, "--simple") == 0
		|| ft_strcmp(s, "--medium") == 0
		|| ft_strcmp(s, "--complex") == 0
		|| ft_strcmp(s, "--bench") == 0
		||ft_strcmp(s, "--adaptive") == 0)
		return (1);
	return (0);
}

/*
** Validates that no more than one algorithm flag is active.
**
** @param algo Pointer to the struct containing the flags to validate.
** @return 1 if the flags are valid, otherwise 0.
*/
int	algo_is_valid(t_algo *algo)
{
	int	s_flag;

	s_flag = algo->simple + algo->medium + algo->complex + algo->adaptive;
	if (s_flag < 2 && algo->bench < 2)
		return (0);
	return (1);
}

/*
** Activates the corresponding algorithm or benchmark flag based on input.
**
** @param argv The string containing the flag argument.
** @param algo Pointer to the struct where the flag state is updated.
*/
void	set_flag_algo(char *argv, t_algo *algo)
{
	if (!argv)
		return ;
	if (ft_strcmp(argv, "--simple") == 0)
		algo->simple += 1;
	else if (ft_strcmp(argv, "--medium") == 0)
		algo->medium += 1;
	else if (ft_strcmp(argv, "--complex") == 0)
		algo->complex += 1;
	else if (ft_strcmp(argv, "--adaptive") == 0)
		algo->adaptive += 1;
	if (ft_strcmp(argv, "--bench") == 0)
		algo->bench += 1;
}

/*
** Determines the starting index for parsing arguments by skipping flags.
**
** @param argv The array of command line arguments.
** @param algo Pointer to the struct containing active algorithm flags.
** @return The index in argv where numbers begin (after the flags).
*/
int	find_start_idx(char **argv, t_algo *algo)
{
	int	start_idx;

	start_idx = 1;
	(void)algo;
	if (argv[1] && is_a_flag(argv[1]))
	{
		start_idx = 2;
		if (argv[2] && is_a_flag(argv[2]))
			start_idx = 3;
	}
	return (start_idx);
}
