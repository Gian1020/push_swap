/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:23:17 by gpecelli          #+#    #+#             */
/*   Updated: 2026/06/03 17:23:17 by gpecelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Frees the memory of a single list element passed as a parameter.
 * Uses the 'del' function to properly deallocate the 'content’' field,
 * preventing memory leaks if the content is itself allocated.
 * It then frees the node structure using 'free()'.
 * This function does't remove the node from the list or modify the 'next' field
 * */
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
