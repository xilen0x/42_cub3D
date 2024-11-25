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

void calculate_visible_area(t_game *g, int *start_x, int *start_y)
{
    int player_tile_x = g->player.px - (g->img22.w / 2);//(MINIMAP_WIDTH / 2);
    int player_tile_y = g->player.py - (g->img22.h / 2);//(MINIMAP_HEIGHT / 2);

    *start_x = player_tile_x;
    *start_y = player_tile_y;

    // Asegúrate de que la ventana visible no se salga del mapa
    if (*start_x < 0) *start_x = 0;
    if (*start_y < 0) *start_y = 0;
	if (*start_x + g->img22.w > g->img2.w) *start_x = g->img2.w - g->img22.w;//if (*start_x + MINIMAP_WIDTH > g->img2.w) *start_x = g->img2.w - MINIMAP_WIDTH;
    if (*start_y + g->img22.h > g->img2.h) *start_y = g->img2.h - g->img22.h;//if (*start_y + MINIMAP_HEIGHT > g->img2.h) *start_y = g->img2.h - MINIMAP_HEIGHT;
}

void extract_visible_area(t_img *src, t_img *dest, int start_x, int start_y)
{
    int y, src_offset, dest_offset;

    y = 0;
    while (y < dest->h)//MINIMAP_HEIGHT)
    {
        // Calcula el puntero inicial para la línea en ambas imágenes
        src_offset = (start_y + y) * src->line_len + (start_x * (src->bpp / 8));
        dest_offset = y * dest->line_len;

        // Copia una línea de la sección visible
        ft_memcpy(&dest->addr[dest_offset], &src->addr[src_offset], dest->w * (src->bpp / 8));//memcpy(&dest->addr[dest_offset], &src->addr[src_offset], MINIMAP_WIDTH * (src->bpp / 8));
        y++;
    }
}

void display_minimap(t_game *g)
{
    int start_x, start_y;

	// Calcula el área visible
    calculate_visible_area(g, &start_x, &start_y);

    // Copia el área visible del mapa completo a un buffer temporal
    extract_visible_area(&g->img2, &g->img22, start_x, start_y);
	
    // Dibuja el buffer en la ventana
    mlx_put_image_to_window(g->mlx, g->win, g->img22.img_ptr, 0, 0);
}


/*Background color of the ground - map*/
// void	floor_to_image(t_img *img, int color)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < (img->h / 2))
// 	{
// 		x = 0;
// 		while (x < img->w)
// 		{
// 			set_pixel_to_image(img, x, y, color);
// 			x++;
// 		}
// 		y++;
// 	}
// }

/*Sky background color - map*/
// void	ceiling_to_image(t_img *img, int color)
// {
// 	int	x;
// 	int	y;

// 	y = img->h / 2;
// 	while (y < img->h)
// 	{
// 		x = 0;
// 		while (x < img->w)
// 		{
// 			set_pixel_to_image(img, x, y, color);
// 			x++;
// 		}
// 		y++;
// 	}
// }

void	draw_wall(t_game *g, int col, float wall_h, int top_pix, int bot_pix)
{
	float			wall_x;
	unsigned int	texture_x;
	unsigned int	texture_y;
	unsigned int	screen_y;
	unsigned int	d;
	unsigned int	tex_pos;
	unsigned int	color;

	if (g->ray.path < 0 || g->ray.path >= 4)
	{
		ft_printf("Invalid ray path: %d\n", g->ray.path);
		return ;
	}
	if (g->tex[g->ray.path].addr == NULL)
	{
		ft_printf("Texture address is NULL for path: %d\n", g->ray.path);
		return ;
	}
	if (g->ray.path == g->ray.vpath)
		wall_x = g->ray.vy;
	else
		wall_x = g->ray.hx;
	texture_x = (unsigned int)(wall_x) % 64;
	screen_y = top_pix;
	while (screen_y < (unsigned int)bot_pix)
	{
		d = screen_y * 256 - g->img3.h * 128 + wall_h * 128;
		texture_y = ((d * g->tex[g->ray.path].h) / wall_h) / 256;
		texture_y = texture_y % 64;
		tex_pos = (texture_y * g->tex[g->ray.path].line_len) + \
		(texture_x * (g->tex[g->ray.path].bpp / 8));
		color = *(unsigned int *)(g->tex[g->ray.path].addr + tex_pos);
		set_pixel_to_image(&g->img3, col, screen_y, color);
		screen_y++;
	}
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
	g->ray.len = (g->ray.len * cosf(cos_angle));
	wall_h = (TL / g->ray.len) * ((g->img3.w / 2) / tanf(g->player.fov / 2));
	bot_pix = (g->img3.h / 2) + (wall_h / 2);
	top_pix = (g->img3.h / 2) - (wall_h / 2);
	if (bot_pix > g->img3.h)
		bot_pix = g->img3.h;
	if (top_pix < 0)
		top_pix = 0;
	draw_wall(g, col, wall_h, top_pix, bot_pix);
}
