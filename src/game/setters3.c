/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:44:21 by castorga          #+#    #+#             */
/*   Updated: 2024/11/26 10:44:23 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	squared_vlen(t_game *g)
{
	float	dx;
	float	dy;

	dx = g->player.px - g->ray.vx;
	dy = g->player.py - g->ray.vy;
	return (dx * dx + dy * dy);
}

void	calculate_ray_hlen(t_game *g)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if ((g->ray.hx < TL) || (g->ray.hx > (g->map.mapw - 1) * TL))
		{
			g->ray.hlen = 0;
			return ;
		}
		g->map.x = ((int)(g->ray.hx)) >> 6;
		if (g->ray.ra > PI && g->ray.ra < 2 * PI)
			g->map.y = ((int)(g->ray.hy - 1)) >> 6;
		else if (g->ray.ra < PI && g->ray.ra > 0)
			g->map.y = ((int)(g->ray.hy)) >> 6;
		g->map.pos = g->map.y * g->map.mapw + g->map.x;
		if (g->map.pos >= 0 && g->map.pos < g->map.mapw * \
		g->map.maph && g->map.map[g->map.pos] == '1')
			hit = 1;
		else
			inc_ray_h(&g->ray);
	}
	set_hpath(g);
	g->ray.hlen = squared_hlen(g);
}

void	check_horizon_lines(t_game *g)
{
	float	tan_ra;

	tan_ra = tanf(g->ray.ra);
	if (g->ray.ra > PI && g->ray.ra < (2 * PI))
	{
		g->ray.hy = ((int)(g->player.py) >> 6) << 6;
		g->ray.hx = (g->player.px - ((g->player.py - g->ray.hy) / tan_ra));
		g->ray.y_step = -TL;
		g->ray.x_step = (g->ray.y_step / tan_ra);
		calculate_ray_hlen(g);
	}
	else if (g->ray.ra < PI && g->ray.ra > 0)
	{
		g->ray.hy = (((int)(g->player.py) >> 6) << 6) + TL;
		g->ray.hx = (g->player.px - ((g->player.py - g->ray.hy) / tan_ra));
		g->ray.y_step = TL;
		g->ray.x_step = (g->ray.y_step / tan_ra);
		calculate_ray_hlen(g);
	}
	else if (g->ray.ra == 0 || g->ray.ra == PI)
		g->ray.hlen = 0;
}

void	calculate_ray_vlen(t_game *g)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if ((g->ray.vy < TL) || (g->ray.vy > (g->map.maph - 1) * TL))
		{
			g->ray.vlen = 0;
			return ;
		}
		if (g->ray.ra > (PI / 2) && g->ray.ra < (3 * PI / 2))
			g->map.x = ((int)(g->ray.vx - 1)) >> 6;
		else if (g->ray.ra < (PI / 2) || g->ray.ra > (3 * PI / 2))
			g->map.x = ((int)(g->ray.vx)) >> 6;
		g->map.y = ((int)g->ray.vy) >> 6;
		g->map.pos = g->map.y * g->map.mapw + g->map.x;
		if (g->map.pos >= 0 && g->map.pos < g->map.mapw * \
		g->map.maph && g->map.map[g->map.pos] == '1')
			hit = 1;
		else
			inc_ray_v(&g->ray);
	}
	set_vpath(g);
	g->ray.vlen = squared_vlen(g);
}

void	check_vertical_lines(t_game *g)
{
	float	tan_ra;

	tan_ra = tanf(g->ray.ra);
	if (g->ray.ra > (PI / 2) && g->ray.ra < (3 * PI / 2))
	{
		g->ray.vx = (((int)g->player.px >> 6) << 6);
		g->ray.vy = (g->player.py - (g->player.px - g->ray.vx) * tan_ra);
		g->ray.x_step = -TL;
		g->ray.y_step = (g->ray.x_step * tan_ra);
		calculate_ray_vlen(g);
	}
	else if (g->ray.ra < (PI / 2) || g->ray.ra > (3 * PI / 2))
	{
		g->ray.vx = (((int)g->player.px >> 6) << 6) + TL;
		g->ray.vy = (g->player.py - (g->player.px - g->ray.vx) * tan_ra);
		g->ray.x_step = TL;
		g->ray.y_step = (g->ray.x_step * tan_ra);
		calculate_ray_vlen(g);
	}
	else if (g->ray.ra == (PI / 2) || g->ray.ra == (3 * PI / 2))
		g->ray.vlen = 0;
}
