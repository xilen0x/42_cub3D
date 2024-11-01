/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_windows.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:45:05 by castorga          #+#    #+#             */
/*   Updated: 2024/08/22 12:45:08 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "cub3d.h"

int	exit_game(t_map *map)
{
	write (1, "####################\n", 21);
	write (1, "     End Game!\n", 15);
	write (1, "####################\n", 21);
	mlx_destroy_window(map->mlx, map->mlx_win);
	free(map->mlx);
	exit(0);
}

/*Funcion que inicializa minilibx*/
void	init_game(t_map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
		ft_errors("Error initializing mlx\n");
	map->mlx_win = mlx_new_window(map->mlx, WIDTH, HEIGHT, "cub3D");
}
