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

#include "cub3D.h"

/* Set the colour of a given pixel in an array of pixels (i.e. the image) */
void	set_pixel_to_image(t_img *img, int x, int y, int color)
{
	char	*offset;

	// Line len is in bytes. If img_w = 1024 pixels, so len_line ~ 4096 bytes (can differ for aligment)
	offset = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)offset = color;
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
			if (map->map[y * map->mapW + x] == 'P')
			{
				player->px = x * TL + TL / 2; // PX/2 is the centre of tile
				player->py = y * TL + TL / 2; // PX/2 is the centre of tile
				player->pa = 0.f;
				player->fov = 1.05f;
				return ;
			}
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

void    set_rays(t_game *g)
{
	float	angle_step;
	int	rays;

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
            g->ray.len = sqrtf(g->ray.vlen); // Usar la distancia vertical
            g->ray.color = g->ray.vcolor;
			g->ray.path = g->ray.vpath;///////////////
		}
		else
		{
            g->ray.len = sqrtf(g->ray.hlen); // Usar la distancia horizontal
            g->ray.color = g->ray.hcolor;
			g->ray.path = g->ray.hpath;///////////////
		}
		//load_texture(&g->ray.tex, g->ray.path, g->mlx);//////////
		ray_to_image(g, g->ray.color);
		render_wall(g, rays);
		g->ray.ra += angle_step;
		rays++;
	}
}

void	set_hcolor(t_game *g)// to be set_path
{
	if (g->ray.ra > PI && g->ray.ra < (2 * PI))	// looking up
	{
		g->ray.hcolor = 0x00C0C0C0;//0x00FFFFFF;// color of north wall
		g->ray.hpath = "./textures/north.xpm";/////////////
	}
	else if (g->ray.ra <= PI && g->ray.ra >= 0)	// looking down
	{
		g->ray.hcolor = 0x00FF00FF;// color of south wall
		g->ray.hpath = "./textures/south.xpm";//////////////
	}
}

void	set_vcolor(t_game *g)// to be set_path
{
	if (g->ray.ra > (PI / 2) && g->ray.ra < (3 * PI / 2)) // looking left
	{
		g->ray.vcolor = 0x00FFFF00;// color of east wall
		g->ray.vpath = "./textures/east.xpm";
	}
	else if (g->ray.ra < (PI / 2) || g->ray.ra > (3 * PI / 2)) // looking right
	{
		g->ray.vcolor = 0x0000FFFF;// color of west wall
		g->ray.vpath = "./textures/west.xpm";
	}
}

float	squared_hlen(t_game *g)
{
	float	dx;
	float	dy;

	dx = g->player.px - g->ray.hx;
	dy = g->player.py - g->ray.hy;
	return (dx * dx + dy * dy);
}

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
	int	hit = 0;
	
	while (hit == 0)
	{
		if ((g->ray.hx < TL) || (g->ray.hx > (g->map.mapW - 1) * TL))
		{
			g->ray.hlen = 0;
			return ;
		}
		g->map.x = ((int)(g->ray.hx)) >> 6;
		if (g->ray.ra > PI && g->ray.ra < 2 * PI)// looking up
			g->map.y = ((int)(g->ray.hy - 1)) >> 6;
		else if (g->ray.ra < PI && g->ray.ra > 0)//looking down
			g->map.y = ((int)(g->ray.hy)) >> 6;
		g->map.pos = g->map.y * g->map.mapW + g->map.x;
		if (g->map.pos >= 0 && g->map.pos < g->map.mapW * g->map.mapH && g->map.map[g->map.pos] == '1')
				hit = 1;
		else
		{
			g->ray.hx += g->ray.x_step;
			g->ray.hy += g->ray.y_step;
		}
	}
	set_hcolor(g);
	g->ray.hlen = squared_hlen(g);
}

void	check_horizon_lines(t_game *g)
{
	float	tan_ra;

	tan_ra = tanf(g->ray.ra);
	if (g->ray.ra > PI && g->ray.ra < (2 * PI))	// looking up
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
	int	hit = 0;

	while (hit == 0)
	{
		if ((g->ray.vy < TL) || (g->ray.vy > (g->map.mapH - 1) * TL))
		{
			g->ray.vlen = 0;
			return ;
		}
		if (g->ray.ra > (PI / 2) && g->ray.ra < (3 * PI / 2))// looking left
			g->map.x = ((int)(g->ray.vx - 1)) >> 6;
		else if (g->ray.ra < (PI / 2) || g->ray.ra > (3 * PI / 2))// looking right
			g->map.x = ((int)(g->ray.vx)) >> 6;
		g->map.y = ((int)g->ray.vy) >> 6;
		g->map.pos = g->map.y * g->map.mapW + g->map.x;
			
		if (g->map.pos >= 0 && g->map.pos < g->map.mapW * g->map.mapH && g->map.map[g->map.pos] == '1')
				hit =1;
		else
		{
			g->ray.vx += g->ray.x_step;
			g->ray.vy += g->ray.y_step;
		}
	}
	set_vcolor(g);
	g->ray.vlen = squared_vlen(g);
}

void	check_vertical_lines(t_game *g)
{
	float	tan_ra;

	tan_ra = tanf(g->ray.ra);
	if (g->ray.ra > (PI / 2) && g->ray.ra < (3 * PI / 2)) // looking left
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

void	set_image(t_game *g)
{
	floor_to_image(&g->img3, 0x0099CCFF);
	ceiling_to_image(&g->img3, 0x00CC9966);
	bg_to_image(&g->img2, 0x00606060);
	map_to_image(&g->img2, &g->map, 0x000000FF);
	grid_to_image(&g->img2, 0x00FFFF00);
	player_to_image(&g->img2, &g->player, 0x00FF0000);
	direction_to_image(g, 0x00FFFFFF);
}