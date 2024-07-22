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


/*Funcion que abre el mapa en modo lectura y almacena su fd en map_fd*/
int	open_map(char *av, t_map *map)
{
	map->map_fd = open(av, O_RDONLY);
	if (map->map_fd == -1)
		ft_errors(2);
	return (0);
}
/*funcion que imprime ancho y largo del fichero*/
void print_width_height(t_map *map)
{
	printf("Width: %d\n", map->w);
	printf("Height: %d\n", map->h);
}
/* F. que verifica si un carácter está presente en un conjunto de caracteres.*/
static int	ft_isset2(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim2(char const *s1, char const *set, char const *tabs)
{
	unsigned int	len;
	unsigned int	i;
	const char		*start;
	const char		*end;
	char			*reserved;

	i = 0;
	start = s1;
	end = s1 + ft_strlen(s1) - 1;
	while (ft_isset2(*start, set) || ft_isset2(*start, tabs))
		start++;
	while (start <= end && ft_isset2(*end, set))
		end--;
	len = end - start + 1;
	reserved = (char *)malloc((len + 1) * sizeof(char));
	if (reserved == NULL)
		return (NULL);
	while (i < len)
	{
		reserved[i] = start[i];
		i++;
	}
	reserved[len] = '\0';
	return (reserved);
}
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

// int	open_matrix(t_map *map)
// {
// 	map->map_fd = open(map->matrix, O_RDONLY);
// 	if (map->map_fd == -1)
// 		ft_errors(2);
// 	return (0);
// }
