// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   utils_2.c                                          :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/07/09 15:45:18 by castorga          #+#    #+#             */
// /*   Updated: 2024/07/09 15:45:20 by castorga         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "cub3d.h"
// z
// /* Funcion que reserva memoria y rellena con ' ' */
// void spaced_malloc(t_map *map, size_t count, size_t size)
// {
//     map->matrix = malloc(size * count);
//     if (!map->matrix)
// 	{
//         perror("malloc");
//         exit(1);
//     }
//     ft_memset(map->matrix, ' ', size * count);
// }


// int	exit_game(t_game *g)
// {
// 	write (1, "####################\n", 21);
// 	write (1, "     End Game!\n", 15);
// 	write (1, "####################\n", 21);
// 	mlx_destroy_window(g->mlx, g->mlx_win);
// 	free(g->mlx);
// 	exit(0);
// }

// int	press_key(int keycode, t_game *game)
// {
// 	(void)keycode;
// 	(void)game;
// 	printf("test\n");
// 	// if (keycode == KEY_ESC)
// 	// 	exit_game(game);
// 	// else if (keycode == KEY_W || keycode == KEY_UP)
// 	// 	move_up(game);
// 	// else if (keycode == KEY_A || keycode == KEY_LEFT)
// 	// 	move_left(game);
// 	// else if (keycode == KEY_S || keycode == KEY_DOWN)
// 	// 	move_down(game);
// 	// else if (keycode == KEY_D || keycode == KEY_RIGHT)
// 	// 	move_right(game);
// 	return (0);
// }

/*Funcion que abre el mapa en modo lectura y almacena su fd en map_fd*/
int	open_map(char *av, t_map *map)
{
	map->map_fd = open(av, O_RDONLY);
	if (map->map_fd == -1)
		ft_errors(2);
	return (0);
}
// int	open_matrix(t_map *map)
// {
// 	map->map_fd = open(map->matrix, O_RDONLY);
// 	if (map->map_fd == -1)
// 		ft_errors(2);
// 	return (0);
// }

/*funcion que imprime ancho y largo del fichero*/
void print_width_height(t_map *map)
{
	printf("Width: %d\n", map->w);
	printf("Height: %d\n", map->h);
}