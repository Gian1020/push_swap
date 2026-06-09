/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:57:38 by gipimpin          #+#    #+#             */
/*   Updated: 2026/06/07 19:58:04 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
** Determines whether to push the first or second maximum value from B to A
** based on which operation sequence requires the fewest moves.
**
** @param pos_first_max Index position of the true maximum element.
** @param pos_sec_max Index position of the second maximum element.
** @param size The current number of elements in stack B.
** @return 1 to push first max, 2 to push second max, or -1 on error.
*/
int	smart_choice(int pos_first_max, int pos_sec_max, int size)
{
	int	cost_first;
	int	cost_sec;

	if (pos_first_max == -1)
		return (-1);
	if (pos_sec_max == -1)
		return (1);
	if (pos_first_max > size / 2)
		cost_first = size - pos_first_max;
	else
		cost_first = pos_first_max;
	if (pos_sec_max > size / 2)
		cost_sec = size - pos_sec_max;
	else
		cost_sec = pos_sec_max;
	if (cost_sec < cost_first)
		return (2);
	return (1);
}

/*
** Chooses between simultaneous swap (ss) or swap A (sa) to optimize moves
** when evaluating the top of the stacks.
**
** @param l_stack_a Double pointer to stack A.
** @param l_stack_b Double pointer to stack B.
** @param data Pointer to benchmark tracking structure.
*/
static void	do_ss_or_sa(t_stack **l_stack_a, t_stack **l_stack_b,
			t_data_bench *data)
{
	if (*l_stack_b && (*l_stack_b)->next
		&& (*l_stack_b)->idx < (*l_stack_b)->next->idx)
		ss(l_stack_a, l_stack_b, data);
	else
		sa(l_stack_a, data);
}

/*
** Executes the secondary fallback strategy when pushing smart from B to A.
** Brings the second maximum to the top, pushes it, then handles the max.
**
** @param l_stack_a Double pointer to stack A.
** @param l_stack_b Double pointer to stack B.
** @param pos_max Pointer to structure maintaining maximum positions.
** @param data Pointer to benchmark tracking structure.
*/
static void	second_choice(t_stack **l_stack_a, t_stack **l_stack_b,
			t_pos_max	*pos_max, t_data_bench *data)
{
	bring_to_top_b(l_stack_b, pos_max->pos_max_1, data);
	pa(l_stack_a, l_stack_b, data);
	pos_max->pos_max = get_pos_idx_max(*l_stack_b, -1);
	bring_to_top_b(l_stack_b, pos_max->pos_max, data);
	pa(l_stack_a, l_stack_b, data);
	do_ss_or_sa(l_stack_a, l_stack_b, data);
}

/*
** Main function to smartly extract and push elements from B to A.
** Finds the two max values and calculates the most efficient way to push them.
**
** @param l_stack_a Double pointer to stack A.
** @param l_stack_b Double pointer to stack B.
** @param data Pointer to benchmark tracking structure.
*/
void	push_smart_to_a(t_stack **l_stack_a, t_stack **l_stack_b,
			t_data_bench *data)
{
	int			size;
	t_pos_max	*pos_max;
	int			choice;

	size = list_size(*l_stack_b);
	if (!size)
		return ;
	pos_max = init_pos_max();
	pos_max->pos_max = get_pos_idx_max(*l_stack_b, -1);
	pos_max->pos_max_1 = get_pos_idx_max(*l_stack_b, size - 1);
	if (size >= 2 && pos_max->pos_max_1 == 0 && pos_max->pos_max == 1)
	{
		sb(l_stack_b, data);
		pos_max->pos_max = 0;
		pos_max->pos_max_1 = 1;
	}
	choice = smart_choice(pos_max->pos_max, pos_max->pos_max_1, size);
	if (choice == 1)
	{
		bring_to_top_b(l_stack_b, pos_max->pos_max, data);
		pa(l_stack_a, l_stack_b, data);
	}
	else if (choice == 2)
		second_choice(l_stack_a, l_stack_b, pos_max, data);
	free(pos_max);
}
