#include "libft.h"

/* Adds the 'new' node to the end of the linked list.
 * If the list is initially empty (*lst == NULL), the new node is
 * set as the head of the list by dereferencing the double
 * pointer. Otherwise, it scans the list to the last node
 * (tail) and updates its 'next' pointer to include the 'new' element. */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	curr = *lst;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
}
