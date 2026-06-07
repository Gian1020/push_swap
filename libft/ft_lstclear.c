/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:57:41 by gipimpin          #+#    #+#             */
/*   Updated: 2026/06/07 19:58:27 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * Deletes and frees the entire linked list pointed to by '*lst'.
 * It uses the del() to clear the contents of each node and then frees
 * the node structure itself using 'free'. It uses a
 * 'next' to save the reference to the next node before
 * deallocating the current one. At the end of the operation,
 * reset the original pointer (*lst = NULL) to avoid dangling pointers. 
 * */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*curr;
	t_list	*next;

	if (!lst || !del)
		return ;
	curr = *lst;
	while (curr != 0)
	{
		next = curr->next;
		del(curr->content);
		free(curr);
		curr = next;
	}
	*lst = NULL;
}
