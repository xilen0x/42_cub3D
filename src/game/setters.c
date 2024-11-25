/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:31:38 by spereyra          #+#    #+#             */
/*   Updated: 2024/09/27 18:23:19 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_player(t_player *player, int x, int y, float angle)
{
	player->px = x * TL + TL / 2;
	player->py = y * TL + TL / 2;
	player->pa = angle;
	player->fov = 1.05f;
}

int	check_and_initialize_player(t_map *map, t_player *player, int x, int y)
{
	char	tile;

	tile = map->map[y * map->mapW + x];
	if (tile == 'N')
	{
		initialize_player(player, x, y, 3 * PI / 2);
		return (1);
	}
	else if (tile == 'S')
	{
		initialize_player(player, x, y, PI / 2);
		return (1);
	}
	else if (tile == 'E')
	{
		initialize_player(player, x, y, 0.f);
		return (1);
	}
	else if (tile == 'W')
	{
		initialize_player(player, x, y, PI);
		return (1);
	}
	return (0);
}

void	set_player(t_map *map, t_player *player)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->mapH)
	{
		x = 0;
		while (x < map->mapW)
		{
			if (check_and_initialize_player(map, player, x, y))
				return ;
			x++;
		}
		y++;
	}
}

float	norm_angle(float angle)
{
	float	norm;

	if (angle < 0)
		norm = angle + 2 * PI;
	else if (angle >= 2 * PI)
		norm = angle - 2 * PI;
	else
		norm = angle;
	return (norm);
}

void	set_image(t_game *g)
{
	int	color1;
	int	color2;

	color1 = g->cols.f_color_hex;
	color2 = g->cols.c_color_hex;

	floor_to_image(&g->img3, color2);
	ceiling_to_image(&g->img3, color1);
	bg_to_image(&g->img2, 0x00A9E2F3);
	map_to_image(&g->img2, &g->map, 0x000000FF);
	grid_to_image(&g->img2, 0x00FFFF00);
	player_to_image(&g->img2, &g->player, 0x00FF0000);
	direction_to_image(g, 0x00FFFFFF);
}
