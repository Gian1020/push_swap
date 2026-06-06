#ifndef GET_NEXT_LINE_H
# define GET_NEXTLINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define MAX_FD 1024

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t		ft_strlen(char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_get_next_line(int fd);
char	*read_and_allocates(int fd, char *stash);
char	*ft_clean_stash(char *stash, int i);
char	*ft_extract_line(char *stash);

#endif
