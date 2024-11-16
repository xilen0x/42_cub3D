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

void	set_pixel_to_image(t_img *img, int x, int y, int color)
{
	char	*offset;

	// if (x < 0 || x >= WINX || y < 0 || y >= WINY)
	// 	return ;
	// Line len is in bytes. If img_w = 1024 pixels, so len_line ~ 4096 bytes (can differ for aligment)
	offset = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)offset = color;
}
// void	set_player(t_map *map, t_player *player)
// {
// 	int	x;
// 	int	y;

//     y = 0;
// 	while (y < map->mapH)
// 	{
// 		x = 0;
// 		while (x < map->mapW)
// 		{       
// 			if (map->map[y * map->mapW + x] == 'P')
// 			{
// 				player->px = x * PX2 + PX2/2; // PX/2 is the centre of tile
// 				player->py = y * PX2 + PX2/2; // PX/2 is the centre of tile
// 				player->pa = 0.f;//PI / 2;//M_PI;
// 				player->fov = 1.05;
// 				return ;
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }

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
				player->px = x * PX2 + PX2B/2; // PX/2 is the centre of tile
				player->py = y * PX2 + PX2B/2; // PX/2 is the centre of tile
				player->pa = 0;//PI / 2;//M_PI;
				player->fov = 1.05;
				return ;
			}
			x++;
		}
		y++;
	}
}

void    set_rays(t_game *g)
{
	int	rays;

	g->ray.ra = g->player.pa - 30 * 0.0175;
	rays = 0;
	printf("Ray angle:%f\n", g->ray.ra);
	while (rays < 768)//g->img3.w)// w=768 //128)
	{
		g->ray.ra = g->ray.ra + (g->player.fov / 768);//g->img3.w);// fov/768
		printf("Ray angle:%f - dif:%f\n", g->ray.ra, (g->player.fov / g->img3.w));
		if (g->ray.ra < 0)
			g->ray.ra = g->ray.ra + 2 * PI;
		else if (g->ray.ra >= 2 * PI)
			g->ray.ra = g->ray.ra - 2 * PI;
		printf("2PI:%f\n", 2 * PI);
		printf("Norm angle:%f\n", g->ray.ra);
		check_horizon_lines(g);
		check_vertical_lines(g);
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
			g->ray.len = g->ray.hlen;
		else if (g->ray.hlen < g->ray.vlen)
		{
			g->ray.len = g->ray.hlen;
			g->ray.color = g->ray.hcolor;
		}
		else if (g->ray.vlen < g->ray.hlen)
		{
			g->ray.len = g->ray.vlen;
			g->ray.color = g->ray.vcolor;
		}
		printf("hlen:%f - hx:%f - hy:%f - angle:%f\n", g->ray.hlen, g->ray.hx,  g->ray.hy, g->ray.ra);
		printf("vlen:%f - vx:%f - vy:%f - angle:%f\n", g->ray.vlen, g->ray.vx, g->ray.vy, g->ray.ra);
		printf("len:%f - angle:%f\n\n", g->ray.len, g->ray.ra);
		
		ray_to_image(g, g->ray.color);//0x00FF0000);//0x0000FF00 green
		//printf("Current col: %d\n", (int)(radians * (g->w / 128)));
		render_wall(g, rays);// + (g->w / 128))));////128////////
		
		rays++;
	}
}

void	calculate_ray_hlen(t_game *g)
{
	int	hit = 0;
	
	while (hit == 0)
	{
		if ((g->ray.hx < 64) || (g->ray.hx > 448))//((g->ray.hx <= PX2 + 1 && g->ray.hy != PX2) || (g->ray.hx >= g->map.mapW * PX2 - PX2 - 1 && g->ray.hy != PX2))//
		{
			g->ray.hlen = 0;
			return ;
		}
		g->map.x = (int)(g->ray.hx) >> 6;
		if (g->ray.ra > PI && g->ray.ra < 2 * PI)// looking up
			g->map.y = (int)(g->ray.hy - 1) >> 6;
		else if (g->ray.ra < PI && g->ray.ra > 0)//looking down
			g->map.y = (int)(g->ray.hy) >> 6;
		g->map.pos = g->map.y * g->map.mapW + g->map.x;
		
		//if ((g->ray.hx % 64 == 0 || g->ray.hx % 64 == 1) && g->ray.hy % 64 == 0 && g->map.pos >= 8 && g->map.pos < g->map.mapW * g->map.mapH && (g->map.map[g->map.pos] == '1' || g->map.map[g->map.pos - 1] == '1'))
		//	hit =1;//dof = 8;    // hit wall
		//else if ((g->ray.hx % 64 == 63) && g->ray.hy % 64 == 0 && g->map.pos >= 0 && g->map.pos < g->map.mapW * g->map.mapH - 1 && (g->map.map[g->map.pos] == '1' || g->map.map[g->map.pos + 1] == '1'))
		//		hit =1;//dof = 8;    // hit wall
		//else 
		if (g->map.pos >= 0 && g->map.pos < g->map.mapW * g->map.mapH && g->map.map[g->map.pos] == '1')
				hit = 1;//dof = 8;    // hit wall
		else
		{
			g->ray.hx += g->ray.x_step;
			g->ray.hy += g->ray.y_step;
		}
	}
	if (g->ray.ra > PI && g->ray.ra < (2 * PI))	// looking up
		g->ray.hcolor = 0x00C0C0C0;//0x00FFFFFF;// color of north wall
	else if (g->ray.ra <= PI && g->ray.ra >= 0)	// looking down
		g->ray.hcolor = 0x00FF00FF;// color of south wall
	g->ray.hlen = sqrtf((g->player.px - g->ray.hx) * (g->player.px - g->ray.hx) + (g->player.py - g->ray.hy) * (g->player.py - g->ray.hy));
}

