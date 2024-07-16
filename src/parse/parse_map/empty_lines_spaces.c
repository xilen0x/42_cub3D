/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_lines_spaces.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:33:55 by castorga          #+#    #+#             */
/*   Updated: 2024/07/16 15:33:58 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

/*FUNCION QUE SALTA LAS LINEAS VACIAS del map almacenado en av[1]*/
// int	empty_lines_handler(t_map *map)
// {
// 	char	*line;
// 	size_t	len;

// 	line = get_next_line(map->map_fd);
// 	while (line)
// 	{
// 		len = ft_strlen(line);
// 		if (line[0] == '\0')
// 		{
// 			printf("empty line found\n");
// 			free(line);
// 			line = get_next_line(map->map_fd);
// 			continue ;
// 		}
// 		if (len > 0 && line[len - 1] == '\n')
// 			len--;
// 		free(line);
// 		line = get_next_line(map->map_fd);
// 	}
// 	return (0);
// }
