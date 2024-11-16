/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:35:54 by spereyra          #+#    #+#             */
/*   Updated: 2024/09/18 18:08:29 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	floor_to_image(t_img *img, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < (WINY / 2))
	{
		x = 0;   
		while (x < WINX)
		{
			set_pixel_to_image(img, x, y, color);
			x++;
		}
		y++;
	}
}


void	ceiling_to_image(t_img *img, int color)
{
	int	x;
	int	y;

	y = WINY / 2;
	while (y < (WINY))
	{
		x = 0;   
		while (x < WINX)
		{
			set_pixel_to_image(img, x, y, color);
			x++;
		}
		y++;
	}
}

void	bg_to_image(t_game *g, int color)
{
	int	x;
	int	y;

	y = 0;
	// while (y < g->img2.h)
	while (y < WINY / 5)
	{
		x = 0;   
		// while (x < g->img2.w)
		while (x < WINX / 5)
		{
			set_pixel_to_image(&g->img2, x, y, color);
			x++;
		}
		y++;
	}
}

void	grid_to_image(t_img *img, int color)
{
	int	x;
	int	y;

	y = 0;
	// while (y < WINY / 5)
	while (y < img->h)
	{
		x = 0;
		// while (x < WINX / 5)
		while (x < img->w)
		{
			if ((y % PX2B) == 0 || (x % PX2B) == 0)
				set_pixel_to_image(img, x, y, color);
			x++;
		}
		y++;
	}
}

void	box_to_image(t_img *img, int x, int y, int color)
{
	int	x0;
	int	y0;

	x0 = x;
	y0 = y;
	while (y < y0 + PX2B)
	{
		x = x0;
		while (x < x0 + PX2B)
		{
			set_pixel_to_image(img, x, y, color);
			x++;
		}
		y++;
	}
}
void	map_to_image(t_img *img, t_map *map, int color)
{
	int	x;
	int	y;

    y = 0;
	// while (y < (map->mapH / WINY)
	while (y < map->mapH)
	{
		x = 0;
		//while (x < (map->mapW / WINX) && map->map[y * map->mapW + x] != '\0')
		while (x < map->mapW && map->map[y * map->mapW + x] != '\0')
		{
			if (map->map[y * map->mapW + x] == '1')
				box_to_image(img, x * PX2, y * PX2, color);
				//box_to_image(img, x * PX2B, y * PX2B, color);
				//box_to_image(img, x * (PX2 / 5), y * (PX2 / 5), color);
			x++;
		}
		y++;
	}
}

void	player_to_image(t_img *img, t_player *player, int color)
{
	int	x;
	int	y;
	int x0;
	int y0;

	x0 = player->px - 4;
	y0 = player->py - 4;
	y = y0;//player->py - 4;
	while (y <= player->py + 4)  // 9 pixels is the size of the mini player
	{
		x = x0;//player->px -4;
		while (x <= player->px + 4)
		{
			set_pixel_to_image(img, x, y, color);
			x++;
		}
		y++;
	}
}

void	direction_to_image(t_game *g, int color)//(t_img *img, t_player *player, int color)
{
	int	x;
	int	y;
	int	hyp;	// hyp is the length of the view direction arrow

	(void)color;
	hyp = 1;
	while (hyp <= 30)
	{
		//x = player->px + (int)(cos(player->pa) * hyp);
		x = (int)(g->player.px + (g->co[g->player.pa] * hyp));
		//printf("pa: %d\tcos(pa) * hyp: %f * %d\n", g->player.pa, g->cosines[g->player.pa], hyp);
		//y = player->py + (int)(sin(player->pa) * hyp);
		y = (int)(g->player.py + (g->si[g->player.pa] * hyp));
		//printf("pa: %d\tsin(pa) * hyp: %f * %d\n\n", g->player.pa, g->sines[g->player.pa], hyp);
		// if (x >= 0 && x <= 511 && y >=0 && y <= 511)//////////
		if (x >= 0 && x < WINX && y >= 0 && y < WINY)//////////
		{
			//set_pixel_to_image(&g->img3, x, y, color);//imprime una linea en la direccion de la vista
			//printf("x:\t%d\ny:\t%d\n\n", x, y);//////////
		}
		hyp++;
	}
}

void	ray_to_image(t_game *g, int color)//(t_img *img, t_ray *ray, t_player *player, int color)
{
	int	x;
	int	y;
	int	hyp;

	hyp = 1;
	x = 0;//68;
	y = 0;//452;
	while (hyp <= g->ray.len)
	{
		x = (int)(g->player.px + roundf(g->co[g->ray.ra] * hyp));//(g->co[g->player.pa] * hyp));
		y = (int)(g->player.py + roundf(g->si[g->ray.ra] * hyp));//(g->si[g->player.pa] * hyp));
	//	if (x >= 0 && x <= 511 && y >= 0 && y<= 511)///////////////(x >= 64 && x <= 447 && y >= 64 && y<= 447)/////////////
	//	{
			set_pixel_to_image(&g->img2, x, y, color);
			//printf("x:\t\%d\ny:\t%d\n", x, y);//////////////
	//	}
		hyp++;
	}
/*
	hyp = 1;
	x = 0;//68;
	y = 0;//452;
	while (hyp <= g->ray.vlen)
	{
		x = (int)(g->player.px + roundf(g->co[g->ray.ra] * hyp));//(g->co[g->player.pa] * hyp));
		y = (int)(g->player.py + roundf(g->si[g->ray.ra] * hyp));//(g->si[g->player.pa] * hyp));
	//	if (x >= 0 && x <= 511 && y >= 0 && y<= 511)///////////////(x >= 64 && x <= 447 && y >= 64 && y<= 447)/////////////
	//	{
			set_pixel_to_image(&g->img, x, y, 0x0000FF00);
			//printf("x:\t\%d\ny:\t%d\n", x, y);//////////////
	//	}
		hyp++;
	}
*/
}

