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

/* Set the colour of a given pixel in an array of pixels (i.e. the image) */
// void	set_pixel_to_image(t_img *img, int x, int y, int color)
// {
// 	char	*offset;

// 	// Line len is in bytes. If img_w = 1024 pixels, so len_line ~ 4096 bytes (can differ for aligment)
// 	offset = img->addr + (y * img->line_len + x * (img->bpp / 8));
// 	*(unsigned int *)offset = color;
// }

void set_pixel_to_image(t_img *img, int x, int y, uint32_t color)
{
	if (x < 0 || x >= WINX || y < 0 || y >= WINY)
		return ;
    char *dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
    *(unsigned int*)dst = color;
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
			if (map->map[y * map->mapW + x] == 'N' || map->map[y * map->mapW + x] == 'S' || map->map[y * map->mapW + x] == 'E' || map->map[y * map->mapW + x] == 'W')
			{
				// player->px = x * PX2 + PX2/2; // PX/2 is the centre of tile
				// player->py = y * PX2 + PX2/2; // PX/2 is the centre of tile
				player->px = x * PX3 + PX3/2;
				player->py = y * PX3 + PX3/2;
				player->pa = 0;//PI / 2;//M_PI;
				return ;
			}
			x++;
		}
		y++;
	}
}

void    set_rays(t_game *g)
{
	int	rays;//radians

	g->ray.ra = g->player.pa - 65;//31;/////////////
	rays = 0;
	while (rays < 128)   //128// Just one ray by now
	{
		g->ray.ra = g->ray.ra + 1;//g->player.pa;//////////////////
		if (g->ray.ra < 0)
			g->ray.ra = g->ray.ra + 2 * PI;
		else if (g->ray.ra >= 2 * PI)
			g->ray.ra = g->ray.ra - 2 * PI;
		check_horizon_lines(g);
		//printf("hlen:%d - angle:%d\n", g->ray.hlen, g->ray.ra);
		check_vertical_lines(g);
		//printf("vlen:%d - angle:%d\n", g->ray.vlen, g->ray.ra);
		if (g->ray.hlen <= 0)
		{
			g->ray.len = g->ray.vlen;
			g->ray.color = g->ray.vcolor;
		}	
		else if (g->ray.vlen <= 0)
		{
			g->ray.len = g->ray.hlen;
			g->ray.color = g->ray.hcolor;
		}
		else if (g->ray.vlen == g->ray.hlen)
		{
			g->ray.len = g->ray.hlen;
			//g->ray.color = g->ray.vcolor;
		}
		else if (g->ray.hlen < g->ray.vlen)// <= //&& g->ray.hlen > 0 && g->ray.hlen < 2147483647)
		{
			g->ray.len = g->ray.hlen;
			//if (g->ray.hx % 64 == 0)
			//	g->ray.color = g->ray.vcolor;
			//else
				g->ray.color = g->ray.hcolor;
		}
		else if (g->ray.vlen < g->ray.hlen)
		{
			g->ray.len = g->ray.vlen;
			//if (g->ray.hy % 64 == 0)
			//	g->ray.color = g->ray.hcolor;
			//else
				g->ray.color = g->ray.vcolor;
		}
		// printf("hlen:%d - hx:%d - hy:%d - angle:%d\n", g->ray.hlen, g->ray.hx,  g->ray.hy, g->ray.ra);
		// printf("vlen:%d - vx:%d - vy:%d - angle:%d\n", g->ray.vlen, g->ray.vx, g->ray.vy, g->ray.ra);
		// printf("len:%d - angle:%d\n\n", g->ray.len, g->ray.ra);
		
		ray_to_image(g, 0x00FF0000);//0x0000FF00 green
		//printf("Current col: %d\n", (int)(radians * (g->w / 128)));
		wall_to_image(g, rays * (g->img3.w / 128));// + (g->w / 128))));////128////////
		rays++;
	}
}

void	calculate_ray_hlen(t_game *g)
{
	int	hit = 0;
	int	power;

	power = (int)log2f((float)PX2);
	while (hit == 0)
	{
		if (g->ray.hx < 0 || g->ray.hx >= g->map.mapW * PX2)//512)
		{
			g->ray.hlen = 0;
			return ;
		}
		else {
			g->map.x = (g->ray.hx >> power);
			if (g->ray.ra > PI && g->ray.ra < 2 * PI)// looking up
				g->map.y = ((g->ray.hy - 1) >> power);
			else if (g->ray.ra < PI && g->ray.ra > 0)
				g->map.y = ((g->ray.hy) >> power);//looking down
			g->map.pos = g->map.y * g->map.mapW + g->map.x;//printf("pos: %d\n", g->map.pos);
			if (g->map.pos >= 0 && g->map.pos < g->map.mapW * g->map.mapH && g->map.map[g->map.pos] == '1')
				hit = 1;//dof = 8;    // hit wall
			else
			{
				g->ray.hx += g->ray.x_step;
				g->ray.hy += g->ray.y_step;
			}
		}
	}
	if (g->ray.ra > PI && g->ray.ra < (2 * PI))	// looking up
	{
		//g->ray.hy = g->ray.hy + 1;//////// delete wall penetration
		g->ray.hcolor = 0x00FFFFFF;// color of north wall
	}
	else if (g->ray.ra <= PI && g->ray.ra >= 0)	// looking down
	{
		//g->ray.hy = g->ray.hy - 1;//////// delete wall penetration
		g->ray.hcolor = 0x00FF00FF;// color of south wall
	}
	g->ray.hlen = (int)sqrt((g->player.px - g->ray.hx) * (g->player.px - g->ray.hx) + (g->player.py - g->ray.hy) * (g->player.py - g->ray.hy));
}

