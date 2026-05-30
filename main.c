#include "push_swap.h"

/* Libera una matrice allocata dinamicamente (char **).
 * Scorre ogni elemento fino al terminatore NULL, libera la memoria
 * di ogni stringa e infine libera l'array di puntatori.*/
static void	free_mtrx(char **mtrx)
{
	int	i;

	i = 0;
	if (!mtrx)
		return ;
	while (mtrx[i])
	{
		free(mtrx[i]);
		i++;
	}
	free(mtrx);
}

/* Popola lo stack convertendo i token di temp_split tramite atoi_check.
 * Interrompe l'inserimento al primo errore di validazione o overflow,
 * segnalando lo stato tramite flag_err. */
static void	fill_stack(t_stack **first, char **temp_split, int *flag_err)
{
	int	val;
	int	j;

	j = 0;
	while (temp_split[j] && !*flag_err)
	{
		val = atoi_check(temp_split[j], flag_err);
		if (!*flag_err)
			list_push_back(first, val);
		j++;
	}
}

/* Converte gli argomenti della riga di comando in una lista concatenata.
 *  1. Divide ogni stringa di argv in singoli token (gestione input misto).
 *  2. Valida e converte ogni token in intero (controllo overflow/formato).
 *  3. Inserisce i valori validi in fondo alla lista (fill_stack).
 *  4. Gestisce la liberazione della memoria temporanea e i flag di errore.*/
t_stack	*argv_to_list(char **argv, int *flag_err)
{
	int		i;
	char	**temp_split;
	t_stack	*first;

	i = 0;
	*flag_err = 0;
	first = NULL;
	while (argv[i] && !*flag_err)
	{
		temp_split = ft_split(argv[i], ' ');
		if (!temp_split)
		{
			*flag_err = 1;
			break ;
		}
		fill_stack(&first, temp_split, flag_err);
		free_mtrx(temp_split);
		i++;
	}
	return (first);
}

/* Assegna un indice relativo (0 a size-1) a ogni nodo dello stack.
 * Semplifica l'ordinamento trasformando i valori reali (anche grandi o negativi)
 * in una sequenza continua di interi.
 * Esegue una ricerca iterativa del valore minimo non ancora indicizzato
 * (quelli con idx == -1) e gli assegna il valore 'i' corrente.*/
static void	fast_sort(t_stack *begin_list)
{
	int		i;
	int		size;
	t_stack	*current;
	t_stack	*min_node;

	i = 0;
	size = list_size(begin_list);
	while (i < size)
	{
		current = begin_list;
		min_node = NULL;
		while (current != NULL)
		{
			if (current->idx == -1)
			{
				if (min_node == NULL || current->value < min_node->value)
					min_node = current;
			}
			current = current->next;
		}
		if (min_node != NULL)
			min_node->idx = i;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		flag_err;
	float	disorder;
	t_stack	*l_stack_a;

	if (argc < 2)
		return (0);
	flag_err = 0;
	l_stack_a = argv_to_list(&argv[1], &flag_err);
	if (!l_stack_a || flag_err || have_duplicate(l_stack_a))
		handle_error(&l_stack_a, NULL);
	fast_sort(l_stack_a);
	disorder = compute_disorder(l_stack_a);
	if (!is_sorted(l_stack_a))
		sort_stack(&l_stack_a);
	list_clear(&l_stack_a);
	return (0);
}
