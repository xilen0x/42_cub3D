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

void	free_elem1(char **elements, char *line_trimed)
{
	free_elements(elements);
	free(line_trimed);
}

void	if_f_or_c(t_elem *elem, t_colors *colors, t_map *map, char *line)
{
	char	*line_trimed;
	char	**elements;

	line_trimed = ft_strtrim2(line, " ", "\t");
	elements = ft_split2(line_trimed);
	if ((ft_strncmp(elements[0], "F", 1) == 0) || \
		(ft_strncmp(elements[0], "C", 1) == 0))
	{
		parsing_colors2(colors, map, line);
		open_map(elem->av[1], map);
		parsing_elements(elem, map);
		free_elements(elements);
		free(line_trimed);
		return ;
	}
	else
	{
		parsing_elements2(elem, map, line);
		open_map(elem->av[1], map);
		parsing_colors(colors, map);
		free_elements(elements);
		free(line_trimed);
		return ;
	}
	free_elem1(elements, line_trimed);
}

void	parsing_comp2(t_elem *elem, t_colors *colors, t_map *map, char *line)
{
	if_f_or_c(elem, colors, map, line);
	free(line);
	return ;
}

void	parsing_components(t_elem *elem, t_colors *colors, t_map *map)
{
	char	*line;

	line = get_next_line(map->map_fd);
	elem->line = line;
	while (elem->line)
	{
		if (elem->line[0] == '\n')
		{
			free(elem->line);
			elem->line = get_next_line(map->map_fd);
			continue ;
		}
		parsing_comp2(elem, colors, map, elem->line);
		elem->line = NULL;
	}
}
						/******* OLD ********/

/******************************************************************************/

						/******* NEW ********/

void	remove_tabs_spaces_elem(t_lmap *lmap)
{
	char	*line;

	while (lmap)
	{
		line = ft_strtrim2(lmap->content, " ", "\t");
		free(lmap->content);
		lmap->content = line;
		lmap = lmap->next;
	}
}

int	save_path_chain_to_elem_struct(t_lmap *lmap, t_elem *elem)
{
	char	**elements;
	int		i;
	int		temp;

	temp = 0;
	while (lmap)
	{
		if (lmap->content[0] == '\n')
		{
			lmap = lmap->next;
			continue;
		}
		elements = ft_split2(lmap->content);
		i = 0;
		while (elements[i])
		{
			if (ft_strncmp(elements[i], "NO", 2) == 0)
			{
				elem->no_path = ft_strdup(elements[i + 1]);
				temp++;
			}
			if (ft_strncmp(elements[i], "SO", 2) == 0)
			{
				elem->so_path = ft_strdup(elements[i + 1]);
				temp++;
			}
			if (ft_strncmp(elements[i], "EA", 2) == 0)
			{
				elem->ea_path = ft_strdup(elements[i + 1]);
				temp++;
			}
			if (ft_strncmp(elements[i], "WE", 2) == 0)
			{
				elem->we_path = ft_strdup(elements[i + 1]);
				temp++;
			}
			i++;
		}
		free_elements(elements);
		lmap = lmap->next;
		if (temp == 4)
			break ;
	}
	return (0);
}

void	parse_elems(t_elem *elem, t_lmap *lmap)
{
	// (void)elem;
	remove_tabs_spaces_elem(lmap);
	// ft_printf("\n\nAfter removing tabs and spaces\n\n");
	save_path_chain_to_elem_struct(lmap, elem);
	ft_printf("NO_PATH: %s\n", elem->no_path);
	ft_printf("SO_PATH: %s\n", elem->so_path);
	ft_printf("EA_PATH: %s\n", elem->ea_path);
	ft_printf("WE_PATH: %s\n", elem->we_path);
	// {
	// 	write(1, "Error split chain\n", 18);
	// 	exit(1);
	// }
}


void	parsing(t_elem *elem, t_colors *colors, t_map *map, t_lmap **lmap)
{
	// (void)lmap;
	(void)colors;
	file_is_cub(elem->av[1]);
	open_map(elem->av[1], map);
	create_list(map, lmap);
	parse_elems(elem, *lmap);
	texture_path_extension_is_valid(elem);
	// parsing_components(elem, colors, map);
	// parsing_map(map, lmap);
	// parse_rgb(colors, lmap);
	print_list(*lmap);
	// print_elements(elem);
	// print_colors(colors);
	// print_width_height(map);
}
