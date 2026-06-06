# Nome programma finale
NAME	= push_swap

# Regole compilatore e flag
CC	= cc
CFLAGS	= -Wall -Werror -Wextra

# Make per compilare LIBFT e PRINTF
MAKE	= make

# Regole per la pulizia
RM	= rm -f

# --------------------------------------------------------------
# 							LIBFT
# --------------------------------------------------------------

LIBFT_DIR	= ./libft
LIBFT_A		= $(LIBFT_DIR)/libft.a
# Flag per il linker (collegamento):
# -L : Indica al compilatore in quale cartella cercare la libreria (es. -L./libft).
# -l : Indica il nome della libreria da cercare (aggiunge in automatico 'lib' e '.a').
LIBFT_FLAG	= -L$(LIBFT_DIR) -lft

# Flag per includere gli header (.h):
# -I (Include) : Dice al compilatore in quali cartelle cercare i file .h usati nel codice.
INC_LIB	= -I./includes -I$(LIBFT_DIR)

# Variabile che contiene tutti i file sorgente di push_swap
SRCS	= check_list.c fnct_list.c error.c op_push.c sort_max_min_extraction.c bench_writer.c\
		  op_shift_rotate.c op_shift_rotate_reverse.c op_swap.c utils_sort.c init_list.c\
		  sort_three.c sort_five.c sort_stack.c main.c utils_nbr.c find_max_min.c disorder.c\
		  check_flag.c

FILES_CHUNK = chunk_sort.c smart_sort.c

FILES_TURK = cost.c move_turk.c target.c turk_sort.c cheap.c

# Aggiunta dei prefissi per i percorsi
SRC_CHUNK = $(addprefix chunk/, $(FILES_CHUNK))
SRC_TURK = $(addprefix turk/, $(FILES_TURK))

# Uniamo TUTTI i sorgenti in un'unica variabile
ALL_SRCS = $(SRCS) $(SRC_CHUNK) $(SRC_TURK)

# Sostituzione di testo: cambia le estensioni della stringa da .c a .o
OBJS	= $(ALL_SRCS:.c=.o)

all: $(NAME)

# Regola per trasformare fisicamente ogni file sorgente (.c) nel rispettivo oggetto (.o).
# Variabili automatiche di Make:
# $< : Rappresenta il primo prerequisito (il file .c).
# $@ : Rappresenta il target (il file .o).
# Flag utilizzate:
# -c : Compila il file .c in .o senza tentare di creare l'eseguibile finale (niente linking).
# -o : Specifica al compilatore come chiamare il file in uscita.
%.o: %.c
	$(CC)  $(CFLAGS) $(INC_LIB) -c $< -o $@

# Regola per entrare nella cartella di libft ed eseguire il suo Makefile interno:
# -C : Change directory. Si sposta nella cartella specificata prima di lanciare make.
$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

# Regola principale per creare l'eseguibile push_swap.
# Dipende dalla creazione di libft.a, libftprintf.a e di tutti i file .o
# Se manca qualcosa, le regole precedenti verranno eseguite in automatico.
$(NAME): $(LIBFT_A) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAG) -o $(NAME)

clean: 
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
