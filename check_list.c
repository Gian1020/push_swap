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

/* Verifica se la lista è ordinata in ordine crescente.
 * Se lo è torna 1 altrimenti 0.*/
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

/* Verifica la presenza di valori duplicati nella lista.
 * Se ci sono fa tornare 1 altrimenti 0.*/
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

/* Salta tab e spazi davanti a una stringa e fa tornare i*/
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

/* Converte le stringa passata in INT gestendo segni e spazi.
 * Controlla se il valore calcolato supera i limiti degli interi.
 * In caso  non li rispetti setta la flag a 1.*/
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
