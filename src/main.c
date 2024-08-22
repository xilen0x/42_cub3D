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
		// set_images(&game);
		mlx_hook(map.mlx_win, X_EVENT_KEY_PRESS, 1L << 0, &press_key, &map);
		mlx_hook(map.mlx_win, X_EVENT_KEY_EXIT, 0, &exit_game, &map);
		// ft_printf("\nAnchura mapa(w): %d\n", map.w);
		// ft_printf("Altura mapa(h): %d\n\n", map.h);
		// ft_printf("Valor x: %d\n", map.x);
		// ft_printf("Valor y: %d\n\n", map.y);
		// ft_printf("NO: %s\n", elem.no_path);
		// ft_printf("SO: %s\n", elem.so_path);
		// ft_printf("EA: %s\n", elem.ea_path);
		// ft_printf("WE: %s\n", elem.we_path);
		// ft_printf("F: %d\n", colors.f);
		// ft_printf("C: %d\n\n", colors.c);
		// ft_printf("Posición del jugador(y, x): %d,%d\n\n", map.y, map.x);
		// ft_printf("Orientación del jugador: %c\n\n", map.matrix[map.y][map.x]);
		mlx_loop(map.mlx);
	}
	else
		ft_errors("Invalid number of arguments\n");
	lst_clear(&lmap, &free);
	free_element_struct(&elem);
	free_matrix(map.matrix, map.h);
	return (0);
}
