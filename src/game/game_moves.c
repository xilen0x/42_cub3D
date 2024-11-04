/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:24:23 by spereyra          #+#    #+#             */
/*   Updated: 2024/09/18 16:30:09 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_w(t_game *g)
{
	(void)g;
	// if (g->player.py > PX2 + 4)//68)  // min py will be 68 = 64 px is the top wall heigth + 4 is miniplayer height/2
	// g->player.py = g->player.py - 4;    // 4 is the Y step of miniplayer
		printf("W\n");
//		printf("Player py:\t%d\n\n", g->player.py);
}
//	set_rays(g);
	// set_image(g);
	// set_rays(g);
	// mlx_put_image_to_window(g->mlx, g->win, g->img3.img_ptr, 0 , 0);
	// mlx_put_image_to_window(g->mlx, g->win, g->img2.img_ptr, 0 , 0);
// }

void	move_s(t_game *g)
{
	// if (g->player.py < ((PX2 * g->map.mapH) - (PX2 + 4)))//512 - 68)    // 64 px is the bottom wall heigth + 4 is miniplayer height/2
	if (g->player.py < ((PX3 * g->map.mapH) - (PX3 + 4)))
	{	
		g->player.py = g->player.py + 4;    // 4 is the Y step of miniplayer
//		printf("Line length:\t%d\n", g->img.line_len);
//		printf("Player py:\t%d\n\n", g->player.py);
	}
//	set_rays(g);
	set_image(g);
	set_rays(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img3.img_ptr, 0 , 0);
	// mlx_put_image_to_window(g->mlx, g->win, g->img2.img_ptr, 0 , 0);
}

void	move_a(t_game *g)
{
	if (g->player.px > PX3 + 4)//68)  // 64 px is the left wall heigth + 4 is miniplayer height/2
	{	
		g->player.px = g->player.px - 4;    // 4 is the Y step of miniplayer
//		printf("Line length:\t%d\n", g->img.line_len);
//		printf("Player px:\t%d\n\n", g->player.px);
	}
//	set_rays(g);
	set_image(g);
	set_rays(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img3.img_ptr, 0 , 0);
	// mlx_put_image_to_window(g->mlx, g->win, g->img2.img_ptr, 0 , 0);
}

void	move_d(t_game *g)
{
	if (g->player.px < ((PX3 * g->map.mapW) - (PX3 + 4)))//512 - 68)    // 64 px is the rigth wall heigth + 4 is miniplayer height/2
	{
		g->player.px = g->player.px + 4;    // 4 is the Y step of miniplayer
//		printf("Line length:\t%d\n", g->img.line_len);
//		printf("Player px:\t%d\n\n", g->player.px);
	}
//	set_rays(g);
	set_image(g);
	set_rays(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img3.img_ptr, 0 , 0);
	// mlx_put_image_to_window(g->mlx, g->win, g->img2.img_ptr, 0 , 0);
}

void	move_l(t_game *g)
{
	g->player.pa -= 1;//10 //0.1;
	if (g->player.pa < 0)
		g->player.pa += 2 * PI;
//	set_rays(g);
	set_image(g);
	set_rays(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img3.img_ptr, 0 , 0);
	// mlx_put_image_to_window(g->mlx, g->win, g->img2.img_ptr, 0 , 0);
}

void	move_r(t_game *g)
{
	g->player.pa += 1;//10 //0.1;
	if (g->player.pa >= 2 * PI)
		g->player.pa -= 2 * PI;
//	set_rays(g);
	set_image(g);
	set_rays(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img3.img_ptr, 0 , 0);
	// mlx_put_image_to_window(g->mlx, g->win, g->img2.img_ptr, 0 , 0);
}
