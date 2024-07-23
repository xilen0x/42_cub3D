/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:44:32 by castorga          #+#    #+#             */
/*   Updated: 2024/07/09 15:44:35 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	print_elements(t_elem *elem)
{
	printf("\nNO     : %s\n", elem->no);
	printf("NO_PATH: %s\n", elem->no_path);
	
	printf("\nSO     : %s\n", elem->so);
	printf("SO_PATH: %s\n", elem->so_path);
	
	printf("\nEA     : %s\n", elem->ea);
	printf("EA_PATH: %s\n", elem->ea_path);

	printf("\nWE     : %s\n", elem->we);
	printf("WE_PATH: %s\n", elem->we_path);
}

void	print_colors(t_colors *colors)
{
	printf("\nF      : %d\n", colors->f);
	printf("F_COLOR: %d, %d, %d\n", colors->f_color[0], colors->f_color[1], colors->f_color[2]);
	printf("\nC      : %d\n", colors->c);
	printf("C_COLOR: %d, %d, %d\n", colors->c_color[0], colors->c_color[1], colors->c_color[2]);
}

void save_elements(t_elem *elem, t_map *map)
{
    char *line;
    char **elements;
    char *temp;
	char *line_trimed;
	int i;
	int j;

    line = get_next_line(map->map_fd);
    while (line)
	{
        if (line[0] == '\n')
		{
            free(line);
            line = get_next_line(map->map_fd);
            continue ;
        }
		line_trimed = ft_strtrim2(line, " ", "\t");
        elements = ft_split2(line_trimed);
		texture_path_extension_is_valid(elements[1]);
		remove_tabs(elements);
		i = 0;
		while (elements[i])
			i++;
		j = 0;
		if (i == 2)
		{
			if (ft_strncmp(elements[0], "NO", 2) == 0)
			{
				j++;
				temp = ft_strtrim(elements[0], " ");
				elem->no = temp;
				temp = ft_strtrim(elements[1], " ");
				elem->no_path = temp;
			}
			else if (ft_strncmp(elements[0], "SO", 2) == 0)
			{
				j++;
				temp = ft_strtrim(elements[0], " ");
				elem->so = temp;
				temp = ft_strtrim(elements[1], " ");
				elem->so_path = temp;
			}
			else if (ft_strncmp(elements[0], "EA", 2) == 0)
			{
				j++;
				temp = ft_strtrim(elements[0], " ");
				elem->ea = temp;
				temp = ft_strtrim(elements[1], " ");
				elem->ea_path = temp;
			}
			else if (ft_strncmp(elements[0], "WE", 2) == 0)
			{
				j++;
				temp = ft_strtrim(elements[0], " ");
				elem->we = temp;
				temp = ft_strtrim(elements[1], " ");
				elem->we_path = temp;
			}
			if (elem->no && elem->so && elem->ea && elem->we)
			{
				free_elements(elements);
				free(line);
				close(map->map_fd);
				free(line_trimed);
				return ;
			}
		}
		else
		{
			printf("Error de sintaxis en elementos!\n");
			free_elements(elements);
			free(line);
			close(map->map_fd);
			free(line_trimed);
			return ;
		}
        free_elements(elements);
        free(line);
		free(line_trimed);
        line = get_next_line(map->map_fd);
    }
    close(map->map_fd);
}


void	save_colors(t_colors *colors, t_map *map)
{
	char *line;
	char *line_trimed;
	int	color_value;
	char **temp;
	char **temp2;
	char *color;
    int i;

	line = get_next_line(map->map_fd);
	while (line)
	{
		if (line[0] == '\n')
		{
			free(line);
			line = get_next_line(map->map_fd);
			continue ;
		}
		line_trimed = ft_strtrim2(line, " ", "\t");
		temp = ft_split(line_trimed, ' ');
		temp2 = ft_split(temp[1], ',');
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
						printf("\nError de rango en colores!\n");
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
			printf("\nError de sintaxis en colores!\n");
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

/*funcion que guarda en */
void	save_components(t_elem *elem, t_colors *colors, t_map *map, char *av[])
{
	save_elements(elem, map);
	print_elements(elem);
	open_map(av[1], map);
	save_colors(colors, map);
	print_colors(colors);
	// save_map(map);
}

void	parsing(t_elem *elem, t_colors *colors, t_map *map, char *av[])
{
	file_is_cub(av[1]);
	open_map(av[1], map);
	width_height_map_file(map, av);
	open_map(av[1], map);
	save_components(elem, colors, map, av);
	
	//open_map(av[1], map);
	//parsing_elements(av[1], map);
	//parsing_map(&map);
	//print_width_height(map);
}
