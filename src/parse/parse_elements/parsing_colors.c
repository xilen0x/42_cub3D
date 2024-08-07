/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:22:12 by castorga          #+#    #+#             */
/*   Updated: 2024/07/24 15:22:15 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing_colors_core(t_colors *colors, t_map *map, char *line)
{
	char	*line_trimed;
	int		color_value;
	char	**temp;
	char	**temp2;
	int		i;

	if (line[0] == '\n')
	{
		free(line);
		line = get_next_line(map->map_fd);
		return ;
	}
	remove_tabs_and_spaces(line);
	remove_spaces_around_commas(line);
	line_trimed = ft_strtrim2(line, " ", "\t");
	temp = ft_split(line_trimed, ' ');
	temp2 = ft_split(temp[1], ',');
	if (!temp2)
	{
		ft_printf("\nError de sintaxis en colores!******1\n");
		free(line);
		free(line_trimed);
		free_elements(temp);
		close(map->map_fd);
		return ;
	}
	i = 0;
	while (temp2[i])
		i++;
	if (i == 3)
	{
		if ((ft_strncmp(line_trimed, "F", 1) == 0) || (ft_strncmp(line_trimed, "C", 1) == 0))
		{
			i = 0;
			while (temp2[i])
			{
				color_value = ft_atoi(temp2[i]);
				if (color_value < MIN_COLOR_VALUE || color_value > MAX_COLOR_VALUE)
				{
					ft_printf("\nError de rango en colores!\n");
					free_elements(temp);
					free(line);
					free(line_trimed);
					close(map->map_fd);
					return ;
				}
				if (ft_strncmp(line_trimed, "F", 1) == 0)
					colors->f_color[i] = color_value;
				else
					colors->c_color[i] = color_value;
				i++;
			}
		}
		else
		{
			ft_printf("\nError de sintaxis en colores!******2\n");
			free_elements(temp);
			free(line);
			free(line_trimed);
			close(map->map_fd);
			return ;
		}
	}
	else
	{
		ft_printf("\nError de sintaxis en colores!******3\n");
		free_elements(temp);
		free(line);
		free(line_trimed);
		close(map->map_fd);
		return ;
	}
	free_elements(temp);
	free(line);
	free(line_trimed);
}

void	parsing_colors(t_colors *colors, t_map *map)
{
	char	*line;

	line = get_next_line(map->map_fd);
	while (line)
	{
		parsing_colors_core(colors, map, line);
		free(line);
		line = get_next_line(map->map_fd);
	}
	close(map->map_fd);
}
