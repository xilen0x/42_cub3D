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

void	draw_wall(t_game *g, int col, int top_pix, int bot_pix)
{
	float			wall_x;
	t_texture		t;

	if (g->ray.path == g->ray.vpath)
		wall_x = g->ray.vy;
	else
		wall_x = g->ray.hx;
	t.texture_x = (unsigned int)(wall_x) % 64;
	t.screen_y = top_pix;
	while (t.screen_y < (unsigned int)bot_pix)
	{
		t.d = t.screen_y * 256 - g->img3.h * 128 + g->ray.wall_h * 128;
		t.texture_y = ((t.d * g->tex[g->ray.path].h) / g->ray.wall_h) / 256;
		t.texture_y = t.texture_y % 64;
		t.tex_pos = (t.texture_y * g->tex[g->ray.path].line_len) + \
		(t.texture_x * (g->tex[g->ray.path].bpp / 8));
		t.color = *(unsigned int *)(g->tex[g->ray.path].addr + t.tex_pos);
		set_pixel_to_image(&g->img3, col, t.screen_y, t.color);
		t.screen_y++;
	}
}

void	render_wall(t_game *g, int col)
{
	float	cos_angle;
	int		bot_pix;
	int		top_pix;

	cos_angle = g->player.pa - g->ray.ra;
	if (cos_angle < 0)
		cos_angle = cos_angle + 2 * PI;
	else if (cos_angle > 2 * PI)
		cos_angle = cos_angle - 2 * PI;
	g->ray.len = (g->ray.len * cosf(cos_angle));
	g->ray.wall_h = (TL / g->ray.len) * \
		((g->img3.w / 2) / tanf(g->player.fov / 2));
	bot_pix = (g->img3.h / 2) + (g->ray.wall_h / 2);
	top_pix = (g->img3.h / 2) - (g->ray.wall_h / 2);
	if (bot_pix > g->img3.h)
		bot_pix = g->img3.h;
	if (top_pix < 0)
		top_pix = 0;
	draw_wall(g, col, top_pix, bot_pix);
}
