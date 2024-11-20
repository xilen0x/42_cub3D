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
	mlx_put_image_to_window(g->mlx, g->win, g->img3.img_ptr, 0, 0);//g->img2.w , 0);
	// mlx_put_image_to_window(g->mlx, g->win, g->img2.img_ptr, 0, 0);
	return (0);
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