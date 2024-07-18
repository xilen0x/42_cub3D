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


//void	save_colors()

/*funcion que guarda en */
void	save_components(t_elem *elem, t_colors *colors, t_map *map)
{
	(void)colors;
	save_elements(elem, map);
	print_elements(elem);
	//save_colors(colors, map);
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
	save_components(elem, colors, map);
	// save_colors(map, av);
	// save_map(map, av);
	//open_map(av[1], map);
	//parsing_elements(av[1], map);
	//parsing_map(&map);
	//print_width_height(map);
}
