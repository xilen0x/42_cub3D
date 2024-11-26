/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:53:16 by castorga          #+#    #+#             */
/*   Updated: 2024/11/22 14:53:18 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	img3_init(t_game *g)
{
	g->img3.w = WX;
	g->img3.h = WY;
	g->img3.img_ptr = mlx_new_image(g->mlx, WX, WY);
	if (!g->img3.img_ptr)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
		return (1);
	}
	g->img3.addr = mlx_get_data_addr(g->img3.img_ptr, &(g->img3.bpp), \
		&(g->img3.line_len), &(g->img3.endian));
	if (!g->img3.addr)
	{
		mlx_destroy_image(g->mlx, g->img3.img_ptr);
		mlx_destroy_display(g->mlx);
		free(g->mlx);
		return (1);
	}
	return (0);
}

void	game_init(t_game *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
		ft_errors("Error initializing mlx\n");
	g->win = mlx_new_window(g->mlx, WX, WY, "Cub3D");
	if (img3_init(g))
		return ;
}

void	set_mlx(t_game *g)
{
	mlx_put_image_to_window(g->mlx, g->win, g->img3.img_ptr, 0, 0);
	mlx_hook(g->win, X_EVENT_KEY_PRESS, 1L << 0, &press_key, g);
	mlx_hook(g->win, X_EVENT_KEY_EXIT, 1L << 0, &exit_game, g);
	mlx_loop(g->mlx);
}
