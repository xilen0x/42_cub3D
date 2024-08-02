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

void	parsing_colors(t_colors *colors, t_map *map)
{
	char	*line_trimed;
	int		color_value;
	char	**temp;
	char	**temp2;
	char	*color;
	int		i;
	char	*line;

	line = get_next_line(map->map_fd);
	while (line)
	{
		if (line[0] == '\n')
		{
			free(line);
			line = get_next_line(map->map_fd);
			continue ;
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
						free_elements(temp2);
						free(line);
						free(line_trimed);
						close(map->map_fd);
						return ;
					}
					i++;
				}
				if (ft_strncmp(temp[0], "F", 1) == 0)
				{
					colors->f = 1;
					color = ft_strtrim(temp2[0], " ");
					colors->f_color[0] = ft_atoi(color);
					free(color);
					color = ft_strtrim(temp2[1], " ");
					colors->f_color[1] = ft_atoi(color);
					free(color);
					color = ft_strtrim(temp2[2], " ");
					colors->f_color[2] = ft_atoi(color);
					free(color);
				}
				else if (ft_strncmp(temp[0], "C", 1) == 0)
				{
					colors->c = 1;
					color = ft_strtrim(temp2[0], " ");
					colors->c_color[0] = ft_atoi(color);
					free(color);
					color = ft_strtrim(temp2[1], " ");
					colors->c_color[1] = ft_atoi(color);
					free(color);
					color = ft_strtrim(temp2[2], " ");
					colors->c_color[2] = ft_atoi(color);
					free(color);
				}
				if (colors->f && colors->c)
				{
					free_elements(temp);
					free_elements(temp2);
					free(line);
					free(line_trimed);
					close(map->map_fd);
					return ;
				}
			}
			else
			{
				free_elements(temp);
				free_elements(temp2);
				free(line);
				free(line_trimed);
				line = get_next_line(map->map_fd);
				continue ;
			}
		}
		else
		{
			ft_printf("\nError de sintaxis en colores!\n");
			free(line);
			free(line_trimed);
			free_elements(temp);
			free_elements(temp2);
			close(map->map_fd);
			return ;
		}
		free(line_trimed);
		free_elements(temp);
		free_elements(temp2);
		free(line);
		line = get_next_line(map->map_fd);
	}
	close(map->map_fd);
}
