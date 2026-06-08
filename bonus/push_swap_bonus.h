/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecelli <gpecelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:59:30 by gpecelli          #+#    #+#             */
/*   Updated: 2026/06/08 17:00:45 by gpecelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

#include "../get_next_line/get_next_line.h"
#include "../push_swap.h"


int	sa_b(t_stack **l_stack_a);
int	sb_b(t_stack **l_stack_b);
int	ss_b(t_stack **l_stack_a, t_stack **l_stack_b);

int	rra_b(t_stack **l_stack_a);
int	rrb_b(t_stack **l_stack_b);
int	rrr_b(t_stack **l_stack_a, t_stack **l_stack_b);

int	ra_b(t_stack **l_stack_a);
int	rb_b(t_stack **l_stack_b);
int	rr_b(t_stack **l_stack_a, t_stack **l_stack_b);

int	pb_b(t_stack **l_stack_a, t_stack **l_stack_b);
int	pa_b(t_stack **l_stack_a, t_stack **l_stack_b);
#endif