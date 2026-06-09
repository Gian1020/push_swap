/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecelli <gpecelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:57:54 by gipimpin          #+#    #+#             */
/*   Updated: 2026/06/08 14:07:28 by gpecelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*
** Frees a dynamically allocated matrix of strings.
** Iterates through each element until NULL, freeing each string's memory,
** and finally frees the array of pointers itself.
**
** @param mtrx The null-terminated array of strings to free.
*/
void	free_mtrx(char **mtrx)
{
	int	i;

	i = 0;
	if (!mtrx)
		return ;
	while (mtrx[i])
	{
		free(mtrx[i]);
		i++;
	}
	free(mtrx);
}

/*
** Populates the stack by converting tokens from temp_split via atoi_check.
** Stops insertion on the first validation or overflow error,
** reporting the status using the flag_err pointer.
**
** @param first Pointer to the first node pointer of the list.
** @param temp_split Array of string tokens to be converted and pushed.
** @param flag_err Pointer to an error flag set to 1 on failure.
*/
void	fill_stack(t_stack **first, char **temp_split, int *flag_err)
{
	int	val;
	int	j;

	j = 0;
	while (temp_split[j] && !*flag_err)
	{
		val = atoi_check(temp_split[j], flag_err);
		if (!*flag_err)
			*flag_err = list_push_back(first, val);
		j++;
	}
}

/*
** Converts command line arguments into a linked list.
** 1. Splits each argv string into tokens to handle mixed inputs.
** 2. Validates and converts each token to an integer, checking overflows.
** 3. Pushes valid values to the back of the list using fill_stack.
** 4. Manages the liberation of temporary memory and error flags.
**
** @param argv Array of strings representing the arguments.
** @param flag_err Pointer to an error flag set to 1 on failure.
** @return Pointer to the first node of the populated stack, or NULL on error.
*/
t_stack	*argv_to_list(char **argv, int *flag_err)
{
	int		i;
	char	**temp_split;
	t_stack	*first;

	i = 0;
	first = NULL;
	while (argv[i] && !*flag_err)
	{
		temp_split = ft_split(argv[i], ' ');
		if (!temp_split || !temp_split[0])
		{
			*flag_err = 1;
			if (temp_split)
				free_mtrx(temp_split);
			break ;
		}
		fill_stack(&first, temp_split, flag_err);
		free_mtrx(temp_split);
		i++;
	}
	return (first);
}

/*
** Assigns a relative index (0 to size-1) to each node in the stack.
** Simplifies sorting by transforming real values (even large or negative ones)
** into a continuous sequence of integers.
** Iteratively finds the minimum value not yet indexed (idx == -1)
** and assigns it the current value 'i'.
**
** @param begin_list Pointer to the first node of the stack.
*/
void	fast_sort(t_stack *begin_list)
{
	int		i;
	int		size;
	t_stack	*current;
	t_stack	*min_node;

	i = 0;
	size = list_size(begin_list);
	while (i < size)
	{
		current = begin_list;
		min_node = NULL;
		while (current != NULL)
		{
			if (current->idx == -1)
			{
				if (min_node == NULL || current->value < min_node->value)
					min_node = current;
			}
			current = current->next;
		}
		if (min_node != NULL)
			min_node->idx = i;
		i++;
	}
}
