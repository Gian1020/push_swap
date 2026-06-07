/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 19:57:42 by gipimpin          #+#    #+#             */
/*   Updated: 2026/06/07 19:58:29 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates and returns a new node, initializing the ‘content’ member 
 * with the value of the parameter and the ‘next’ member to NULL. 
 * Handles any allocation failures by returning NULL.
 * */
t_list	*ft_lstnew(void *content)
{
	t_list	*dst;

	dst = (t_list *) malloc (sizeof(t_list));
	if (!dst)
		return (NULL);
	dst->content = content;
	dst->next = NULL;
	return (dst);
}
