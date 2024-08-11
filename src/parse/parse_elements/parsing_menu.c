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
				// free(line);
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

int	exist_colors(t_lmap *lmap)
{
	char	**elements;
	int		i;
	int		temp;

	temp = 0;
	while (lmap)
	{
		elements = ft_split2(lmap->content);
		i = 0;
		while (elements[i] && temp < 2)
		{
			if (ft_strlen(elements[i]) == 1)
			{
				if (ft_strncmp(elements[i], "F", 1) == 0)
					temp++;
				else if (ft_strncmp(elements[i], "C", 1) == 0)
					temp++;
			}
			i++;
		}
		free_elements(elements);
		lmap = lmap->next;
	}
	if (temp != 2)
		return (1);
	return (0);
}


static int	check_range_values(char **colors, int i, char **line)
{
	int		color_value;

	i = 0;
	while (colors[i])
	{
		color_value = ft_atoi(colors[i]);
		if (color_value < MIN_COLOR_VALUE || color_value > MAX_COLOR_VALUE)
		{
			free_elements(line);
			free_elements(colors);
			return (1);
		}
		i++;
	}
	return (0);
}

int	free_data(char **line, char **colors)
{
	free_elements(line);
	free_elements(colors);
	return (1);
}
void	free_data2(char **line, char **colors)
{
	free_elements(line);
	free_elements(colors);
}

int	exist_path_colors(t_lmap *lmap)
{
	char	**line;
	int		i;
	char	**colors;

	line = ft_split2(lmap->content);
	while (lmap)
	{
		if ((ft_strncmp(line[0], "F", 1) == 0) ||
			(ft_strncmp(line[0], "C", 1) == 0))
		{
			colors = ft_split(line[1], ',');
			i = 0;
			while (colors[i])
				i++;
			if (i == 3)
				check_range_values(colors, i, line);
			else
				free_data(line, colors);
			free_data2(line, colors);
		}
		lmap = lmap->next;
	}
	free_elements(line);
	return (0);
}

void	remove_empty_lines(t_lmap *lmap)
{
	t_lmap	*temp;
	t_lmap	*prev;

	temp = lmap;
	prev = NULL;
	while (temp)
	{
		if (temp->content[0] == '\0')
		{
			if (prev)
				prev->next = temp->next;
			free(temp->content);
			free(temp);
			temp = prev;
		}
		prev = temp;
		temp = temp->next;
	}
}

void	parse_elems(t_elem *elem, t_lmap *lmap)
{
	(void)elem;
	remove_tabs_spaces_elem(lmap);
	remove_empty_lines(lmap);
	if (exist_elements(lmap))
		ft_errors(3);
	if (exist_path_elements(lmap))
		ft_errors(4);		
	if (exist_colors(lmap))
		ft_errors(3);
	if (exist_path_colors(lmap))
		ft_errors(4);
	// save_path_chain_to_elem_struct(lmap, elem);
	// texture_path_extension_is_valid(elem);
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
