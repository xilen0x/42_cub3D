/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:26:04 by castorga          #+#    #+#             */
/*   Updated: 2023/12/04 16:26:06 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*Funcion que verifica si el mapa esta rodeado de paredes - continuacion*/
int	is_surrounded_by_walls2(t_game *game, int q_cols, int q_rows)
{
	int	i;

	i = 0;
	while (i < game->h)
	{
		if (game->matrix[i][q_cols - 1] != '1')
			ft_errors(3);
		i++;
	}
	i = 0;
	while (game->matrix[0][i] && game->matrix[0][i] != '\n')
	{
		if (game->matrix[q_rows - 1][i] != '1')
			ft_errors(3);
		i++;
	}
	return (0);
}

/* Funcion que verifica si el mapa esta rodeado de paredes
  Se verifica pared x pared en c/ciclo*/
int	is_surrounded_by_walls(t_game *game)
{
	int	i;
	int	q_rows;
	int	q_cols;

	i = 0;
	q_rows = game->h;
	q_cols = game->w;
	while (game->matrix[0][i] && game->matrix[0][i] != '\n')
	{
		if (game->matrix[0][i] != '1')
			ft_errors(3);
		i++;
	}
	i = 0;
	while (i < game->h)
	{
		if (game->matrix[i][0] != '1')
			ft_errors(3);
		i++;
	}
	is_surrounded_by_walls2(game, q_cols, q_rows);
	return (0);
}

/*Funcion que calcula y retorna cant. de collectibles 'C'*/
int	q_collectible(t_game *game)
{
	int	y;
	int	x;
	int	count_c;

	y = 0;
	x = 0;
	count_c = 0;
	while (y < game->h)
	{
		x = 0;
		while (x < game->w)
		{
			if (game->matrix[y][x] == 'C')
			{
				count_c++;
			}
			x++;
		}
		y++;
	}
	game->q_collec = count_c;
	return (count_c);
}

int	has_only_one_exit(t_game *game)
{
	int	y;
	int	x;
	int	count_e;

	y = 0;
	x = 0;
	count_e = 0;
	while (y < game->h)
	{
		x = 0;
		while (x < game->w)
		{
			if (game->matrix[y][x] == 'E')
			{
				count_e++;
				game->exit.x = x;
				game->exit.y = y;
			}
			x++;
		}
		y++;
	}
	return (count_e);
}
