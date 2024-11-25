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

#include "cub3D.h"

int	exit_game(t_game *g)
{
	if (g->mlx)
		mlx_destroy_window(g->mlx, g->win);
	free(g->map.map); // free strdup
	mlx_destroy_image(g->mlx, g->img2.img_ptr);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	printf("GOOD BYE!\n");
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
	mlx_clear_window(g->mlx, g->win);
	mlx_put_image_to_window(g->mlx, g->win, g->img3.img_ptr, 0, 0);//g->img2.w , 0);
	//mlx_put_image_to_window(g->mlx, g->win, g->img2.img_ptr, 0, 0);
	display_minimap(g);
	return (0);
}

int ft_min(int a, int b)
{
    return (a < b) ? a : b;
}

int	is_wall(t_game *g, int x, int y)
{
	int	mapX;
	int	mapY;
	int	pos;

	mapX = x >> 6;//x / PX2;
	mapY = y >> 6;//y / PX2;
	pos = mapY * g->map.mapW + mapX;
	return (g->map.map[pos] == '1');
}

void    load_textures(t_game *g)///////////////////
{
    g->tex[0].img_ptr = mlx_xpm_file_to_image(g->mlx, "./textures/north.xpm", &g->tex[0].w, &g->tex[0].h);
    g->tex[0].addr = mlx_get_data_addr(g->tex[0].img_ptr, &g->tex[0].bpp, &g->tex[0].line_len, &g->tex[0].endian);

    g->tex[1].img_ptr = mlx_xpm_file_to_image(g->mlx, "./textures/south.xpm", &g->tex[1].w, &g->tex[1].h);
    g->tex[1].addr = mlx_get_data_addr(g->tex[1].img_ptr, &g->tex[1].bpp, &g->tex[1].line_len, &g->tex[1].endian);

    g->tex[2].img_ptr = mlx_xpm_file_to_image(g->mlx, "./textures/east.xpm", &g->tex[2].w, &g->tex[2].h);
    g->tex[2].addr = mlx_get_data_addr(g->tex[2].img_ptr, &g->tex[2].bpp, &g->tex[2].line_len, &g->tex[2].endian);

    g->tex[3].img_ptr = mlx_xpm_file_to_image(g->mlx, "./textures/west.xpm", &g->tex[3].w, &g->tex[3].h);
    g->tex[3].addr = mlx_get_data_addr(g->tex[3].img_ptr, &g->tex[3].bpp, &g->tex[3].line_len, &g->tex[3].endian);
}