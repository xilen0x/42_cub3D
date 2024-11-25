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

// void	move_w(t_game *g)
// {
// 	int	x;
// 	int	xleft;
// 	int	xright;
// 	int	y;

// 	x = (int)(g->player.px) >> 6;
// 	xleft = (int)(g->player.px - 8) >> 6;
// 	xright = (int)(g->player.px + 7) >> 6;
// 	y = (int)(g->player.py - 9) >> 6;
// 	if (g->map.map[g->map.mapW * y + x] != '1' && g->map.map[g->map.mapW * y + 
// 	xleft] != '1' && g->map.map[g->map.mapW * y + xright] != '1')
// 	{
// 		g->player.py = g->player.py - 4;
// 		set_image(g);
// 		set_rays(g);
// 	}
// }

// void	move_s(t_game *g)
// {
// 	int	x;
// 	int	xleft;
// 	int	xright;
// 	int	y;

// 	x = (int)(g->player.px) >> 6;
// 	xleft = (int)(g->player.px - 8) >> 6;
// 	xright = (int)(g->player.px + 7) >> 6;
// 	y = (int)(g->player.py + 9) >> 6;
// 	if (g->map.map[g->map.mapW * y + x] != '1' && g->map.map[g->map.mapW * y + 
// 	xleft] != '1' && g->map.map[g->map.mapW * y + xright] != '1')
// 	{
// 		g->player.py = g->player.py + 4;
// 		set_image(g);
// 		set_rays(g);
// 	}
// }

// void	move_a(t_game *g)
// {
// 	int	x;
// 	int	y;
// 	int	yup;
// 	int	ydown;

// 	x = (int)(g->player.px - 9) >> 6;
// 	y = (int)(g->player.py) >> 6;
// 	yup = (int)(g->player.py - 8) >> 6;
// 	ydown = (int)(g->player.py + 7) >> 6;
// 	if (g->map.map[g->map.mapW * y + x] != '1' && g->map.map[g->map.mapW * 
// 	yup + x] != '1' && g->map.map[g->map.mapW * ydown + x] != '1')
// 	{
// 		g->player.px = g->player.px - 4;
// 		set_image(g);
// 		set_rays(g);
// 	}
// }

// void	move_d(t_game *g)
// {
// 	int	x;
// 	int	y;
// 	int	yup;
// 	int	ydown;

// 	x = (int)(g->player.px + 9) >> 6;
// 	y = (int)(g->player.py) >> 6;
// 	yup = (int)(g->player.py - 8) >> 6;
// 	ydown = (int)(g->player.py + 7) >> 6;
// 	if (g->map.map[g->map.mapW * y + x] != '1' && g->map.map[g->map.mapW * 
// 	yup + x] != '1' && g->map.map[g->map.mapW * ydown + x] != '1')
// 	{
// 		g->player.px = g->player.px + 4;
// 		set_image(g);
// 		set_rays(g);
// 	}
// }

#define SPEED 4       // Velocidad del jugador
#define MARGIN 8      // Distancia mínima a las paredes

void	move_w(t_game *g)
{
	float new_px = g->player.px + cosf(g->player.pa) * SPEED;
	float new_py = g->player.py + sinf(g->player.pa) * SPEED;

	int x = (int)new_px >> 6;
	int y = (int)new_py >> 6;

	int x_margin_left = (int)(new_px - MARGIN) >> 6;
	int x_margin_right = (int)(new_px + MARGIN) >> 6;
	int y_margin_up = (int)(new_py - MARGIN) >> 6;
	int y_margin_down = (int)(new_py + MARGIN) >> 6;

	// Verificar colisiones con margen
	if (g->map.map[g->map.mapW * y_margin_up + x] != '1' &&
		g->map.map[g->map.mapW * y_margin_down + x] != '1' &&
		g->map.map[g->map.mapW * y + x_margin_left] != '1' &&
		g->map.map[g->map.mapW * y + x_margin_right] != '1')
	{
		g->player.px = new_px;
		g->player.py = new_py;
	}
	set_image(g);
	set_rays(g);
}

void	move_s(t_game *g)
{
	float new_px = g->player.px - cos(g->player.pa) * SPEED;
	float new_py = g->player.py - sin(g->player.pa) * SPEED;

	int x = (int)new_px >> 6;
	int y = (int)new_py >> 6;

	int x_margin_left = (int)(new_px - MARGIN) >> 6;
	int x_margin_right = (int)(new_px + MARGIN) >> 6;
	int y_margin_up = (int)(new_py - MARGIN) >> 6;
	int y_margin_down = (int)(new_py + MARGIN) >> 6;

	// Verificar colisiones con margen
	if (g->map.map[g->map.mapW * y_margin_up + x] != '1' &&
		g->map.map[g->map.mapW * y_margin_down + x] != '1' &&
		g->map.map[g->map.mapW * y + x_margin_left] != '1' &&
		g->map.map[g->map.mapW * y + x_margin_right] != '1')
	{
		g->player.px = new_px;
		g->player.py = new_py;
	}
	set_image(g);
	set_rays(g);
}

void	move_d(t_game *g)
{
	float new_px = g->player.px - sin(g->player.pa) * SPEED;
	float new_py = g->player.py + cos(g->player.pa) * SPEED;

	int x = (int)new_px >> 6;
	int y = (int)new_py >> 6;

	int x_margin_left = (int)(new_px - MARGIN) >> 6;
	int x_margin_right = (int)(new_px + MARGIN) >> 6;
	int y_margin_up = (int)(new_py - MARGIN) >> 6;
	int y_margin_down = (int)(new_py + MARGIN) >> 6;

	// Verificar colisiones con margen
	if (g->map.map[g->map.mapW * y_margin_up + x] != '1' &&
		g->map.map[g->map.mapW * y_margin_down + x] != '1' &&
		g->map.map[g->map.mapW * y + x_margin_left] != '1' &&
		g->map.map[g->map.mapW * y + x_margin_right] != '1')
	{
		g->player.px = new_px;
		g->player.py = new_py;
	}
	set_image(g);
	set_rays(g);
}

void	move_a(t_game *g)
{
	float new_px = g->player.px + sin(g->player.pa) * SPEED;
	float new_py = g->player.py - cos(g->player.pa) * SPEED;

	int x = (int)new_px >> 6;
	int y = (int)new_py >> 6;

	int x_margin_left = (int)(new_px - MARGIN) >> 6;
	int x_margin_right = (int)(new_px + MARGIN) >> 6;
	int y_margin_up = (int)(new_py - MARGIN) >> 6;
	int y_margin_down = (int)(new_py + MARGIN) >> 6;

	// Verificar colisiones con margen
	if (g->map.map[g->map.mapW * y_margin_up + x] != '1' &&
		g->map.map[g->map.mapW * y_margin_down + x] != '1' &&
		g->map.map[g->map.mapW * y + x_margin_left] != '1' &&
		g->map.map[g->map.mapW * y + x_margin_right] != '1')
	{
		g->player.px = new_px;
		g->player.py = new_py;
	}
	set_image(g);
	set_rays(g);
}