/*int	get_color(t_game *g)// get the color of the wall
{
	int	color;

	if (g->ray.ra >= (7 * PI / 4) || g->ray.ra < (PI / 4)) // 7*PI/4=549 and PI/4=78 because of integer division!!!
		color = 0x00FFFF00; // east wall
	else if (g->ray.ra >= (PI / 4) && g->ray.ra < (3 * PI / 4))
		color = 0x00FF00FF; // south wall
	else if (g->ray.ra >= (3 * PI / 4) && g->ray.ra < (5 * PI / 4))
		color = 0x0000FFFF; // west wall
	else if (g->ray.ra >= (5 * PI / 4) && g->ray.ra < (7 * PI / 4))
		color = 0x00FFFFFF;//north wall
	return (color);
}*/

void	slice_to_image(t_game *g, int col, int top_px, int bottom_px)//, int color)	// draw the wall
{
	int	x;
	int	wall_slice;
	//int	color;

	x = 0;
	wall_slice = WINX / 128;//768 / 128 fov = 1.28 radians
	//color = get_color(g);
	while (top_px < bottom_px)
	{
		x = 0;
		while (x < wall_slice)
		{
			set_pixel_to_image(&g->img3, col + x, top_px, g->ray.color);
			x++;
		}
		top_px++;
	}
}

void	wall_to_image(t_game *g, int col)
{
	int	wall_h;
	int	bottom_px;
	int	top_px;
	int	cos_angle;

	cos_angle = g->player.pa - g->ray.ra;
	if (cos_angle < 0)
		cos_angle = cos_angle + 2 * PI;
	else if (cos_angle > 2 * PI)
		cos_angle = cos_angle - 2 * PI;
	g->ray.len = roundf(g->ray.len * g->co[cos_angle]); // fix the fisheye

	wall_h = (roundf)((64.f / g->ray.len) * ((g->img3.w / 2) / g->ta[64]));//ta[g->ray.ra - g->player.pa])); // get the wall height
	if (wall_h < 0)
		wall_h = (-1) * wall_h;
	bottom_px = (WINY / 2) + (wall_h / 2);//(g->h / 2) + (wall_h / 2); // get the bottom pixel
	top_px = (WINY / 2) - (wall_h / 2);//(g->h / 2) - (wall_h / 2); // get the top pixel
	if (bottom_px > WINY)//(bottom_px > g->h) // check the bottom pixel
		bottom_px = WINY;//bottom_px = g->h;
	if (top_px < 0) // check the top pixel
		top_px = 0;
	slice_to_image(g, col, top_px, bottom_px);
}
