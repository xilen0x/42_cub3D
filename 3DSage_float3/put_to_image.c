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

#include "cub3D.h"

void	floor_to_image(t_img *img, int color)
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

void	ceiling_to_image(t_img *img, int color)
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

void	bg_to_image(t_img *img, int color)
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

void	grid_to_image(t_img *img, int color)
{
	int	x;
	int	y;

    y = 0;
	while (y < img->h)
	{
		x = 0;
		while (x < img->w)
		{       
			if ((y % 32) == 0 || (x % 32) == 0)//if ((y % TL) == 0 || (x % TL) == 0)
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
	while (y < y0 + 32)//TL)
	{
		x = x0;
		while (x < x0 + 32)//TL)
		{
			set_pixel_to_image(img, x, y, color);
			x++;
		}
		y++;
	}
}
/* OK!!!
void	map_to_image(t_img *img, t_map *map, int color)
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
				box_to_image(img, x * 32, y * 32, color);//box_to_image(img, x * TL, y * TL, color);
			x++;
		}
		y++;
	}
}*/

void	map_to_image(t_img *img, t_map *map, int color)
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
				box_to_image(img, x * 32, y * 32, color);//box_to_image(img, x * TL, y * TL, color);
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

	x0 = (player->px)/2 - 4;//8;
	y0 = (player->py)/2 - 4;//8;
	y = y0;
	while (y <= (player->py / 2) + 4)//8)  // 17 pixels is the size of the mini player
	{
		x = x0;
		while (x <= (player->px / 2) + 4)//8)
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
	float	px;
	float	py;

	hyp = 1;
	px = g->player.px / 2;
	py = g->player.py / 2;
	while (hyp <= 15)//30)
	{
		x = (int)(px + (cosf(g->player.pa) * hyp));//x = (int)(g->player.px + (cosf(g->player.pa) * hyp));
		y = (int)(py + (sinf(g->player.pa) * hyp));//y = (int)(g->player.py + (sinf(g->player.pa) * hyp));
		set_pixel_to_image(&g->img2, x, y, color);
		hyp++;
	}
}

void	ray_to_image(t_game *g, int color)//(t_img *img, t_ray *ray, t_player *player, int color)
{
	int	x;
	int	y;
	int	hyp;
	float	px;
	float	py;

	hyp = 1;
	x = 0;
	y = 0;
	px = g->player.px / 2;
	py = g->player.py / 2;
	while (hyp <= g->ray.len / 2)
	{
		x = (int)(px + (cosf(g->ray.ra) * hyp));//x = (int)(g->player.px + (cosf(g->ray.ra) * hyp));
		y = (int)(py + (sinf(g->ray.ra) * hyp));//y = (int)(g->player.py + (sinf(g->ray.ra) * hyp));
			set_pixel_to_image(&g->img2, x, y, color);
		hyp++;
	}
}


//IT WORKS OK WITH COLOURS!!!!!!!!!!!!!!!!!!
/*void	draw_wall(t_game *g, int col, int top_pix, int bot_pix)	// draw the wall
{
	while (top_pix < bot_pix)
		set_pixel_to_image(&g->img3, col, top_pix++, g->ray.color);
}*/



void	draw_wall(t_game *g, int col, float wall_h, int top_pix, int bot_pix)
{
	float	wall_x;
	int		texture_x;
	int		texture_y;
	int		screen_y;
	int		d;

	//wall_x = (g->ray.path == g->ray.vpath) ? g->ray.vy : g->ray.hx;
	if (g->ray.path == g->ray.vpath)
		wall_x = g->ray.vy;
	else
		wall_x = g->ray.hx;
	texture_x = (int)(wall_x) % 64;
	screen_y = top_pix;
	while (screen_y < bot_pix)
	{
        d = screen_y * 256 - g->img3.h * 128 + wall_h * 128;
        texture_y = ((d * g->tex[g->ray.path].h) / wall_h) / 256;//texture_y = (int)(((screen_y - top_pix) * 64) / wall_h);
		texture_y = texture_y % 64;

        int tex_pos = (texture_y * g->tex[g->ray.path].line_len) + 
                      (texture_x * (g->tex[g->ray.path].bpp / 8));
        int color = *(int *)(g->tex[g->ray.path].addr + tex_pos);
        set_pixel_to_image(&g->img3, col, screen_y, color);
		screen_y++;
    }
}

void	render_wall(t_game *g, int col)
{
	float	cos_angle;
	float	wall_h;
	//float	wall_x;
	int	bot_pix;
	int	top_pix;
	//int texture_x, texture_y;

	cos_angle = g->player.pa - g->ray.ra;
	if (cos_angle < 0)
		cos_angle = cos_angle + 2 * PI;
	else if (cos_angle > 2 * PI)
		cos_angle = cos_angle - 2 * PI;
	g->ray.len = (g->ray.len * cosf(cos_angle)); // fix the fisheye
	wall_h = (TL / g->ray.len) * ((g->img3.w / 2) / tanf(g->player.fov / 2));
	bot_pix = (g->img3.h / 2) + (wall_h / 2); // get the bottom pixel
	top_pix = (g->img3.h / 2) - (wall_h / 2); // get the top pixel
	if (bot_pix > g->img3.h) // check the bottom pixel
		bot_pix = g->img3.h;
	if (top_pix < 0) // check the top pixel
		top_pix = 0;
	
	// Determinar coordenada X de la textura
    //printf("RayPath:%s - Texture width:%d\n", g->ray.path, g->tex[1].w);
	
	//wall_x = (g->ray.path == g->ray.vpath) ? g->ray.vy : g->ray.hx;
	//wall_x -= floorf(wall_x);
	//printf("decimal wall_x:%f\n", wall_x);
    //texture_x = (int)(wall_x * 64);//texture_x = (int)(wall_x * g->tex[g->ray.path].w);
	//texture_x = (int)(wall_x) % 64;
	// Dibujar la pared píxel a píxel
    /*for (int screen_y = top_pix; screen_y < bot_pix; screen_y++)
	{
        int d = screen_y * 256 - g->img3.h * 128 + wall_h * 128;
        texture_y = ((d * g->tex[g->ray.path].h) / wall_h) / 256;//texture_y = (int)(((screen_y - top_pix) * 64) / wall_h);
		texture_y = texture_y % 64;

        int tex_pos = (texture_y * g->tex[g->ray.path].line_len) + 
                      (texture_x * (g->tex[g->ray.path].bpp / 8));
        int color = *(int *)(g->tex[g->ray.path].addr + tex_pos);

        set_pixel_to_image(&g->img3, col, screen_y, color);
    }*/
	draw_wall(g, col, wall_h, top_pix, bot_pix);
}

/*
int	get_texture_pixel(t_img *tex, int x, int y)
{
	char *pixel = tex->addr + (y * tex->line_len + x * (tex->bpp / 8));
	int color = *(int*)pixel;
	return color;
}*/

/*void load_texture(t_img *tex, char *path, void *mlx)
{
    tex->img_ptr = mlx_xpm_file_to_image(mlx, path, &tex->w, &tex->h);  // leaks here!!!
    tex->addr = mlx_get_data_addr(tex->img_ptr, &tex->bpp, &tex->line_len, &tex->endian);
}*/
/*
void	draw_wall(t_game *g, int col, int top_pix, int bot_pix)	// draw the wall
{
	while (top_pix < 0)
		top_pix++;
	while (bot_pix > g->img3.h)
		top_pix--;
	while (top_pix < bot_pix)
		set_pixel_to_image(&g->img3, col, top_pix++, g->ray.color);
}


void	render_wall(t_game *g, int col)
{
	float	cos_angle;
	float	wall_h;
	int	bot_pix;
	int	top_pix;

	cos_angle = g->player.pa - g->ray.ra;
	if (cos_angle < 0)
		cos_angle = cos_angle + 2 * PI;
	else if (cos_angle > 2 * PI)
		cos_angle = cos_angle - 2 * PI;
	g->ray.len = (g->ray.len * cosf(cos_angle)); // fix the fisheye
	wall_h = (TL / g->ray.len) * ((g->img3.w / 2) / tanf(g->player.fov / 2));
	bot_pix = (g->img3.h / 2) + (wall_h / 2); // get the bottom pixel
	top_pix = (g->img3.h / 2) - (wall_h / 2); // get the top pixel
	if (bot_pix > g->img3.h) // check the bottom pixel
		bot_pix = g->img3.h;
	if (top_pix < 0) // check the top pixel
		top_pix = 0;
	draw_wall(g, col, top_pix, bot_pix); // draw the wall

}*/
