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

# include "../get_next_line/get_next_line.h"
# include "../push_swap.h"

void    sa_b(t_stack **l_stack_a);
void    sb_b(t_stack **l_stack_b);
void    ss_b(t_stack **l_stack_a, t_stack **l_stack_b);

void    rra_b(t_stack **l_stack_a);
void    rrb_b(t_stack **l_stack_b);
void    rrr_b(t_stack **l_stack_a, t_stack **l_stack_b);

void    ra_b(t_stack **l_stack_a);
void    rb_b(t_stack **l_stack_b);
void    rr_b(t_stack **l_stack_a, t_stack **l_stack_b);

void    pb_b(t_stack **l_stack_a, t_stack **l_stack_b);
void    pa_b(t_stack **l_stack_a, t_stack **l_stack_b);

void	is_ok_or_ko(t_stack **l_stack_a, t_stack **l_stack_b, char *line);
void	result(t_stack **l_stack_a, t_stack **l_stack_b, char *line, char *msg);
#endif