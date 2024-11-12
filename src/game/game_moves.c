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
	// printf("DESPUES colors.f: %u\n", colors.f_color_hex);
	// printf("DESPUES colors.c: %u\n", colors.c_color_hex);
	if (g->player.py > PX2 + 4)//68)  // min py will be 68 = 64 px is the top wall heigth + 4 is miniplayer height/2
		g->player.py = g->player.py - 4;    // 4 is the Y step of miniplayer
}

void	move_s(t_game *g)
{
	if (g->player.py < ((PX2 * g->map.mapH) - (PX2 + 4)))//512 - 68)    // 64 px is the bottom wall heigth + 4 is miniplayer height/2
		g->player.py = g->player.py + 4;    // 4 is the Y step of miniplayer
	// set_image(g, colors);
	// set_rays(g);

}

void	move_a(t_game *g)
{
	if (g->player.px > PX2 + 4)//68)  // 64 px is the left wall heigth + 4 is miniplayer height/2
		g->player.px = g->player.px - 4;    // 4 is the Y step of miniplayer
	// set_image(g, colors);
	// set_rays(g);
}

void	move_d(t_game *g)
{
	if (g->player.px < ((PX2 * g->map.mapW) - (PX2 + 4)))//512 - 68)    // 64 px is the rigth wall heigth + 4 is miniplayer height/2
		g->player.px = g->player.px + 4;    // 4 is the Y step of miniplayer
	// set_image(g, colors);
	// set_rays(g);

}

void	move_l(t_game *g)
{
	g->player.pa -= 1;//10 //0.1;
	if (g->player.pa < 0)
		g->player.pa += 2 * PI;
	// set_image(g, colors);;
	// set_rays(g);

}

void	move_r(t_game *g)
{
	g->player.pa += 1;//10 //0.1;
	if (g->player.pa >= 2 * PI)
		g->player.pa -= 2 * PI;
	// set_image(g, colors);;
	// set_rays(g);

}
