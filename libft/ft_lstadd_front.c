/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:57:41 by gipimpin          #+#    #+#             */
/*   Updated: 2026/06/07 19:58:27 by gipimpin         ###   ########.fr       */
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
