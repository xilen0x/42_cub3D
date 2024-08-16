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

// int	any_zero_or_space_lst(t_lmap *lm)
// {
// 	char	*line;
// 	int		length;

// 	while (lm && (
// 			(ft_strnstr2(lm->content, "NO", ft_strlen(lm->content)) != NULL) || 
// 			(ft_strnstr2(lm->content, "SO", ft_strlen(lm->content)) != NULL) || 
// 			(ft_strnstr2(lm->content, "WE", ft_strlen(lm->content)) != NULL) || 
// 			(ft_strnstr2(lm->content, "EA", ft_strlen(lm->content)) != NULL) || 
// 			(ft_strnstr2(lm->content, "F", ft_strlen(lm->content)) != NULL) || 
// 			(ft_strnstr2(lm->content, "C", ft_strlen(lm->content)) != NULL) || 
// 			(lm->content[0] == '\0')))
// 		lm = lm->next;
// 	while (lm != NULL)
// 	{
// 		line = lm->content;
// 		length = 0;
// 		while (line[length] != '\0')
// 		{
// 			length++;
// 		}
// 		if (length == 0 || line[0] != '1' || line[length - 2] != '1')
// 		{
// 			return (1);
// 		}
// 		lm = lm->next;
// 	}
// 	return (0);
// }


void	valid_map(t_map *map)
{
	if (any_zero_or_space(map) == 1)
		ft_errors("Invalid map. There is a space around the 0\n");
	if (is_one_player(map) == 1)
		ft_errors("Invalid map, there must be only one player\n");
	if (only_characters_allowed(map) == 1)
		ft_errors("Invalid map, characters not allowed were found\n");
	if (its_playable(map) == 1)
		ft_errors("Invalid map. The map is not playable\n");
}

