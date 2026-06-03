/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:23:17 by gpecelli          #+#    #+#             */
/*   Updated: 2026/06/03 17:23:17 by gpecelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Inserts the 'new' node at the beginning of the linked list.
 * Sets the 'next'' pointer of the new element to point to the current
 * head of the list (*lst), then updates the root pointer of the
 * structure so that 'new' becomes the first node.
 * Safely handles NULL inputs to prevent illegal dereferencing.
 * */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
