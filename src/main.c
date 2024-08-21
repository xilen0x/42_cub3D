/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:31:15 by castorga          #+#    #+#             */
/*   Updated: 2024/07/17 11:31:18 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "window.h"

int	main(int ac, char *av[])
{
	t_elem		elem;
	t_colors	colors;
	t_map		map;
	t_lmap		*lmap;

	lmap = NULL;
	if (ac == 2)
	{
		elem.av = av;
		init_values(&elem, &colors, &map, av);
		parsing(&elem, &colors, &map, &lmap);
		init_game(&map);
		//set_images(&game);
		mlx_hook(map.mlx_win, X_EVENT_KEY_PRESS, 1L << 0, &press_key, &map);
		mlx_hook(map.mlx_win, X_EVENT_KEY_EXIT, 0, &exit_game, &map);
		mlx_loop(map.mlx);
	}
	else
		ft_errors("Invalid number of arguments\n");
	lst_clear(&lmap, &free);
	free_element_struct(&elem);
	free_matrix(map.matrix, map.h);
	return (0);
}
