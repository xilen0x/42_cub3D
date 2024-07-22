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
	printf("\nNO: %s\n", elem->no);
	printf("NO_PATH: %s\n", elem->no_path);
	printf("SO: %s\n", elem->so);
	printf("SO_PATH: %s\n", elem->so_path);
	printf("\nEA: %s\n", elem->ea);
	printf("EA_PATH: %s\n", elem->ea_path);
	printf("WE: %s\n", elem->we);
	printf("WE_PATH: %s\n", elem->we_path);
}

void	print_colors(t_colors *colors)
{
	printf("\nF: %d\n", colors->f);
	printf("F_COLOR: %d, %d, %d\n", colors->f_color[0], colors->f_color[1], colors->f_color[2]);
	printf("\nC: %d\n", colors->c);
	printf("C_COLOR: %d, %d, %d\n", colors->c_color[0], colors->c_color[1], colors->c_color[2]);
}

void save_elements(t_elem *elem, t_map *map)
{
    char *line;
    char **elements;
    char *temp;

    line = get_next_line(map->map_fd);
    while (line)
	{
        if (line[0] == '\n')
		{
            free(line);
            line = get_next_line(map->map_fd);
            continue ;
        }
        elements = ft_split(line, ' ');
        if (ft_strncmp(line, "NO", 2) == 0)
		{
            temp = ft_strtrim(elements[0], " ");
            elem->no = temp;
            temp = ft_strtrim(elements[1], " ");
            elem->no_path = temp;
        }
		else if (ft_strncmp(line, "SO", 2) == 0)
		{
			temp = ft_strtrim(elements[0], " ");
			elem->so = temp;
			temp = ft_strtrim(elements[1], " ");
			elem->so_path = temp;
        }
		else if (ft_strncmp(line, "EA", 2) == 0)
		{
			temp = ft_strtrim(elements[0], " ");
			elem->ea = temp;
			temp = ft_strtrim(elements[1], " ");
			elem->ea_path = temp;
		}
		else if (ft_strncmp(line, "WE", 2) == 0)
		{
			temp = ft_strtrim(elements[0], " ");
			elem->we = temp;
			temp = ft_strtrim(elements[1], " ");
			elem->we_path = temp;
		}
        free_elements(elements);
        free(line);
        line = get_next_line(map->map_fd);
    }
    close(map->map_fd);
}


void	save_colors(t_colors *colors, t_map *map)
{
	char *line;
	char **colors_elem;
	char **temp;
	char *color;
    
	line = get_next_line(map->map_fd);
	while (line)
	{
		if (line[0] == '\n')
		{
			free(line);
			line = get_next_line(map->map_fd);
			continue ;
		}
		if ((ft_strncmp(line, "F", 1) == 0) || (ft_strncmp(line, "C", 1) == 0))
		{
			colors_elem = ft_split(line, ' ');
			temp = ft_split(colors_elem[1], ',');
			if (ft_strncmp(colors_elem[0], "F", 1) == 0)
			{
				// temp = ft_strtrim(colors_elem[0], " ");
				colors->f = 1;
				
				color = ft_strtrim(temp[0], " ");
				colors->f_color[0] = ft_atoi(color);
				free(color);
				
				color = ft_strtrim(temp[1], " ");
				colors->f_color[1] = ft_atoi(color);
				free(color);
				
				color = ft_strtrim(temp[2], " ");
				colors->f_color[2] = ft_atoi(color);
				free(color);
			}
			else if (ft_strncmp(colors_elem[0], "C", 1) == 0)
			{
				// temp = ft_strtrim(colors_elem[0], " ");
				colors->c = 1;

				color = ft_strtrim(temp[0], " ");
				colors->c_color[0] = ft_atoi(color);
				free(color);

				color = ft_strtrim(temp[1], " ");
				colors->c_color[1] = ft_atoi(color);
				free(color);
				
				color = ft_strtrim(temp[2], " ");
				colors->c_color[2] = ft_atoi(color);
				free(color);
			}
		}
		else
		{
			// free_colors_elem(colors_elem);
			free(line);
			line = get_next_line(map->map_fd);
			continue ;
		}
		free_elements(colors_elem);
		free_elements(temp);
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

// static int	parsing_elements(char *av, t_map *map)
// {
// 	(void)av;
// 	if (elements_exist(map) != 0)
// 		ft_errors(3);
// 	// if (elements_colors_exist(av, map) != 0)
// 	//   	ft_errors(3);//corregir(si procede) luego los mensajes de error
// 	// //F: cant. de elementos o formato debe ser == (X XXX,XXX,XXX)
// 	// //F 220,100,0
// 	// if (elements_colors_range(map) != 0)
// 	// 	ft_errors(3);	
// 	return (0);
// }

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
