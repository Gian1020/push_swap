#include "libft.h"

/*
 * Applies the call to 'f()' to the 'content' member
 * of each node in the 'lst' list.
 * Includes a guard clause to prevent dereferencing NULL pointers.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*curr;

	if (!lst || !f)
		return ;
	curr = lst;
	while (curr != NULL)
	{
		f(curr->content);
		curr = curr->next;
	}
}
