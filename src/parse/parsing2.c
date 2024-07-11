/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:44:51 by castorga          #+#    #+#             */
/*   Updated: 2024/07/09 15:44:54 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Descr.: verifica si el mapa es rectangular*/
// int	is_rectangular(t_game *game)
// {
// 	int		i;
// 	int		curr_row_len;
// 	int		first_row_len;

// 	i = 0;
// 	if (game->w <= 4 || game->w > 34)
// 		ft_errors(3);
// 	first_row_len = ft_strlen(game->matrix[i]);
// 	while (i < game->h)
// 	{
// 		curr_row_len = ft_strlen(game->matrix[i]);
// 		if (first_row_len != curr_row_len)
// 			ft_errors(3);
// 		i++;
// 	}
// 	return (0);
// }

/* 
Descr.: Busca y cuenta 'P' en el mapa, guardando su posición.
Return: Cantidad de 'P' encontrados.
*/
// int	is_initial_position(t_game *game)
// {
// 	int		y;
// 	int		x;
// 	int		count_p;

// 	y = 0;
// 	x = 0;
// 	count_p = 0;
// 	while (y < game->h)
// 	{
// 		x = 0;
// 		while (x < game->w)
// 		{
// 			if (game->matrix[y][x] == 'P')
// 			{
// 				count_p++;
// 				game->position.x = x;
// 				game->position.y = y;
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (count_p);
// }

// t_point	find_p(t_game *copy_map, t_game *game)
// {
// 	int		y;
// 	int		x;
// 	t_point	coord;

// 	y = 0;
// 	while (y < copy_map->h)
// 	{
// 		x = 0;
// 		while (x < copy_map->w)
// 		{
// 			if (copy_map->matrix[y][x] == 'P')
// 			{
// 				coord.y = y;
// 				coord.x = x;
// 				game->position.y = y;
// 				game->position.x = x;
// 				break ;
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (coord);
// }

/*Funcion que verifica si hay una ruta valida en el mapa - continuacion*/
// void	fill(char **map, t_point cur, int *exit_found)
// {
// 	if (map[cur.y][cur.x] == '1' || map[cur.y][cur.x] == '*' \
// 	|| *exit_found == 1)
// 		return ;
// 	if (map[cur.y][cur.x] == 'E')
// 		*exit_found = 1;
// 	map[cur.y][cur.x] = '*';
// 	if (*exit_found == 0)
// 	{
// 		fill(map, (t_point){cur.x - 1, cur.y}, exit_found);
// 		fill(map, (t_point){cur.x + 1, cur.y}, exit_found);
// 		fill(map, (t_point){cur.x, cur.y - 1}, exit_found);
// 		fill(map, (t_point){cur.x, cur.y + 1}, exit_found);
// 	}
// }

/*Funcion que verifica si hay una ruta valida en el mapa*/
// int	valid_path_to_exit(t_game *game)
// {
// 	int			i;
// 	int			exit_found;
// 	t_point		p_location;
// 	t_game		copy_map;

// 	exit_found = 0;
// 	copy_map.w = game->w;
// 	copy_map.h = game->h;
// 	copy_map.matrix = (char **)malloc(sizeof(char *) * (game->h + 1));
// 	if (!copy_map.matrix)
// 	{
// 		free(copy_map.matrix);
// 		return (1);
// 	}
// 	i = 0;
// 	while (i < game->h)
// 	{
// 		copy_map.matrix[i] = ft_strdup(game->matrix[i]);
// 		i++;
// 	}
// 	p_location = find_p(&copy_map, game);
// 	fill(copy_map.matrix, p_location, &exit_found);
// 	free_map(&copy_map);
// 	return (exit_found);
// }
