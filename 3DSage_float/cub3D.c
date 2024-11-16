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

	//set_sine(g.si);
	//set_cosine(g.co);
	//set_tan(g.ta);

	//g.map.map =	strdup("1111111110000001100000011000000110000P01100000011000000111111111");
	//g.map.map =	strdup("1111111111111111100000011000000110000P01100000011111111111111111");
	g.map.map =	strdup("1111111111111111110000111101001111001P11110000111111111111111111");
	g.map.mapH = 8;	// map height in tiles
	g.map.mapW = 8;	// map width in tiles

	g.mlx = mlx_init();
	g.h = 512;//g.map.mapH * PX3;// game/window height = 8 tiles * 64 px = 512 px;
	g.w = 1280;//1024;//g.map.mapW * PX3;// game/window width = 8 tiles * 64 px = 512 px;
	g.win = mlx_new_window(g.mlx, g.w, g.h, "cub3D");

	g.img2.h = g.map.mapH * PX2;//8 * 64 = 512;
	g.img2.w = g.map.mapW * PX2;//8 * 64 = 512;
	g.img2.img_ptr = mlx_new_image(g.mlx, g.img2.w, g.img2.h);
	g.img2.addr = mlx_get_data_addr(g.img2.img_ptr, &(g.img2.bpp), &(g.img2.line_len), &(g.img2.endian));

	g.img3.h = 512;//g.map.mapH * PX3;//768;//1536;
	g.img3.w = 768;//g.map.mapH * PX3;//1280;//2048;
	g.img3.img_ptr = mlx_new_image(g.mlx, g.img3.w, g.img3.h);
	g.img3.addr = mlx_get_data_addr(g.img3.img_ptr, &(g.img3.bpp), &(g.img3.line_len), &(g.img3.endian));

	set_player(&g.map, &g.player);
	set_image(&g);
	set_rays(&g);
	mlx_put_image_to_window(g.mlx, g.win, g.img3.img_ptr, 512 , 0);	
	mlx_put_image_to_window(g.mlx, g.win, g.img2.img_ptr, 0 , 0);	
	mlx_hook(g.win, X_EVENT_KEY_PRESS, 1L << 0, &press_key, &g);
	mlx_hook(g.win, X_EVENT_KEY_EXIT, 1L << 0, &exit_game, &g);
	mlx_loop(g.mlx);
}
