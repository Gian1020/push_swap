#include "push_swap.h"

/* Crea un nuovo elemento della lista usando malloc,
 * setta tutti i valori di default.
 * idx -> -1 perché 0 rappresenta il primo nodo della lista.*/
t_stack	*new_node(int value)
{
	t_stack	*node;

	node = (t_stack *) malloc (sizeof(t_stack));
	if (!node)
		return (NULL);
	node->idx = -1;
	node->value = value;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

/* Inserisce un nuovo nodo alla fine della lista rispettando l'ordine.
 * Gestisce l'inizializzazione se la lista è vuota.*/
int	list_push_back(t_stack **begin, int value)
{
	t_stack	*new;
	t_stack	*last;

	if (!begin)
		return (0);
	new = new_node(value);
	if (!new)
	{
		handle_error(begin, NULL);
		return (0);
	}
	if (!*begin)
	{
		*begin = new;
		return (1);
	}
	last = list_last(*begin);
	new->prev = last;
	last->next = new;
	return (1);
}

/* Si posiziona sulla testa e dealloca ogni nodo iterativamente. 
 * Facendo attenzione a non rompere la sequenza.*/
void	list_clear(t_stack **node)
{
	t_stack	*temp;

	if (!node || !*node)
		return ;
	while ((*node)->prev)
		*node = (*node)->prev;
	while (*node != NULL)
	{
		temp = (*node)->next;
		free(*node);
		*node = temp;
	}
	*node = NULL;
}
/* Restituisce il numero nodi della lista.*/
int	list_size(t_stack *begin)
{
	int	i;

	i = 0;
	while (begin != NULL)
	{
		i++;
		begin = begin->next;
	}
	return (i);
}

/* Stampa il valore e l'indice della lista, utile per il debug.*/
void	print_list(t_stack *begin, char *label)
{
	ft_printf("----------%s----------\n", label);
	if (!begin)
	{
		ft_printf("(stack vuoto)\n");
		return ;
	}
	while (begin != NULL)
	{
		ft_printf("n : %d || ", begin->value);
		ft_printf("idx : %u\n",begin->idx);
		begin = begin->next;
	}
	ft_printf("------------------------\n");
}

/* Restituisce l'ultimo nodo della lista.*/
t_stack	*list_last(t_stack *begin)
{
	while((begin)->next != NULL)
		begin = begin->next;
	return (begin);
}
