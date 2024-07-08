
#include "cub3d.h"

// int	ft_errors2(int n)
// {
// 	if (n == 4)
// 	{
// 		write (2, "Error\n", 6);
// 		write (2, "Invalid route in map!\n", 22);
// 		exit(1);
// 	}
// 	else if (n == 5)
// 	{
// 		write (2, "Error\n", 6);
// 		write (2, "It was not possible to initialize the program!\n", 47);
// 		exit(1);
// 	}
// 	else
// 	{
// 		write (2, "Error\n", 6);
// 		exit(1);
// 	}
// 	return (1);
// }

/*Funcion que muestra mensajes de error*/
int	ft_errors(int n)
{
	if (n == 1)
	{
		write (2, "Error\n", 6);
		write (2, "Use: ./cub3d <map.cub>\n", 23);
		exit(1);
	}
	else if (n == 2)
	{
		write (2, "Error\n", 6);
		write (2, "It was not possible to open the file\n", 37);
		exit(1);
	}
	else if (n == 3)
	{
		write (2, "Error\n", 6);
		write (2, "Invalid map file!\n", 18);
		exit(1);
	}
	// else
	// 	ft_errors2(n);
	return (1);
}


/*funcion que imprime la matriz*/
// void	print_matrix(t_game *game)
// {
// 	int	i;

// 	i = 0;
// 	while (i < game->h)
// 	{
// 		ft_printf("%s", game->matrix[i]);
// 		i++;
// 	}
// }

// /*funcion que libera la mem. de los mapas*/
// void	free_map(t_game *game)
// {
// 	int	i;

// 	i = 0;
// 	while (i < game->h)
// 	{
// 		free(game->matrix[i]);
// 		game->matrix[i] = NULL;
// 		i++;
// 	}
// 	free(game->matrix);
// }
