/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:24:23 by spereyra          #+#    #+#             */
/*   Updated: 2024/09/18 16:30:09 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(t_game *g, float move_x, float move_y)
{
	float	new_px;
	float	new_py;
	int		x;
	int		y;

	new_px = g->player.px + move_x * SPEED;
	new_py = g->player.py + move_y * SPEED;
	x = (int)new_px >> 6;
	y = (int)new_py >> 6;
	if (g->map.map[g->map.mapw * ((int)(new_py - MARGIN) >> 6) + x] != '1' &&
		g->map.map[g->map.mapw * ((int)(new_py + MARGIN) >> 6) + x] != '1' &&
		g->map.map[g->map.mapw * y + ((int)(new_px - MARGIN) >> 6)] != '1' &&
		g->map.map[g->map.mapw * y + ((int)(new_px + MARGIN) >> 6)] != '1')
	{
		g->player.px = new_px;
		g->player.py = new_py;
	}
	set_image(g);
	set_rays(g);
}

void	move_w(t_game *g)
{
	move_player(g, cosf(g->player.pa), sinf(g->player.pa));
}

void	move_s(t_game *g)
{
	move_player(g, -cosf(g->player.pa), -sinf(g->player.pa));
}

void	move_d(t_game *g)
{
	move_player(g, -sinf(g->player.pa), cosf(g->player.pa));
}

void	move_a(t_game *g)
{
	move_player(g, sinf(g->player.pa), -cosf(g->player.pa));
}
