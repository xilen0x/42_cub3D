/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:04:02 by castorga          #+#    #+#             */
/*   Updated: 2024/07/10 19:04:05 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

/* Funcion que reserva memoria y rellena con ' ' */
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

/*convert the env(list) to an array(char **)*/
// int	list_to_array(t_map *map)
// {
// 	int		len;
// 	// t_env	*current;

// 	len = 0;
// 	current = env;
// 	while (current)
// 	{
// 		len++;
// 		current = current->next;
// 	}
// 	exe->new_array = (char **)malloc(sizeof(char *) * (len + 1));
// 	if (exe->new_array == NULL)
// 		return (-1);
// 	current = env;
// 	allocate_memory(current, len, exe);
// 	exe->new_array[len] = NULL;
// 	return (0);
// }

/* Funcion que crea la matriz a partir de la lista*/
void	create_matrix(t_map *map, t_lmap *lmap)
{
	int		i;
	int		j;
	t_lmap	*tmp;

	i = 0;
	j = 0;
	tmp = lmap;
	map->matrix = p_malloc(sizeof(char *) * (map->h + 1));
	while (i < map->h)
	{
		map->matrix[i] = p_malloc(sizeof(char) * (map->w + 1));
		j = 0;
		while (j < map->w)
		{
			map->matrix[i][j] = tmp->content;
			tmp = tmp->next;
			j++;
		}
		map->matrix[i][j] = '\0';
		i++;
	}
}
