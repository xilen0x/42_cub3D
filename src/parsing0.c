/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:45:23 by castorga          #+#    #+#             */
/*   Updated: 2023/11/27 13:45:26 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*Funcion que inicializa valores*/
void	set_values(t_game *g)
{
	g->collected = 0;
	g->walk_cnt = 0;
	g->h = 0;
	g->w = 0;
}

/*Funcion que verifica la extension .ber*/
int	file_is_ber(char *av, t_game *game)
{
	int	len;

	len = ft_strlen(av);
	if (ft_strncmp(&av[len - 4], ".ber", 4) == 0)
	{
		set_values(game);
		return (0);
	}
	else
	{
		write (2, "Error\n", 6);
		write (2, "The file does not have a .ber extension.\n", 41);
		exit(1);
	}
}

int	parsing_map(t_game *game)
{
	if (is_rectangular(game) != 0)
		ft_errors(3);
	if (is_surrounded_by_walls(game) != 0)
		ft_errors(3);
	if (is_initial_position(game) != 1)
		ft_errors(3);
	if (has_only_one_exit(game) != 1)
		ft_errors(3);
	if (valid_path_to_exit(game) == 0)
		ft_errors(4);
	if (valid_path_to_collectables(game) != 0)
		ft_errors(4);
	if (q_collectible(game) < 1)
		ft_errors(3);
	return (0);
}

