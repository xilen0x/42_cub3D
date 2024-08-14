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

	while (elements[i] && ((ft_strncmp(elements[i], "NO", 2) == 0) || (ft_strncmp(elements[i], "SO", 2) == 0) || (ft_strncmp(elements[i], "EA", 2) == 0) || (ft_strncmp(elements[i], "WE", 2) == 0)))
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
		if (temp == 1)
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

int	exist_elements_or_colors_anywhere(t_lmap *lmap)
{
	int		count;

	count = 0;
	while (lmap)
	{
		if (ft_strnstr(lmap->content, "NO", ft_strlen(lmap->content)))
			count++;
		else if (ft_strnstr(lmap->content, "SO", ft_strlen(lmap->content)))
			count++;
		else if (ft_strnstr(lmap->content, "EA", ft_strlen(lmap->content)))
			count++;
		else if (ft_strnstr(lmap->content, "WE", ft_strlen(lmap->content)))
			count++;
		else if (ft_strnstr(lmap->content, "F", ft_strlen(lmap->content)))
			count++;
		else if (ft_strnstr(lmap->content, "C", ft_strlen(lmap->content)))
			count++;
		lmap = lmap->next;
	}
	if (count != 6)
		ft_errors(3);
	return (0);
}

/*Inserta un espacio antes y despues de la coma.(de los val. nums.)*/
void	add_one_space_between_elements(t_lmap *lmap)
{
	int		i;
	int		j;
	int		additional_space_count;
	char	*line;
	char	*new_line;

	while (lmap)
	{
		i = 0;
		additional_space_count = 0;
		line = lmap->content;
		while (line[i])
		{
			if (line[i] == ',' && line[i + 1] != ' ' && line[i + 1] != '\t' && line[i + 1] != '\0')
				additional_space_count++;
			i++;
		}
		new_line = (char *)malloc(strlen(line) + additional_space_count + 1);
		if (!new_line)
			return ;
		i = 0;
		j = 0;
		while (line[i])
		{
			if (line[i] != '\t')
			{
				new_line[j++] = line[i];
				if (line[i] == ',' && line[i + 1] != ' ' && line[i + 1] != '\t' && line[i + 1] != '\0')
					new_line[j++] = ' ';
				else if (line[i] == ' ')
				{
					while (line[i + 1] == '\t')
						i++;
				}
			}
			i++;
		}
		new_line[j] = '\0';
		free(lmap->content);
		lmap->content = new_line;
		lmap = lmap->next;
	}
}

/*Descripción:Encamina el parsing segun sea el caso. 
  Objetivo: Manejar lineas en cualquier orden estas vengan.*/
static void	hub_elements(t_lmap *lmap, t_colors *colors)
{
	while (lmap)
	{
		if ((lmap->content[0] == 'N') || (lmap->content[0] == 'S') || 
			(lmap->content[0] == 'W') || (lmap->content[0] == 'E'))
		{
			if (exist_elements(lmap))
				ft_errors(3);
			if (exist_path_elements(lmap))
				ft_errors(3);
		}
		else if ((lmap->content[0] == 'F') || (lmap->content[0] == 'C'))
		{
			add_one_space_between_elements(lmap);
			if (exist_colors(lmap))
				ft_errors(3);
			if (exist_path_colors_op2(lmap, colors))
				ft_errors(3);
		}
		lmap = lmap->next;
	}
}

void	save_rgb_values(t_lmap *lmap, t_colors *colors)
{
	t_lmap	*temp;
	int		i;
	int		j;
	int		count;

	temp = lmap;
	while (temp)
	{
		if (temp->content[0] == 'F' || temp->content[0] == 'C')
		{
			i = 0;
			j = 0;
			count = 0;
			while (temp->content[i])
			{
				if (temp->content[i] == ' ' || temp->content[i] == '\t')
					i++;
				if (temp->content[i] >= '0' && temp->content[i] <= '9')
				{
					if (temp->content[0] == 'F')
					{
						colors->f = 1;
						if (count == 0)
							colors->f_color[j++] = ft_atoi(&temp->content[i]);
						else if (count == 1)
							colors->f_color[j++] = ft_atoi(&temp->content[i]);
						else if (count == 2)
							colors->f_color[j++] = ft_atoi(&temp->content[i]);
					}
					else if (temp->content[0] == 'C')
					{
						colors->c = 2;
						if (count == 0)
							colors->c_color[j++] = ft_atoi(&temp->content[i]);
						else if (count == 1)
							colors->c_color[j++] = ft_atoi(&temp->content[i]);
						else if (count == 2)
							colors->c_color[j++] = ft_atoi(&temp->content[i]);
					}
					while (temp->content[i] >= '0' && temp->content[i] <= '9')
						i++;
					count++;
				}
				if (count == 3)
				{
					return ;
				}
				i++;
			}
		}
		temp = temp->next;
	}
}


void	parse_elems(t_elem *elem, t_lmap *lmap, t_colors *colors)
{
	remove_empty_lines(lmap);
	remove_external_tabs_spaces_elem(lmap);
	printf("\n---------LISTA DEPUES DE REM. LINEAS V. & TRIM-----------\n\n");
	print_list(lmap);
	if (exist_elements_or_colors_anywhere(lmap))
		ft_errors(3);
	hub_elements(lmap, colors);
	save_path_chain_to_elem_struct(lmap, elem);
}

/******************************Menu parsing*******************************/
void	parsing(t_elem *elem, t_colors *colors, t_map *map, t_lmap **lmap)
{
	file_is_cub(elem->av[1]);
	open_map(elem->av[1], map);
	create_list(map, lmap);
	printf("\n--------------LISTA ORIGINAL--------------\n\n");
	print_list(*lmap);
	parse_elems(elem, *lmap, colors);
	parsing_map(map, lmap);
	// print_elements(elem);
	// print_colors(colors);
	// print_width_height(map);
}

// int	duplicate_lines(t_lmap *lmap)
// {
// 	t_lmap	*temp;
// 	t_lmap	*temp2;

// 	temp = lmap;
// 	while (temp)
// 	{
// 		temp2 = temp->next;
// 		if (temp->content[0] == 'S' || temp->content[0] == 'N' || 
// 		temp->content[0] == 'E' || temp->content[0] == 'W' || 
// 		temp->content[0] == 'F' || temp->content[0] == 'C')
// 		{
// 			while (temp2)
// 			{
// 				if (ft_strncmp(temp->content, temp2->content, ft_strlen(temp->content)) == 0)
// 					return (1);
// 				temp2 = temp2->next;
// 			}
// 			temp = temp->next;
// 		}
// 		temp = temp->next;
// 	}
// 	return (0);
// }