void	check_horizon_lines(t_game *g)
{
	if (g->ray.ra > PI && g->ray.ra < (2 * PI))	// looking up
	{
		g->ray.hy = ((int)(g->player.py) >> 6) << 6;
		g->ray.hx = (int)roundf(g->player.px - ((g->player.py - g->ray.hy) / tanf(g->ray.ra)));//g->ta[g->ray.ra]
		g->ray.y_step = -PX2;
		g->ray.x_step = (int)roundf(g->ray.y_step / tanf(g->ray.ra));//g->ta[g->ray.ra]);
		calculate_ray_hlen(g);
	}
	else if (g->ray.ra < PI && g->ray.ra > 0)	// looking down
	{
		g->ray.hy = (((int)(g->player.py) >> 6) << 6) + PX2;
		g->ray.hx = (int)roundf(g->player.px - ((g->player.py - g->ray.hy) / tanf(g->ray.ra)));
		g->ray.y_step = PX2;
		g->ray.x_step = (int)roundf(g->ray.y_step / tanf(g->ray.ra));
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
		if ((g->ray.vy < 64) || (g->ray.vy > 448))//((g->ray.vy <= PX2 + 1 && g->ray.vx != PX2) || (g->ray.vy >= g->map.mapH * PX2 - PX2 - 1 && g->ray.vx != g->map.mapH * PX2 - PX2))//
		{
			g->ray.vlen = 0;
			return ;
		}
		if (g->ray.ra > (PI / 2) && g->ray.ra < (3 * PI / 2))// looking left
			g->map.x = ((int)(g->ray.vx - 1) >> 6);
		else if (g->ray.ra < (PI / 2) || g->ray.ra > (3 * PI / 2))// looking right
			g->map.x = (int)(g->ray.vx) >> 6;
		g->map.y = (int)g->ray.vy >> 6;
		g->map.pos = g->map.y * g->map.mapW + g->map.x;//printf("vx:%d -- vy:%d\n", g->ray.vx, g->ray.vy);//printf("pos: %d\n", g->map.pos);
			
		//if (g->ray.vx % 64 == 0 && (g->ray.vy % 64 == 0 || g->ray.vy % 64 == 1) && g->map.pos >= 8 && g->map.pos < g->map.mapW * g->map.mapH && (g->map.map[g->map.pos] == '1' || g->map.map[g->map.pos - 8] == '1'))
		//		hit =1;//dof = 8;    // hit wall

		//else if (g->ray.vx % 64 == 0 && (g->ray.vy % 64 == 63) && g->map.pos < g->map.mapW * g->map.mapH - 8 && (g->map.map[g->map.pos] == '1' || g->map.map[g->map.pos + 8] == '1'))
		//		hit =1;//dof = 8;    // hit wall

		//else
		if (g->map.pos >= 0 && g->map.pos < g->map.mapW * g->map.mapH && g->map.map[g->map.pos] == '1')
				hit =1;//dof = 8;    // hit wall
		else
		{
			g->ray.vx += g->ray.x_step;
			g->ray.vy += g->ray.y_step;
		}
	}
	if (g->ray.ra > (PI / 2) && g->ray.ra < (3 * PI / 2)) // looking left
		g->ray.vcolor = 0x00FFFF00;// color of east wall
	else if (g->ray.ra < (PI / 2) || g->ray.ra > (3 * PI / 2)) // looking right
		g->ray.vcolor = 0x0000FFFF;// color of west wall
	g->ray.vlen = sqrtf((g->player.px - g->ray.vx) * (g->player.px - g->ray.vx) + (g->player.py - g->ray.vy) * (g->player.py - g->ray.vy));
}

void	check_vertical_lines(t_game *g)
{
	if (g->ray.ra > (PI / 2) && g->ray.ra < (3 * PI / 2)) // looking left
	{
		g->ray.vx = (((int)g->player.px >> 6) << 6);
		g->ray.vy = (g->player.py - (g->player.px - g->ray.vx) * tanf(g->ray.ra));
		g->ray.x_step = -PX2;
		g->ray.y_step = (g->ray.x_step * tanf(g->ray.ra));
		calculate_ray_vlen(g);
	}
	else if (g->ray.ra < (PI / 2) || g->ray.ra > (3 * PI / 2))
	{
		g->ray.vx = (((int)g->player.px >> 6) << 6) + PX2;
		g->ray.vy = (g->player.py - (g->player.px - g->ray.vx) * tanf(g->ray.ra));
		g->ray.x_step = PX2;
		g->ray.y_step = (g->ray.x_step * tanf(g->ray.ra));
		calculate_ray_vlen(g);
	}
	else if (g->ray.ra == (PI / 2) || g->ray.ra == (3 * PI / 2))
		g->ray.vlen = 0;
}

void	set_image(t_game *g)
{
	int	red;
	int	green;

	red = g->cols.f_color_hex;
	green = g->cols.c_color_hex;

	floor_to_image(&g->img3, green);//g->cols.f_color_hex);
	ceiling_to_image(&g->img3, red);//g->cols.c_color_hex);
	bg_to_image(g, 0x00FFCDD2);    	// background color rosado minimap
	map_to_image(&g->img2, &g->map, 0x000000FF);			// blue boxes (walls)
	grid_to_image(&g->img2, 0x00FFFF00);					// yellow grid lines
	player_to_image(&g->img2, &g->player, 0x00FF0000);	// red player
	direction_to_image(g, 0x00FFFFFF);//(&g->img, &g->player, 0x00FFFFFF);// white direction
}
