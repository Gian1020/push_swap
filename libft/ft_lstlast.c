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
