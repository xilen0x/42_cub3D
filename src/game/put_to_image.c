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

void	floor_to_image(t_img *img, unsigned int color)
{
	int	x;
	int	y;

    y = 0;
	while (y < (img->h / 2))
	{
		x = 0;   
		while (x < img->w)
		{
			set_pixel_to_image(img, x, y, color);
			x++;
		}
		y++;
	}
}

void	ceiling_to_image(t_img *img, unsigned int color)
{
	int	x;
	int	y;

    y = img->h / 2;
	while (y < img->h)
	{
		x = 0;   
		while (x < img->w)
		{
			set_pixel_to_image(img, x, y, color);
			x++;
		}
		y++;
	}
}

void	bg_to_image(t_img *img, unsigned int color)
{
	int	x;
	int	y;

    y = 0;
	while (y < img->h)
	{
		x = 0;   
		while (x < img->w)
		{
			set_pixel_to_image(img, x, y, color);
			x++;
		}
		y++;
	}
}

void	grid_to_image(t_img *img, unsigned int color)
{
	int	x;
	int	y;

    y = 0;
	while (y < img->h)
	{
		x = 0;
		while (x < img->w)
		{       
			if ((y % TL32) == 0 || (x % TL32) == 0)
				set_pixel_to_image(img, x, y, color);
			x++;
		}
		y++;
	}
}

void	box_to_image(t_img *img, int x, int y, unsigned int color)
{
	int	x0;
	int	y0;

	x0 = x;
	y0 = y;
	while (y < y0 + TL32)
	{
		x = x0;
		while (x < x0 + TL32)
		{
			set_pixel_to_image(img, x, y, color);
			x++;
		}
		y++;
	}
}

void	map_to_image(t_img *img, t_map *map, unsigned int color)
{
	int	x;
	int	y;

    y = 0;
	while (y < map->mapH)
	{
		x = 0;
		while (x < map->mapW)
		{
			if (map->map[y * map->mapW + x] == '1')
				box_to_image(img, x * TL32, y * TL32, color);
				// box_to_image(img, x * TL, y * TL, color);
			x++;
		}
		y++;
	}
}

void	player_to_image(t_img *img, t_player *player,unsigned int color)
{
	int	x;
	int	y;
	int x0;
	int y0;

	x0 = player->px - 8;
	y0 = player->py - 8;
	y = y0;//player->py - 4;
	while (y <= player->py + 8)  // 17 pixels is the size of the mini player
	{
		x = x0;//player->px -4;
		while (x <= player->px + 8)
		{
			set_pixel_to_image(img, x, y, color);
			x++;
		}
		y++;
	}
}

void	direction_to_image(t_game *g,unsigned int color)//(t_img *img, t_player *player, int color)
{
	int	x;
	int	y;
	int	hyp;	// hyp is the length of the view direction arrow

	hyp = 1;
	while (hyp <= 30)
	{
		x = (int)(g->player.px + (cosf(g->player.pa) * hyp));
		y = (int)(g->player.py + (sinf(g->player.pa) * hyp));
		set_pixel_to_image(&g->img2, x, y, color);
		hyp++;
	}
}

void	ray_to_image(t_game *g, unsigned int color)//(t_img *img, t_ray *ray, t_player *player, int color)
{
	int	x;
	int	y;
	int	hyp;

	hyp = 1;
	x = 0;
	y = 0;
	while (hyp <= g->ray.len)
	{
		x = (int)(g->player.px + (cosf(g->ray.ra) * hyp));
		y = (int)(g->player.py + (sinf(g->ray.ra) * hyp));
			set_pixel_to_image(&g->img2, x, y, color);
		hyp++;
	}
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

void	draw_wall(t_game *g, int col, int top_pix, int bot_pix)	// draw the wall
{
	while (top_pix < bot_pix)
		set_pixel_to_image(&g->img3, col, top_pix++, g->ray.color);
}

void	render_wall(t_game *g, int col)
{
	float	cos_angle;
	float	wall_h;
	int		bot_pix;
	int		top_pix;

	cos_angle = g->player.pa - g->ray.ra;
	if (cos_angle < 0)
		cos_angle = cos_angle + 2 * PI;
	else if (cos_angle > 2 * PI)
		cos_angle = cos_angle - 2 * PI;
	g->ray.len = (g->ray.len * cosf(cos_angle)); // fix the fisheye
	//g->ray->distance *= cos(nor_angle(mlx->ray->ray_ngl - mlx->ply->angle)); // fix the fisheye
	wall_h = (TL / g->ray.len) * ((g->img3.w / 2) / tanf(g->player.fov / 2));
	bot_pix = (g->img3.h / 2) + (wall_h / 2); // get the bottom pixel
	top_pix = (g->img3.h / 2) - (wall_h / 2); // get the top pixel
	if (bot_pix > g->img3.h) // check the bottom pixel
		bot_pix = g->img3.h;
	if (top_pix < 0) // check the top pixel
		top_pix = 0;
	draw_wall(g, col, top_pix, bot_pix); // draw the wall
}
