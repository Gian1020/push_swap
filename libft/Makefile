# Target library name
NAME	= libft.a

# Compiler and base flags (strict compilation)
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

# Commands for static archive creation and file deletion
LIB_CMD	= ar rc
RM		= rm -f

# List of source files (includes both standard and linked list functions)
SRC_FILES   =	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
		ft_tolower.c ft_toupper.c ft_atoi.c ft_itoa.c ft_calloc.c ft_bzero.c\
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c\
		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strrchr.c\
		ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c\
		ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strchr.c ft_strtrim.c ft_substr.c\
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

# Pattern substitution: transforms every .c file into a .o file
OBJS	= $(SRC_FILES:.c=.o)

# Default rule: compiles the library
all: $(NAME)

# Static library creation: archives object files and creates the index (ranlib)
$(NAME): $(OBJS)
	$(LIB_CMD) $(NAME) $(OBJS)
	ranlib $(NAME)

# Generic compilation rule for object files.
# Uses $< (first prerequisite, the .c file) and $@ (the target, the .o file).
# Includes the headers directory using the -I flag.
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Removes generated object files
clean:
	$(RM) $(OBJS)

# Removes objects and the library itself
fclean: clean
	$(RM) $(NAME)

# Cleans everything and recompiles from scratch
re: fclean all

# Declares targets not associated with physical files to avoid name conflicts
.PHONY: all bonus clean fclean re
