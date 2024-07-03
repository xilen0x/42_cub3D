/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:54:30 by castorga          #+#    #+#             */
/*   Updated: 2023/08/03 14:54:32 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_cl(char *current_line)
{
	free (current_line);
	current_line = NULL;
	return (NULL);
}

/* strchr(): Locates a character in a string. This finds the first occurrence
 of the desired character in a string or NULL if the character does not appear
  in the string.
*/
char	*ft_strchr2(char *current_line, int c)
{
	int	i;

	i = 0;
	if (!current_line)
		return (0);
	if (c == '\0')
		return ((char *)&current_line[ft_strlen(current_line)]);
	while (current_line[i] != '\0')
	{
		if (current_line[i] == (char) c)
			return ((char *)&current_line[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin2(char *line, char *buff)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!line)
	{
		line = (char *)malloc(sizeof(char));
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	str = malloc(sizeof(char) * ((ft_strlen(line) + ft_strlen(buff)) + 1));
	if (str != NULL)
	{
		while (line && line[++i] != '\0')
			str[i] = line[i];
		while (buff[j] != '\0')
			str[i++] = buff[j++];
		str[ft_strlen(line) + ft_strlen(buff)] = '\0';
	}
	free(line);
	return (str);
}
