/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_moves2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:25:46 by castorga          #+#    #+#             */
/*   Updated: 2024/11/22 14:25:51 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_l(t_game *g)
{
	g->player.pa -= 0.1;
	if (g->player.pa < 0)
		g->player.pa += 2 * PI;
	set_image(g);
	set_rays(g);
}

void	move_r(t_game *g)
{
	g->player.pa += 0.1;
	if (g->player.pa >= 2 * PI)
		g->player.pa -= 2 * PI;
	set_image(g);
	set_rays(g);
}
