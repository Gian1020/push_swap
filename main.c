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
			*flag_err = list_push_back(first, val);
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
	int		idx;
	t_stack	*l_stack_a;
	t_algo	*algo_flag;

	if (argc < 2)
		return (0);
	flag_err = 0;
	algo_flag = init_algo();
	set_flag_algo(argv[1], algo_flag);
	set_flag_algo(argv[2], algo_flag);
	idx = find_start_idx(argv, algo_flag);
	l_stack_a = argv_to_list(&argv[idx], &flag_err);
	if (!l_stack_a || flag_err || have_duplicate(l_stack_a))
		handle_error(&l_stack_a, NULL, algo_flag);
	fast_sort(l_stack_a);
	if (!is_sorted(l_stack_a))
		sort_stack(&l_stack_a, algo_flag);
	return (0);
}

//  #### A. Gestione dei Flag di avvio nel  main.c  (Parsing)

//  Al momento, se provi ad avviare il programma passando le flag richieste (es.  ./push_swap --simple 3 2 1 ),
//il programma andrà in errore ( Error\n ) perché  argv_to_list  cercherà di convertire  --simple  in
//  un   
//  numero.  

//  • Cosa fare: Devi modificare il  main.c  per:  
//  1. Riconoscere ed estrarre i parametri flag:  --simple ,  --medium ,  --complex ,  --adaptive ,  --bench .  
//  2. Inizializzare la struct  t_algo  (tramite  init_algo() ) impostando a  1  la flag passata (altrimenti, di default,  --adaptive  è attiva). 
//  3. Separare le flag dai veri numeri da ordinare, in modo che solo i numeri vengano passati a  argv_to_list .


//  #### B. Scegliere l'algoritmo in base alla Struct Algo e all'Indice di Disordine 

//  Nella funzione  sort_stack  (in sort_stack.c):   

//  • Se la flag è  --simple  (o se siamo in  --adaptive  e il disordine è  < 0.2 ): usa l'algoritmo semplice (es.  sort_max_min_extraction  o simile).   
//  • Se la flag è  --medium  (o se siamo in  --adaptive  e il disordine è  0.2 <= d < 0.5 ): usa  chunk_sort . 
//  • Se la flag è  --complex  (o se siamo in  --adaptive  e il disordine è  >= 0.5 ): usa il  turk_sort  (il Turkish algorithm).  

//  #### C. Gestione del Benchmark ( --bench )                                 
                                                                                                                                                                                                                 
//  • Mostrare l'output del benchmark (disordine, strategia, numero totale di mosse e conteggio mosse per tipo) inviandolo a  stderr  solo se la flag  --bench  è attiva.