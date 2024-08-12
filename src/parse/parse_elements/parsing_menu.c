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

static void	save_path3(t_elem *elem, char *line, char *option)
{
	if (ft_strncmp(option, "NO", 2) == 0)
		elem->no_path = ft_strdup(line);
	else if (ft_strncmp(option, "SO", 2) == 0)
		elem->so_path = ft_strdup(line);
	else if (ft_strncmp(option, "EA", 2) == 0)
		elem->ea_path = ft_strdup(line);
	else if (ft_strncmp(option, "WE", 2) == 0)
		elem->we_path = ft_strdup(line);
	free(line);
}

static void	save_path2(t_elem *elem, char **elements, int i, int temp)
{
	char	*line;
	char	*option;

	while (elements[i])
	{
		if (ft_strlen(elements[i]) == 2)
		{
			option = elements[i];
			if (ft_strncmp(elements[i], option, 2) == 0)
			{
				line = ft_strdup(elements[i + 1]);
				save_path3(elem, line, option);
				temp++;
			}
		}
		if (temp == 4)
			break ;
		i++;
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
			continue ;
		}
		elements = ft_split2(lmap->content);
		i = 0;
		save_path2(elem, elements, i, temp);
		free_elements(elements);
		lmap = lmap->next;
	}
	return (0);
}

int	duplicate_lines(t_lmap *lmap)
{
	t_lmap	*temp;
	t_lmap	*temp2;

	temp = lmap;
	while (temp)
	{
		temp2 = temp->next;
		if (temp->content[0] == 'S' || temp->content[0] == 'N' || \
		temp->content[0] == 'E' || temp->content[0] == 'W' || \
		temp->content[0] == 'F' || temp->content[0] == 'C')
		{
			while (temp2)
			{
				if (ft_strncmp(temp->content, temp2->content, ft_strlen(temp->content)) == 0)
					return (1);
				temp2 = temp2->next;
			}
			temp = temp->next;
		}
		temp = temp->next;
	}
	return (0);
}

void	parse_elems(t_elem *elem, t_lmap *lmap)
{
	(void)elem;
	remove_tabs_spaces_elem(lmap);
	remove_empty_lines(lmap);
	if (exist_elements(lmap))
		ft_errors(3);
	if (exist_path_elements(lmap))
		ft_errors(3);		
	if (exist_colors(lmap))
		ft_errors(3);
	if (exist_path_colors(lmap))
		ft_errors(3);
	if (duplicate_lines(lmap))
		ft_errors(3);

	// save_path_chain_to_elem_struct(lmap, elem);
}

/*Menu parsing*/
void	parsing(t_elem *elem, t_colors *colors, t_map *map, t_lmap **lmap)
{
	// (void)lmap;
	(void)colors;
	file_is_cub(elem->av[1]);
	open_map(elem->av[1], map);
	create_list(map, lmap);
	parse_elems(elem, *lmap);

	// parsing_components(elem, colors, map);
	// parsing_map(map, lmap);
	// parse_rgb(colors, lmap);
	print_list(*lmap);
	// print_elements(elem);
	// print_colors(colors);
	// print_width_height(map);
}
