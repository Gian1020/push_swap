# Nome programma finale
NAME		= push_swap
NAME_BONUS	= checker

# Compilatore e flag
CC		= cc
CFLAGS		= -Wall -Werror -Wextra
MAKE		= make
RM		= rm -f

# --------------------------------------------------------------
#							LIBFT
# --------------------------------------------------------------
LIBFT_DIR	= ./libft
LIBFT_A		= $(LIBFT_DIR)/libft.a
LIBFT_FLAG	= -L$(LIBFT_DIR) -lft
INC_LIB = -I./includes -I$(LIBFT_DIR) -I./get_next_line

# --------------------------------------------------------------
#							GET_NEXT_LINE
# --------------------------------------------------------------
GET_NEXT_LINE_SRCS	= get_next_line.c get_next_line_utils.c
GET_NEXT_LINE_DIR	= $(addprefix get_next_line/, $(GET_NEXT_LINE_SRCS))

# --------------------------------------------------------------
#							PUSH_SWAP
# --------------------------------------------------------------
SRCS		= check_list.c fnct_list.c error.c op_push.c \
			  sort_max_min_extraction.c bench_writer.c \
			  op_shift_rotate.c op_shift_rotate_reverse.c op_swap.c \
			  utils_sort.c init_list.c sort_three.c sort_five.c \
			  sort_stack.c main.c utils_nbr.c find_max_min.c \
			  disorder.c check_flag.c create_stack.c

FILES_CHUNK	= chunk_sort.c smart_sort.c
FILES_TURK	= cost.c move_turk.c target.c turk_sort.c cheap.c

SRC_CHUNK	= $(addprefix chunk/, $(FILES_CHUNK))
SRC_TURK	= $(addprefix turk/, $(FILES_TURK))

ALL_SRCS	= $(SRCS) $(SRC_CHUNK) $(SRC_TURK)
OBJS		= $(ALL_SRCS:.c=.o)

# --------------------------------------------------------------
#							CHECKER (BONUS)
# --------------------------------------------------------------
BONUS_SHARED	= op_shift_rotate_bonus.c op_shift_rotate_reverse_bonus.c op_swap_bonus.c \
				  op_push_bonus.c check_list.c check_flag.c create_stack.c \
				  error.c fnct_list.c utils_nbr.c find_max_min.c \
				  init_list.c disorder.c

SRCS_BONUS	= bonus/main_bonus.c $(BONUS_SHARED) $(GET_NEXT_LINE_DIR)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

# --------------------------------------------------------------
#							RULES
# --------------------------------------------------------------
all: $(NAME)

bonus: $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) $(INC_LIB) -c $< -o $@

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT_A) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAG) -o $(NAME)

$(NAME_BONUS): $(LIBFT_A) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT_FLAG) -o $(NAME_BONUS)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re