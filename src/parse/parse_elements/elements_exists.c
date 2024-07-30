/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:44:40 by castorga          #+#    #+#             */
/*   Updated: 2024/07/09 15:44:43 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int elements_colors_exist(char *av, t_map *map)
// {
//     char *line;
//     char **elements;
//     char **colors;
//     int i;

//     open_map(av, map);
//     line = get_next_line(map->map_fd);
//     while (line)
// 	{
//         if (line[0] == '\n')
// 		{
//             free(line);
//             line = get_next_line(map->map_fd);
//             continue ;
//         }
//         remove_spaces_around_commas(line);
//         elements = ft_split(line, ' ');
// 		remove_tabs_and_spaces(elements);
//         if (!elements)
// 		{
//             free(line);
//             ft_printf("Error al dividir la línea en elementos!\n");
//             return 1;
//         }
//         i = 0;
//         while (elements[i])
//             i++;
//         if (i == 2)
// 		{
//             if (ft_strncmp(elements[0], "F", 1) == 0 || ft_strncmp(elements[0], "C", 1) == 0)
// 			{
//                 char *trimmed_element = ft_strtrim(elements[1], "\n");
//                 colors = ft_split(trimmed_element, ',');
//                 free(trimmed_element);
//                 if (!colors) {
//                     free_elements(elements);
//                     free(line);
//                     ft_printf("Error al dividir los colores!\n");
//                     return 1;
//                 }
//                 i = 0;
//                 int valid_colors = 1;
//                 while (colors[i])
// 				{
//                     int color_value = ft_atoi(colors[i]);
//                     if (color_value < MIN_COLOR_VALUE || color_value > MAX_COLOR_VALUE)
// 					{
//                         valid_colors = 0;
//                         break;
//                     }
//                     i++;
//                 }
//                 if (!valid_colors || i != 3)
// 				{
//                     ft_printf("Error de sintaxis en colores!\n");
//                     free_elements(colors);
//                     free_elements(elements);
//                     free(line);
//                     return 1;
//                 }
//                 if (ft_strncmp(elements[0], "F", 1) == 0)
// 				{
//                     map->f_color[0] = ft_atoi(colors[0]);
//                     map->f_color[1] = ft_atoi(colors[1]);
//                     map->f_color[2] = ft_atoi(colors[2]);
//                     map->f++;
//                 } else if (ft_strncmp(elements[0], "C", 1) == 0)
// 				{
//                     map->c_color[0] = ft_atoi(colors[0]);
//                     map->c_color[1] = ft_atoi(colors[1]);
//                     map->c_color[2] = ft_atoi(colors[2]);
//                     map->c++;
//                 }
//                 free_elements(colors);
//             }
//         }
//         free_elements(elements);
//         free(line);
//         line = get_next_line(map->map_fd);
//     }
//     close(map->map_fd);
//     if (map->f && map->c) {
//         ft_printf("\nAll colors exist\n");
//         return 0;
//     } else {
//         ft_printf("Error: Faltan colores!\n");
//         return 1;
//     }
// }

//Check if elements exist(in any order)
// int elements_exist(t_map *map)
// {
//     char *line;
//     char **elements;
//     int i;

//     line = get_next_line(map->map_fd);
//     while (line)
//     {
//         if (line[0] == '\n')
//         {
//             free(line);
//             line = get_next_line(map->map_fd);
//             continue;
//         }

//         elements = ft_split(line, ' ');
//         remove_tabs_and_spaces(elements);
//         texture_path_extension_is_valid(elements[1]);
//         i = 0;
//         while (elements[i])
//             i++;
//         if (i == 2)
//         {
//             if (ft_strncmp(elements[0], "NO", 2) == 0)
//             {
//                 map->no++;
//                 map->no_path = ft_strdup(elements[1]);
//             }
//             else if (ft_strncmp(elements[0], "SO", 2) == 0)
//             {
//                 map->so++;
//                 map->so_path = ft_strdup(elements[1]);
//             }
//             else if (ft_strncmp(elements[0], "WE", 2) == 0)
//             {
//                 map->we++;
//                 map->we_path = ft_strdup(elements[1]);
//             }
//             else if (ft_strncmp(elements[0], "EA", 2) == 0)
//             {
//                 map->ea++;
//                 map->ea_path = ft_strdup(elements[1]);
//             }
//         }
//         else
//         {
//             ft_printf("Error de sintaxis en elementos!\n");
//             close(map->map_fd);
//             free(line);
//             free_elements(elements);
//             free_xx_path(map);
//             return (1);
//         }
//         free(line);
//         free_elements(elements);
//         if (map->no && map->so && map->we && map->ea)
//         {
//             close(map->map_fd);
//             ft_printf("\nAll cardinal directions exist\n");
//             free_xx_path(map);
//             return (0);
//         }
//         line = get_next_line(map->map_fd);
//     }

//     ft_printf("algun otro Error\n");
//     close(map->map_fd);
//     free_xx_path(map);
//     return (1);
// }
