#include "push_swap.h"

/* Verifica la presenza di valori duplicati nella lista.
 * Se ci sono fa tornare 1 altrimenti 0.*/
int	have_duplicate(t_stack *begin_list)
{
	t_stack	*next_node;

	if (!begin_list || !begin_list->next)
		return (0);
	while(begin_list != NULL)
	{
		next_node = begin_list->next;
		while(next_node != NULL)
		{
			if(begin_list->value == next_node->value)
				return (1);
			next_node = next_node->next;
		}
		begin_list = begin_list->next;
	}
	return (0);
}

/* Converte le stringa passata in INT gestendo segni e spazi.
 * Controlla se il valore calcolato supera i limiti degli interi.
 * In caso  non li rispetti setta la flag a 1.*/
int	atoi_check(char *str, int *flag_err)
{
	int	i;
	long long n;
	int	sign;

	i = 0;
	n = 0;
	sign = 1;
	while((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if(str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + str[i] - '0';
		if((n * sign) > INT_MAX || (n * sign) < INT_MIN)
		{
			*flag_err = 1;
			break;
		}
		i++;
	}
	return ((int)n * sign);
}
