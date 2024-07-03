/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:54:06 by castorga          #+#    #+#             */
/*   Updated: 2023/08/03 14:54:10 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "../libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_read_and_append_line(int fd, char *current_line);
char	*ft_extract_next_line(char *line);
char	*ft_get_line_from_cl(char *line);
char	*ft_strjoin2(char *line, char *buff);
char	*ft_strchr2(char *s, int c);
//size_t	ft_strlen(char *s);
//char	*ft_free_buf(char *buffer, char *current_line);
char	*ft_free_cl(char *current_line);

#endif
