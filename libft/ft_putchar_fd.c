#include "libft.h"

/* Sends a single character 'c' to file descriptor 'fd' via the
 * 'write()' system call. 
 * It passes the address of the character (&c) as the source buffer
 * and specifies a size of 1 byte. It allows output to be directed to
 * standard output (1), standard error (2), or previously opened files. */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
