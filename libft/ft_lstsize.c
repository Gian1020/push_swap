#include "libft.h"

/*
 * Calculates the length of the list.
 * Returns the total number of nodes counted up to the NULL terminator.
 * */
int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*curr;

	i = 0;
	curr = lst;
	while (curr != NULL)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}
