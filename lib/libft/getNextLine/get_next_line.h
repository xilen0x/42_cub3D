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
#  define BUFFER_SIZE 1024
# endif

# include "../libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>

char	*get_next_line(int fd);

#endif
