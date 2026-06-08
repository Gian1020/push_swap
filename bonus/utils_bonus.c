/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 20:04:00 by gipimpin          #+#    #+#             */
/*   Updated: 2026/06/08 20:04:04 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	is_ok_or_ko(t_stack **l_stack_a, t_stack **l_stack_b, char *line)
{
	if (is_sorted(*l_stack_a))
		result(l_stack_a, l_stack_b, line, "OK\n");
	else
		result(l_stack_a, l_stack_b, line, "KO\n");
}
