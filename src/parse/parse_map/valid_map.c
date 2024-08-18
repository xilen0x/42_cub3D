/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:35:07 by castorga          #+#    #+#             */
/*   Updated: 2024/07/16 15:35:09 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


size_t	ft_strlen2(const char *str)
{
	size_t	i;
	size_t	space;

	i = 0;
	space = 0;
	if (!str)
		ft_errors("Error, the string is empty\n");
	while (str[i] == ' ' || str[i] == '\t')
	{
		space++;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			space++;
		i++;
	}
	return (i - space);
}

int	its_playable(t_map	*map)
{
	int	count;

	count = 0;
	map->y = 0;
	while (map->matrix[map->y])
	{
		map->x = 0;
		while (map->matrix[map->y][map->x])
		{
			if (map->matrix[map->y][map->x] == '1')
				count++;
			map->x++;
		}
		if ((map->y + 1) < map->h)
			map->y++;
		else
			break ;
	}
	if (count < 4)
		return (1);
	return (0);
}

int	only_characters_allowed(t_map	*map)
{
	map->y = 0;
	while (map->matrix[map->y])
	{
		map->x = 0;
		while (map->matrix[map->y][map->x])
		{
			if (map->matrix[map->y][map->x] != ' ' &&
				map->matrix[map->y][map->x] != '0' &&
				map->matrix[map->y][map->x] != '1' &&
				map->matrix[map->y][map->x] != 'N' &&
				map->matrix[map->y][map->x] != 'S' &&
				map->matrix[map->y][map->x] != 'E' &&
				map->matrix[map->y][map->x] != 'W' &&
				map->matrix[map->y][map->x] != '\t')
				return (1);
			map->x++;
		}
		if ((map->y + 1) < map->h)
			map->y++;
		else
			break ;
	}
	return (0);
}

int	is_one_player(t_map *map)
{
	int	count;

	count = 0;
	map->y = 0;
	while (map->matrix[map->y])
	{
		map->x = 0;
		while (map->matrix[map->y][map->x])
		{
			if (map->matrix[map->y][map->x] == 'N' ||
				map->matrix[map->y][map->x] == 'S' ||
				map->matrix[map->y][map->x] == 'E' ||
				map->matrix[map->y][map->x] == 'W')
				count++;
			map->x++;
		}
		if ((map->y + 1) < map->h)
			map->y++;
		else
			break ;
	}
	if (count != 1)
		return (1);
	return (0);
}

/*Check if there is any space around the 0*/
int	any_zero_or_space(t_map *map)
{
	while (map->matrix[map->y])
	{
		map->x = 0;
		while (map->matrix[map->y][map->x])
		{
			if ((map->matrix[map->y][map->x] == '0') &&
				((map->matrix[map->y - 1][map->x] == ' ') ||
				(map->matrix[map->y + 1][map->x] == ' ') ||
				(map->matrix[map->y][map->x - 1] == ' ') ||
				(map->matrix[map->y][map->x + 1] == ' ')))
				return (1);
			map->x++;
		}
		if ((map->y + 1) < map->h)
			map->y++;
		else
			break ;
	}
	return (0);
}

// int	all_walls_closed(t_lmap *lm)
// {
// 	int		i;

// 	i = 0;
// 	while (lm && (
// 			(ft_strnstr2(lm->content, "NO", ft_strlen(lm->content)) != NULL) || 
// 			(ft_strnstr2(lm->content, "SO", ft_strlen(lm->content)) != NULL) || 
// 			(ft_strnstr2(lm->content, "WE", ft_strlen(lm->content)) != NULL) || 
// 			(ft_strnstr2(lm->content, "EA", ft_strlen(lm->content)) != NULL) || 
// 			(ft_strnstr2(lm->content, "F", ft_strlen(lm->content)) != NULL) || 
// 			(ft_strnstr2(lm->content, "C", ft_strlen(lm->content)) != NULL) || 
// 			(lm->content[0] == '\0')))
// 		lm = lm->next;
// 	while (lm)
// 	{
// 		remove_newline_char(lm->content);//test
// 		if (lm->content[0] == '1')
// 		{
// 			while (lm->content[i])
// 				i++;
// 			if (lm->content[i - 1] != '1')
// 				return (1);
// 		}
// 		lm = lm->next;
// 	}
// 	return (0);
// }

