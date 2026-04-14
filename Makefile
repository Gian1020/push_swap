NAME	= push_swap.a
CC	= cc
FLAGS	= -Wall -Werror -Wextra
LIB_CMD	= ar rc
RM	= rm -f
INC_DIR	= includes

SRCS	= check_list.c fnct_list.c error.c op_push.c op_shift_rotate.c op_shift_rotate_reverse.c op_swap.c utils_sort.c sort_three.c sort_five.c sort_stack.c smart_sort.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(LIB_CMD) $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	$(CC)  $(FLAGS) -I $(INC_DIR) -c $< -o $@

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
