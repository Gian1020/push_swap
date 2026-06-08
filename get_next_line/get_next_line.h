/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipimpin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 12:46:04 by gipimpin          #+#    #+#             */
/*   Updated: 2026/05/22 19:22:45 by gipimpin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(char *str);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	*read_and_allocates(int fd, char *stash);
char	*ft_clean_stash(char *stash, int i);
char	*ft_extract_line(char *stash);

#endif
