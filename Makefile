# Nome programma finale
NAME	= push_swap

# Regole compilatore e flag
CC	= cc
CFLAGS	= -Wall -Werror -Wextra -g

# Make per compilare LIBFT e PRINTF
MAKE	= make

# Regole per la pulizia
RM	= rm -f

# --------------------------------------------------------------
#			LIBFT
# --------------------------------------------------------------

LIBFT_DIR	= ./libft
LIBFT_A		= $(LIBFT_DIR)/libft.a

# Flag per il linker (collegamento):
# -L : Indica al compilatore in quale cartella cercare la libreria (es. -L./libft).
# -l : Indica il nome della libreria da cercare (aggiunge in automatico 'lib' e '.a').
LIBFT_FLAG	= -L$(LIBFT_DIR) -lft

# --------------------------------------------------------------
# 			 LIBFTPRINTF
# --------------------------------------------------------------
PRINTF_DIR	= ./libftprintf
PRINTF_A	= $(PRINTF_DIR)/libftprintf.a
PRINTF_FLAG	= -L$(PRINTF_DIR) -lftprintf

# Flag per includere gli header (.h):
# -I (Include) : Dice al compilatore in quali cartelle cercare i file .h usati nel codice.
INC_LIB	= -I./includes -I$(LIBFT_DIR) -I$(PRINTF_DIR)

# Variabile che contiene tutti i file sorgente di push_swap
SRCS	= check_list.c fnct_list.c error.c op_push.c op_shift_rotate.c utils_nbr.c calculate_cost.c\
	  op_shift_rotate_reverse.c op_swap.c utils_sort.c init_list.c bench.c sort_big.c turk_sort.c get_target_node.c\
	  sort_three.c sort_five.c sort_stack.c smart_sort.c main.c disorder.c sort_max_min_extraction.c

# Sostituzione di testo: cambia le estensioni della stringa da .c a .o
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

# Regola per trasformare fisicamente ogni file sorgente (.c) nel rispettivo oggetto (.o).
# Variabili automatiche di Make:
# $< : Rappresenta il primo prerequisito (il file .c).
# $@ : Rappresenta il target (il file .o).
# Flag utilizzate:
# -c : Compila il file .c in .o senza tentare di creare l'eseguibile finale (niente linking).
# -o : Specifica al compilatore come chiamare il file in uscita.
%.o: %.c
	$(CC) $(CFLAGS) $(INC_LIB) -c $< -o $@

# Regola per entrare nella cartella di libft ed eseguire il suo Makefile interno:
# -C : Change directory. Si sposta nella cartella specificata prima di lanciare make.
$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

# Regola per entrare nella cartella di libftprintf ed eseguire il suo Makefile
$(PRINTF_A): 
	$(MAKE) -C $(PRINTF_DIR) -b

# Regola principale per creare l'eseguibile push_swap.
# Dipende dalla creazione di libft.a, libftprintf.a e di tutti i file .o
# Se manca qualcosa, le regole precedenti verranno eseguite in automatico.
$(NAME): $(LIBFT_A) $(PRINTF_A) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAG) $(PRINTF_FLAG) -o $(NAME)

clean: 
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
