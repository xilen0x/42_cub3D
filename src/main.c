/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:50:22 by castorga          #+#    #+#             */
/*   Updated: 2024/11/26 10:50:24 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_elem		elem;
	t_map_parse	map_parse;
	t_lmap		*lmap;
	t_game		g;

	lmap = NULL;
	if (argc == 2)
	{
		elem.av = argv;
		init_values(&elem, &g.cols, &map_parse, elem.av);
		parsing(&elem, &g.cols, &map_parse, &lmap);
		load_map(&g, &map_parse);
		game_init(&g);
		load_textures(&g, &elem);
		set_player(&g.map, &g.player);
		set_image(&g);
		set_rays(&g);
		set_mlx(&g);
	}
	else
		ft_errors("Invalid number of arguments\n");
	lst_clear(&lmap, &free);
	free_element_struct(&elem);
	free_matrix(map_parse.matrix, map_parse.h);
	return (0);
}
