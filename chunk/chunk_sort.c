/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecelli <gpecelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:57:38 by gipimpin          #+#    #+#             */
/*   Updated: 2026/06/10 14:25:17 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
** Allocates and initializes the range structure for chunk sorting.
**
** @return A pointer to the newly allocated t_i_range struct.
*/
static t_i_range	*init_i_range(void)
{
	t_i_range	*s_i_range;

	s_i_range = (t_i_range *) malloc (sizeof(t_i_range));
	s_i_range->i = 0;
	s_i_range->range = 0;
	return (s_i_range);
}

/*
** Analyzes the size of stack A to determine an adequate chunk size using sqrt.
**
** @param size_a The number of elements currently in stack A.
** @return The calculated optimal range size (integer square root).
*/
static int	select_range(int size_a)
{
	return (ft_sqrt(size_a));
}

/*
** Optimizes pushing elements to B by doing simultaneous rotate or rotate B,
** depending on the current element in A versus the calculated chunk bounds.
**
** @param l_stack_a Double pointer to stack A.
** @param l_stack_b Double pointer to stack B.
** @param s_i_range Pointer to the struct holding current range indices.
** @param data Pointer to benchmark struct tracking operations.
** @return 0 if simultaneous rotate (rr) was used, 1 if rotate B (rb) was used.
*/
static int	do_rr_or_rb(t_stack **l_stack_a, t_stack **l_stack_b,
		t_i_range	*s_i_range, t_data_bench *data)
{
	if (*l_stack_a && (*l_stack_a)->idx > (s_i_range->i + s_i_range->range))
	{
		rr(l_stack_a, l_stack_b, data);
		return (0);
	}
	else
	{
		rb(l_stack_b, data);
		return (1);
	}
}

/*
** Handles sorting for stacks larger than 5 elements using chunk ranges.
** 1. Calculates a range using selection_range.
** 2. Pushes all A elements to B via pre-selection:
**    - If index is in the current range, pushes to the top of B.
**    - If in the next immediate range, pushes to the bottom of B.
**    - Otherwise rotates A.
** 3. Pushes the highest nodes back from B to A until B is empty.
**
** @param l_stack_a Double pointer to stack A.
** @param l_stack_b Double pointer to stack B.
** @param data Pointer to benchmark struct tracking operations.
*/
void	chunk_sort(t_stack **l_stack_a, t_stack **l_stack_b, t_data_bench *data)
{
	t_i_range	*s_i_range;

	s_i_range = init_i_range();
	s_i_range->i = 0;
	s_i_range->range = select_range(list_size(*l_stack_a));
	while (*l_stack_a)
	{
		if ((*l_stack_a)->idx <= s_i_range->i)
		{
			pb(l_stack_a, l_stack_b, data);
			s_i_range->i++;
		}
		else if ((*l_stack_a)->idx <= (s_i_range->range + s_i_range->i))
		{
			pb(l_stack_a, l_stack_b, data);
			do_rr_or_rb(l_stack_a, l_stack_b, s_i_range, data);
			s_i_range->i++;
		}
		else
			ra(l_stack_a, data);
	}
	while (*l_stack_b)
		push_smart_to_a(l_stack_a, l_stack_b, data);
	free(s_i_range);
}