int	counter_of_char(const char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!str)
		ft_errors("Error, the string is empty\n");
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == '1')
			count++;
		i++;
	}
	return (count);
}
/*funcion que remueve los espacios y tabulaciones que encuentre al final de la linea, del tipo "1111111110110 0001110000000000001 \n". Solo los espacios o tabsdel final*/
void	remove_final_spaces_tabs(char *str)
{
	int	i;

	i = ft_strlen(str) - 2;
	while (str[i] == ' ' || str[i] == '\t')
	{
		str[i] = '\0';
		i--;
	}
}

int	rows_are_all_ones(t_lmap *lm)
{
	unsigned int	start;
	unsigned int	end;
	unsigned int	i;
	unsigned int	size;
	unsigned int	length_line;
	unsigned int	q_of_ones;

	i = 0;
	while (lm && (
			(ft_strnstr2(lm->content, "NO", ft_strlen(lm->content)) != NULL) || 
			(ft_strnstr2(lm->content, "SO", ft_strlen(lm->content)) != NULL) || 
			(ft_strnstr2(lm->content, "WE", ft_strlen(lm->content)) != NULL) || 
			(ft_strnstr2(lm->content, "EA", ft_strlen(lm->content)) != NULL) || 
			(ft_strnstr2(lm->content, "F", ft_strlen(lm->content)) != NULL) || 
			(ft_strnstr2(lm->content, "C", ft_strlen(lm->content)) != NULL) || 
			(lm->content[0] == '\0')))
		lm = lm->next;
	lm = lm->next;//para q avance a la siguiente linea del mapa
	size = lst_size(lm);
	while (lm && size > 1)
	{
		start = 0;
		end = 0;
		i = 0;
		remove_final_spaces_tabs(lm->content);
		remove_newline_char(lm->content);
		while (lm->content[i] == ' ' || lm->content[i] == '\t')
			i++;
		if (lm->content[i] == '1')
			start = 1;
		while (lm->content[i] != '\0')
			i++;
		if (lm->content[i - 1] == '1')
			end = 1;
		if (start == 1 && end == 1)
			lm = lm->next;
		else
			return (1);
		size--;
	}
	remove_newline_char(lm->content);
	length_line = ft_strlen2(lm->content);
	q_of_ones = counter_of_char(lm->content);
	if (length_line != q_of_ones)
		return (1);
	return (0);
}

int	first_row_is_all_ones(t_lmap *lm)
{
	unsigned int	length_line;
	unsigned int	q_of_ones;
	char			*line;

	while (lm && (
			(ft_strnstr2(lm->content, "NO", ft_strlen(lm->content)) != NULL) || 
			(ft_strnstr2(lm->content, "SO", ft_strlen(lm->content)) != NULL) || 
			(ft_strnstr2(lm->content, "WE", ft_strlen(lm->content)) != NULL) || 
			(ft_strnstr2(lm->content, "EA", ft_strlen(lm->content)) != NULL) || 
			(ft_strnstr2(lm->content, "F", ft_strlen(lm->content)) != NULL) || 
			(ft_strnstr2(lm->content, "C", ft_strlen(lm->content)) != NULL) || 
			(lm->content[0] == '\0')))
		lm = lm->next;
	remove_newline_char(lm->content);
	line = ft_strtrim2(lm->content, " ", "\t");
	length_line = ft_strlen2(line);
	q_of_ones = counter_of_char(line);
	if (length_line != q_of_ones)
	{
		free(line);
		return (1);
	}
	free(line);
	return (0);
}


void	valid_map(t_map *map)
{
	spaces_to_ones(map);
	if (is_one_player(map) == 1)
		ft_errors("Invalid map, there must be only one player\n");
	if (only_characters_allowed(map) == 1)
		ft_errors("Invalid map, characters not allowed were found\n");
	if (its_playable(map) == 1)
		ft_errors("Invalid map. The map is not playable\n");
}

