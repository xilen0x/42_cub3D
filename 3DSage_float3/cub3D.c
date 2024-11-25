/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:23:59 by spereyra          #+#    #+#             */
/*   Updated: 2024/09/27 17:37:27 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*	The map =	11111111
				10100001
				10100001
				10100P01
				10000001
				10000101
				10000001
				11111111
*/

int	main(void)
{
	t_game	g;

	//g.map.map =	strdup("1111111110100001101000011010000110000P01100001011000000111111111");
	//g.map.map =	strdup("1111111110010001100100011001000110000P01100001011000000111111111");
	//g.map.map =	strdup("1111111111111111100000011000000110000P01100000011111111111111111");
	g.map.map =	strdup("1111111111111111110000111101001111000P11110100111111111111111111");
	//g.map.map =	strdup("11111111100000011000000110000001100000011000000110000001100000011000000110000001110000111100001111000P11110000111011110111111111");
	g.map.mapH = 8;	// map height in tiles
	g.map.mapW = 8;	// map width in tiles

	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, WX, WY, "cub3D");

	g.img2.h = g.map.mapH * 32;//TL;
	g.img2.w = g.map.mapW * 32;//TL;
	g.img2.img_ptr = mlx_new_image(g.mlx, g.img2.w, g.img2.h);
	g.img2.addr = mlx_get_data_addr(g.img2.img_ptr, &(g.img2.bpp), &(g.img2.line_len), &(g.img2.endian));

	g.img3.h = WY;
	g.img3.w = WX;// - g.img2.w;//1280 - 512 = 768
	g.img3.img_ptr = mlx_new_image(g.mlx, g.img3.w, g.img3.h);
	g.img3.addr = mlx_get_data_addr(g.img3.img_ptr, &(g.img3.bpp), &(g.img3.line_len), &(g.img3.endian));

	load_textures(&g);

	set_player(&g.map, &g.player);
	set_image(&g);
	set_rays(&g);
	mlx_clear_window(g.mlx, g.win);
	mlx_put_image_to_window(g.mlx, g.win, g.img3.img_ptr, 0, 0);//g.img2.w, 0);
	mlx_put_image_to_window(g.mlx, g.win, g.img2.img_ptr, 0, 0);
	mlx_hook(g.win, X_EVENT_KEY_PRESS, 1L << 0, &press_key, &g);
	mlx_hook(g.win, X_EVENT_KEY_EXIT, 1L << 0, &exit_game, &g);
	mlx_loop(g.mlx);
}
