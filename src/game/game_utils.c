/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:19:54 by spereyra          #+#    #+#             */
/*   Updated: 2024/10/11 12:13:18 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_game(t_game *g)
{
	if (g->mlx)
		mlx_destroy_window(g->mlx, g->win);
	free(g->map.map);
	mlx_destroy_image(g->mlx, g->img3.img_ptr);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	ft_printf("GOOD BYE!\n");
	exit(EXIT_SUCCESS);
}

int	press_key(int keycode, t_game *g)
{
	if (keycode == KEY_ESC)
		exit_game(g);
	else if (keycode == KEY_W)
		move_w(g);
	else if (keycode == KEY_A)
		move_a(g);
	else if (keycode == KEY_S)
		move_s(g);
	else if (keycode == KEY_D)
		move_d(g);
	else if (keycode == KEY_LEFT)
		move_l(g);
	else if (keycode == KEY_RIGHT)
		move_r(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img3.img_ptr, 0, 0);
	return (0);
}

void	inc_ray_h(t_ray *ray)
{
	ray->hx += ray->x_step;
	ray->hy += ray->y_step;
}

void	inc_ray_v(t_ray *ray)
{
	ray->vx += ray->x_step;
	ray->vy += ray->y_step;
}

void	load_textures(t_game *g, t_elem *elem)
{
	g->tex[0].img_ptr = mlx_xpm_file_to_image(g->mlx, elem->no_path, \
	&g->tex[0].w, &g->tex[0].h);
	g->tex[0].addr = mlx_get_data_addr(g->tex[0].img_ptr, &g->tex[0].bpp, \
	&g->tex[0].line_len, &g->tex[0].endian);
	g->tex[1].img_ptr = mlx_xpm_file_to_image(g->mlx, elem->so_path, \
	&g->tex[1].w, &g->tex[1].h);
	g->tex[1].addr = mlx_get_data_addr(g->tex[1].img_ptr, &g->tex[1].bpp, \
	&g->tex[1].line_len, &g->tex[1].endian);
	g->tex[2].img_ptr = mlx_xpm_file_to_image(g->mlx, elem->ea_path, \
	&g->tex[2].w, &g->tex[2].h);
	g->tex[2].addr = mlx_get_data_addr(g->tex[2].img_ptr, &g->tex[2].bpp, \
	&g->tex[2].line_len, &g->tex[2].endian);
	g->tex[3].img_ptr = mlx_xpm_file_to_image(g->mlx, elem->we_path, \
	&g->tex[3].w, &g->tex[3].h);
	g->tex[3].addr = mlx_get_data_addr(g->tex[3].img_ptr, &g->tex[3].bpp, \
	&g->tex[3].line_len, &g->tex[3].endian);
}
