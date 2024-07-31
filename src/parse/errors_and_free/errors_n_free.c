/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:45:10 by castorga          #+#    #+#             */
/*   Updated: 2024/07/09 15:45:12 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

int	ft_errors2(int n)
{
	if (n == 4)
	{
		write (2, "Error\n", 6);
		write (2, "Invalid route in map!\n", 22);
		exit(1);
	}
	else if (n == 5)
	{
		write (2, "Error\n", 6);
		write (2, "It was not possible to initialize the program!\n", 47);
		exit(1);
	}
	else
	{
		write (2, "Error\n", 6);
		exit(1);
	}
	return (1);
}

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
		return (1);
	}
	// else
	// 	ft_errors2(n);
	return (1);
}

// void free_matrix(char **matrix)
// {
//     int i;

// 	i = 0;

// 	if (!matrix)
// 		return ;
//     if (matrix)
// 	{
//         while (matrix[i])
// 		{
//             free(matrix[i]);
//             i++;
//         }
//         free(matrix);
//         matrix = NULL;
//     }
// }
void free_matrix(char **matrix, size_t rows)
{
    size_t i;

    for (i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
}

void	free_element_struct(t_elem *elem)
{
	free(elem->no);
	free(elem->so);
	free(elem->we);
	free(elem->ea);
    free(elem->no_path);
    free(elem->so_path);
    free(elem->we_path);
    free(elem->ea_path);
}
void	free_elements(char **double_pointer)
{
	int i;
	
	 i = 0;
	if (!double_pointer)
		return ;
	while (double_pointer[i])
	{
		free(double_pointer[i]);
		i++;
	}
	free(double_pointer);
}

/*funcion que imprime la matriz*/
void	print_matrix(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->h)
	{
		ft_printf("%s\n", map->matrix[i]);
		i++;
	}
}

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
