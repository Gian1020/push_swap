# 1. Variabili
NAME    = libftprintf.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
LIB_CMD = ar rc
RM      = rm -f

# 2. Directory e File
INC_DIR = includes
BONUS_DIR = bonus

# Lista dei file sorgente parte mandatoria
SRC_FILES = ft_printf.c ft_print_csdiu.c ft_utils.c ft_print_xXp.c

# Lista dei file sorgente parte bonus
SRC_FILES_BONUS = ft_printf_bonus.c ft_print_s_bonus.c ft_print_c_bonus.c \
                  ft_utils_bonus.c ft_utils_nbr_bonus.c ft_utils_print_int_hex_bonus.c \
                  ft_struct_bonus.c ft_print_diu_bonus.c ft_print_xX_bonus.c \
                  ft_print_p_bonus.c

# Inserisco il path perché la parte bonus è in una sotto cartella
SRC_BONUS = $(addprefix $(BONUS_DIR)/, $(SRC_FILES_BONUS))

# I file .o devono essere vicini ai .c
OBJS       = $(SRC_FILES:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)

# 3. Regole principali
all: $(NAME)

$(NAME): $(OBJS)
	$(LIB_CMD) $(NAME) $(OBJS)
	ranlib $(NAME)

# La regola bonus richiede gli oggetti bonus, li archivia nella libreria e aggiorna l'indice
bonus: $(OBJS_BONUS)
	$(LIB_CMD) $(NAME) $(OBJS_BONUS)
	ranlib $(NAME)

# Regola per compilare i .c in .o
# Usiamo -I per l'header in includes/
%.o: %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

# 4. Regole di pulizia
clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

# 5. Regola di ricompilazione
re: fclean all

# Protezione per i target che non sono veri file
.PHONY: all clean fclean re bonus
