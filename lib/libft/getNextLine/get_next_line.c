/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:54:59 by castorga          #+#    #+#             */
/*   Updated: 2023/09/04 15:24:58 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin3(char *s1, char const *s2, size_t len)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*join;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = len;
	join = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!join)
		return (0);
	ft_strlcpy(join, s1, s1_len + 1);
	ft_strlcpy((join + s1_len), s2, s2_len + 1);
	free(s1);
	return (join);
}

char *get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	char		*newline;
	int			bytes_read;
	int			to_copy;

	line = ft_strdup(buf);
	while (!(ft_strchr(line, '\n')) && (bytes_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bytes_read] = '\0';
		line = ft_strjoin3(line, buf, bytes_read);
	}
	if (ft_strlen(line) == 0)
		return (free(line), NULL);

	newline = ft_strchr(line, '\n');
	if (newline != NULL)
	{
		to_copy = newline - line + 1;
		ft_strlcpy(buf, newline + 1, BUFFER_SIZE + 1);
	}
	else
	{
		to_copy = ft_strlen(line);
		ft_strlcpy(buf, "", BUFFER_SIZE + 1);
	}
	line[to_copy] = '\0';
	return (line);
}
