/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 18:29:43 by marvin            #+#    #+#             */
/*   Updated: 2026/06/07 19:57:52 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Checks if the list is sorted in ascending order.
**
** @param l_stack Pointer to the first node of the stack to evaluate.
** @return 1 if sorted, otherwise 0.
*/
int	is_sorted(t_stack *l_stack)
{
	if (!l_stack)
		return (1);
	while (l_stack && l_stack->next)
	{
		if (l_stack->idx > l_stack->next->idx)
			return (0);
		l_stack = l_stack->next;
	}
	return (1);
}

/*
** Checks for duplicate values in the list.
**
** @param begin_list Pointer to the first node of the list.
** @return 1 if duplicates exist, otherwise 0.
*/
int	have_duplicate(t_stack *begin_list)
{
	t_stack	*next_node;

	if (!begin_list || !begin_list->next)
		return (0);
	while (begin_list != NULL)
	{
		next_node = begin_list->next;
		while (next_node != NULL)
		{
			if (begin_list->value == next_node->value)
				return (1);
			next_node = next_node->next;
		}
		begin_list = begin_list->next;
	}
	return (0);
}

/*
** Skips leading tabs and spaces in a string and returns the index.
**
** @param str The string to parse.
** @return The index of the first non-whitespace character.
*/
static int	is_space(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}

/*
** Checks the sign of the number, updates the index, and returns the sign.
**
** @param str The string containing the number.
** @param i Pointer to the current parsing index in the string.
** @return 1 for positive, -1 for negative.
*/
static int	check_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	if ((str[*i] == '-' || str[*i] == '+'))
	{
		if (str[*i] == '-')
			sign *= -1;
		(*i)++;
	}
	return (sign);
}

/*
** Converts the given string to an int, handling signs and spaces.
** Checks if the calculated value exceeds integer limits.
** Sets the error flag to 1 if limits are exceeded or formatting is bad.
**
** @param str The string representation of the integer.
** @param flag_err Pointer to an integer flag set to 1 upon an error.
** @return The converted integer value.
*/
int	atoi_check(char *str, int *flag_err)
{
	int				i;
	int				j;
	int				sign;
	long long		n;

	i = is_space(str);
	n = 0;
	sign = 1;
	sign = check_sign(str, &i);
	j = i;
	while (ft_isdigit(str[i]))
	{
		n = (n * 10) + str[i] - '0';
		if ((n > 2147483648 && sign == -1) || (n > 2147483647 && sign == 1))
		{
			*flag_err = 1;
			break ;
		}
		i++;
	}
	if (j == i || str[i] != '\0')
		*flag_err = 1;
	return ((int)(n * sign));
}
