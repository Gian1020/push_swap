/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:57:42 by gipimpin          #+#    #+#             */
/*   Updated: 2026/06/07 19:58:28 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Returns the address of the last node of the 'lst' list. 
 * Handles the edge case of a NULL input and traverses 
 * the list until it reaches the element with a 'next' == NULL member. */
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lst_last;

	if (!lst)
		return (NULL);
	lst_last = lst;
	while (lst_last->next != NULL)
		lst_last = lst_last->next;
	return (lst_last);
}
