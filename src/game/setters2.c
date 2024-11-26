/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:43:36 by castorga          #+#    #+#             */
/*   Updated: 2024/11/26 10:43:39 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Set the colour of a given pixel in an array of pixels (i.e. the image) */
void	set_pixel_to_image(t_img *img, int x, int y, unsigned int color)
{
	void	*offset;

	if (x < 0 || x >= WX || y < 0 || y >= WY)
		return ;
	offset = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)offset = color;
}

void	set_rays(t_game *g)
{
	float	angle_step;
	int		rays;

	g->ray.ra = g->player.pa - (g->player.fov / 2);
	angle_step = g->player.fov / g->img3.w;
	rays = 0;
	while (rays < g->img3.w)
	{
		g->ray.ra = norm_angle(g->ray.ra);
		check_horizon_lines(g);
		check_vertical_lines(g);
		if (g->ray.hlen <= 0 || (g->ray.vlen > 0 && g->ray.vlen < g->ray.hlen))
		{
			g->ray.len = sqrtf(g->ray.vlen);
			g->ray.path = g->ray.vpath;
		}
		else
		{
			g->ray.len = sqrtf(g->ray.hlen);
			g->ray.path = g->ray.hpath;
		}
		render_wall(g, rays);
		g->ray.ra += angle_step;
		rays++;
	}
}

void	set_hpath(t_game *g)
{
	if (g->ray.ra > PI && g->ray.ra < (2 * PI))
		g->ray.hpath = 0;
	else if (g->ray.ra <= PI && g->ray.ra >= 0)
		g->ray.hpath = 1;
}

void	set_vpath(t_game *g)// to be set_path
{
	if (g->ray.ra > (PI / 2) && g->ray.ra < (3 * PI / 2))
		g->ray.vpath = 2;
	else if (g->ray.ra < (PI / 2) || g->ray.ra > (3 * PI / 2))
		g->ray.vpath = 3;
}

float	squared_hlen(t_game *g)
{
	float	dx;
	float	dy;

	dx = g->player.px - g->ray.hx;
	dy = g->player.py - g->ray.hy;
	return (dx * dx + dy * dy);
}
