/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnct_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 18:42:03 by marvin            #+#    #+#             */
/*   Updated: 2026/06/07 19:57:53 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Inserts a new node at the end of the list, maintaining the order.
** Handles list initialization if it's currently empty.
**
** @param begin Double pointer to the first node of the list.
** @param value The integer value to be assigned to the new node.
** @return 0 on success, 1 on allocation failure.
*/
int	list_push_back(t_stack **begin, int value)
{
	t_stack	*new;
	t_stack	*last;

	if (!begin)
		return (0);
	new = new_node(value);
	if (!new)
	{
		handle_error(begin, NULL, NULL);
		return (1);
	}
	if (!*begin)
	{
		*begin = new;
		return (0);
	}
	last = list_last(*begin);
	new->prev = last;
	last->next = new;
	return (0);
}

/*
** Positions at the head and iteratively deallocates each node,
** taking care not to break the sequence during traversal.
**
** @param node Double pointer to any node in the list.
*/
void	list_clear(t_stack **node)
{
	t_stack	*temp;

	if (!node || !*node)
		return ;
	while ((*node)->prev)
		*node = (*node)->prev;
	while (*node != NULL)
	{
		temp = (*node)->next;
		free(*node);
		*node = temp;
	}
	*node = NULL;
}

/*
** Returns the total number of nodes currently in the list.
**
** @param begin Pointer to the first node of the list.
** @return The integer count of nodes in the list.
*/
int	list_size(t_stack *begin)
{
	int	i;

	i = 0;
	while (begin != NULL)
	{
		i++;
		begin = begin->next;
	}
	return (i);
}
/*
** Prints the value and index of the list elements, useful for debugging.
void	print_list(t_stack *begin, char *label)
{
	ft_printf("----------%s----------\n", label);
	if (!begin)
	{
		ft_printf("(stack vuoto)\n");
		return ;
	}
	while (begin != NULL)
	{
		ft_printf("n : %d || ", begin->value);
		ft_printf("idx : %d\n",begin->idx);
		begin = begin->next;
	}
	ft_printf("------------------------\n");
}*/

/*
** Returns a pointer to the last node of the list.
**
** @param begin Pointer to the first node of the list.
** @return A pointer to the last node, or NULL if the list is empty.
*/
t_stack	*list_last(t_stack *begin)
{
	while ((begin)->next != NULL)
		begin = begin->next;
	return (begin);
}

/*
** Iterates through the list and assigns each node its current position index.
**
** @param l_stack Pointer to the first node of the stack.
*/
void	insert_curr_pos(t_stack *l_stack)
{
	int		i;
	t_stack	*temp;

	if (!l_stack)
		return ;
	i = 0;
	temp = l_stack;
	while (temp != NULL)
	{
		temp->curr_pos = i;
		i++;
		temp = temp->next;
	}
}
