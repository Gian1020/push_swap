#include "../push_swap.h"

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

static void	do_ss_or_sa(t_stack **l_stack_a, t_stack **l_stack_b)
{
	if (*l_stack_b && (*l_stack_b)->next
		&& (*l_stack_b)->idx < (*l_stack_b)->next->idx)
		ss(l_stack_a, l_stack_b);
	else
		sa(l_stack_a);
}

static void	second_choice(t_stack **l_stack_a, t_stack **l_stack_b,
		int pos_max, int pos_max_1)
{
	bring_to_top_b(l_stack_b, pos_max_1);
	pa(l_stack_a, l_stack_b);
	pos_max = get_pos_idx_max(*l_stack_b, -1);
	bring_to_top_b(l_stack_b, pos_max);
	pa(l_stack_a, l_stack_b);
	do_ss_or_sa(l_stack_a, l_stack_b);
}

void	push_smart_to_a(t_stack **l_stack_a, t_stack **l_stack_b)
{
	int	size;
	int	pos_max;
	int	pos_max_1;
	int	choice;

	size = list_size(*l_stack_b);
	if (!size)
		return ;
	pos_max = get_pos_idx_max(*l_stack_b, -1);
	pos_max_1 = get_pos_idx_max(*l_stack_b, size - 1);
	if (size >= 2 && pos_max_1 == 0 && pos_max == 1)
	{
		sb(l_stack_b);
		pos_max = 0;
		pos_max_1 = 1;
	}
	choice = smart_choice(pos_max, pos_max_1, size);
	if (choice == 1)
	{
		bring_to_top_b(l_stack_b, pos_max);
		pa(l_stack_a, l_stack_b);
	}
	else if (choice == 2)
		second_choice(l_stack_a, l_stack_b, pos_max, pos_max_1);
}
