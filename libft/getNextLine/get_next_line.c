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

/*función q lee el contenido del archivo asociado al fd y almacena la línea
 en el puntero current_line. La función utiliza un buffer para leer el archivo en
  bloques definidos por BUFFER_SIZE y luego concatena el contenido del
   buffer a la línea hasta encontrar un salto de línea o hasta que se 
   llegue al final del archivo.*/
char	*ft_read_and_append_line(int fd, char *current_line)
{
	ssize_t	read_bytes;
	char	*buffer;

	read_bytes = 1;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(buffer);
		free(current_line);
		return (0);
	}
	while (!ft_strchr2(current_line, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if ((read_bytes == 0 && current_line == NULL) || read_bytes == -1)
		{
			free(buffer);
			return (current_line = ft_free_cl(current_line));
		}
		if (buffer > 0)
			buffer[read_bytes] = '\0';
		current_line = ft_strjoin2(current_line, buffer);
	}
	free(buffer);
	return (current_line);
}

/*La función ft_extract_next_line crea una nueva cadena que contiene todo el 
contenido de la línea después del primer salto de línea encontrado en la cadena
original. Es decir, elimina la primera línea de la cadena original y devuelve
el resto.*/
char	*ft_extract_next_line(char *line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (!str)
	{
		free(line);
		return (NULL);
	}
	i++;
	j = 0;
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	free(line);
	return (str);
}

char	*ft_get_line_from_cl_extend(char *current_line, char *str)
{
	int	i;

	i = 0;
	while (current_line[i] && current_line[i] != '\n')
	{
		str[i] = current_line[i];
		i++;
	}
	if (current_line[i] == '\n')
	{
		str[i] = current_line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*La función ft_get_line_from_fd extrae la primera línea de la cadena pasada 
como argumento y la devuelve en una nueva cadena.*/
char	*ft_get_line_from_cl(char *current_line)
{
	int		i;
	char	*str;

	i = 0;
	if (!current_line[i])
		return (NULL);
	while (current_line[i] && current_line[i] != '\n')
		i++;
	if (current_line[i] == '\n')
	{
		str = (char *)malloc(i + 2);
		if (!str)
			return (NULL);
	}
	else
	{
		str = (char *)malloc(i + 1);
		if (!str)
			return (NULL);
	}
	str = ft_get_line_from_cl_extend(current_line, str);
	return (str);
}

/*
función principal que se utilizará para obtener la siguiente línea del archivo. 
Llama a ft_read_and_append_line para leer el contenido del archivo y almacenarlo 
en current_line, luego llama a ft_get_line_from_fd para extraer la primera línea 
y finalmente llama a ft_extract_next_line para eliminar la línea extraída de line
.*/
char	*get_next_line(int fd)
{
	static char	*current_line;
	char		*next_line;

	if (fd < 0)
		return (NULL);
	current_line = ft_read_and_append_line(fd, current_line);
	if (!current_line)
		return (NULL);
	next_line = ft_get_line_from_cl(current_line);
	if (!next_line)
	{
		free(current_line);
		current_line = NULL;
	}
	else
		current_line = ft_extract_next_line(current_line);
	return (next_line);
}

/* --------------------- Main function --------------------- */

/*int	main(void)
{
	int		fd;
	char	*line_result;

	fd = open("only_nl.txt", O_RDONLY);
	while ((line_result = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line_result);
		free(line_result);
	}
	close(fd);
	return (0);
}*/