void	check_horizon_lines(t_game *g)
{
	int	power;

	power = (int)log2f((float)PX2);
	if (g->ray.ra > PI && g->ray.ra < (2 * PI))	// looking up
	{
		g->ray.hy = ((g->player.py >> power) << power);//// - 1 - 1;////////////////////////////////////
		g->ray.hx = (int)roundf(g->player.px - ((g->player.py - g->ray.hy) / g->ta[g->ray.ra]));
		g->ray.y_step = -PX2;
		g->ray.x_step = (int)roundf(g->ray.y_step / g->ta[g->ray.ra]);
		calculate_ray_hlen(g);
	}
	else if (g->ray.ra < PI && g->ray.ra > 0)	// looking down
	{
		g->ray.hy = ((g->player.py >> power) << power) + PX2;// + 1;//////////////////////////////////
		g->ray.hx = (int)roundf(g->player.px - ((g->player.py - g->ray.hy) / g->ta[g->ray.ra]));
		g->ray.y_step = PX2;
		g->ray.x_step = (int)roundf(g->ray.y_step / g->ta[g->ray.ra]);
		calculate_ray_hlen(g);
	}
	else if (g->ray.ra == 0 || g->ray.ra == PI)
		g->ray.hlen = 0;
}

void	calculate_ray_vlen(t_game *g)
{
	int	hit = 0;
	int	power;

	power = (int)log2f((float)PX2);
	while (hit == 0)
	{
		if (g->ray.vy < 0 || g->ray.vy >= g->map.mapH * PX2)//512)
		{
			g->ray.vlen = 0;
			return ;
		}
		else
		{
			if (g->ray.ra > (PI / 2) && g->ray.ra < (3 * PI / 2))// looking left
				g->map.x = ((g->ray.vx - 1) >> power);
			else if (g->ray.ra < (PI / 2) || g->ray.ra > (3 * PI / 2))// looking right
				g->map.x = (g->ray.vx >> power);
			g->map.y = (g->ray.vy >> power);
			g->map.pos = g->map.y * g->map.mapW + g->map.x;//printf("pos: %d\n", g->map.pos);
			if (g->map.pos >= 0 && g->map.pos < g->map.mapW * g->map.mapH && g->map.map[g->map.pos] == '1')
				hit =1;//dof = 8;    // hit wall
			else
			{
				g->ray.vx += g->ray.x_step;
				g->ray.vy += g->ray.y_step;
			}
		}
	}
	if (g->ray.ra > (PI / 2) && g->ray.ra < (3 * PI / 2)) // looking left
	{
	//	g->ray.vx = g->ray.vx + 1;
		g->ray.vcolor = 0x00FFFF00;// color of east wall
	}
	else if (g->ray.ra < (PI / 2) || g->ray.ra > (3 * PI / 2)) // looking right
	{
	//	g->ray.vx = g->ray.vx - 1;
		g->ray.vcolor = 0x0000FFFF;// color of west wall
	}
	g->ray.vlen = (int)sqrt((g->player.px - g->ray.vx) * (g->player.px - g->ray.vx) + (g->player.py - g->ray.vy) * (g->player.py - g->ray.vy));
}

void	check_vertical_lines(t_game *g)
{
	int	power;

	power = (int)log2f((float)PX2);
	if (g->ray.ra > (PI / 2) && g->ray.ra < (3 * PI / 2)) // looking left
	{
		g->ray.vx = ((g->player.px >> power) << power);// - 1 - 1;/////////////////////////////////////////
		g->ray.vy = (int)roundf(g->player.py - (g->player.px - g->ray.vx) * g->ta[g->ray.ra]);
		g->ray.x_step = -PX2;
		g->ray.y_step = (int)roundf(g->ray.x_step * g->ta[g->ray.ra]);
		calculate_ray_vlen(g);
	}
	else if (g->ray.ra < (PI / 2) || g->ray.ra > (3 * PI / 2))
	{
		g->ray.vx = ((g->player.px >> power) << power) + PX2;// + 1;   // looking right////////////////////////////////////////////
		g->ray.vy = (int)roundf(g->player.py - (g->player.px - g->ray.vx) * g->ta[g->ray.ra]);
		g->ray.x_step = PX2;
		g->ray.y_step = (int)roundf(g->ray.x_step * g->ta[g->ray.ra]);
		calculate_ray_vlen(g);
	}
	else if (g->ray.ra == (PI / 2) || g->ray.ra == (3 * PI / 2))
		g->ray.vlen = 0;
}

void	set_image(t_game *g, t_colors *colors)
{
	//bg_to_image(&g->img3, 0x00C0C0C0);
	floor_to_image(&g->img3, colors);
	// ceiling_to_image(&g->img3, 0x00ff5050);//COLOR ROJO

	// bg_to_image(&g->img2, 0x00606060);    				// grey background
	// map_to_image(&g->img2, &g->map, 0x000000FF);			// blue boxes (walls)
	// grid_to_image(&g->img2, 0x00FFFF00);					// yellow grid lines
	// player_to_image(&g->img2, &g->player, 0x00FF0000);	// red player
	direction_to_image(g, 0x00FFFFFF);//(&g->img, &g->player, 0x00FFFFFF);// white direction
	//ray_to_image(g, 0x00FF0000);//0x0000FF00 green
}
