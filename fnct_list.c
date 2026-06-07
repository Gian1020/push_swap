/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnct_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 18:42:03 by marvin            #+#    #+#             */
/*   Updated: 2026/06/07 19:57:53 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		handle_error(begin, NULL, NULL);
		return (1);
	}
	if (!*begin)
	{
		*begin = new;
		return (0);
	}
	last = list_last(*begin);
	new->prev = last;
	last->next = new;
	return (0);
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
/*
//Stampa il valore e l'indice della lista, utile per il debug.
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
		ft_printf("idx : %d\n",begin->idx);
		begin = begin->next;
	}
	ft_printf("------------------------\n");
}*/

/* Restituisce l'ultimo nodo della lista.*/
t_stack	*list_last(t_stack *begin)
{
	while ((begin)->next != NULL)
		begin = begin->next;
	return (begin);
}

void	insert_curr_pos(t_stack *l_stack)
{
	int		i;
	t_stack	*temp;

	if (!l_stack)
		return ;
	i = 0;
	temp = l_stack;
	while (temp != NULL)
	{
		temp->curr_pos = i;
		i++;
		temp = temp->next;
	}
}
