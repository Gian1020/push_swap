#include "libft.h"

/* Sends the string 's' followed by a newline character ('\n') to the file
 * descriptor 'fd'. Implements a preventive safety check to
 * prevent operations on NULL pointers. Leverages the library's modularity
 * by delegating output to ft_putstr_fd and ft_putchar_fd, ensuring consistency
 * and code reuse in the writing system. */
void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		ft_putstr_fd(s, fd);
		write(fd, "\n", 1);
	}
}
