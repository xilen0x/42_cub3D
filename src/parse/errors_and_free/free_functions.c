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

void	free_matrix(char **matrix, size_t rows)
{
	size_t	i;

	i = 0;
	while (i < rows)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	free_element_struct(t_elem *elem)
{
	if (elem->no_path)
		free(elem->no_path);
	if (elem->so_path)
		free(elem->so_path);
	if (elem->we_path)
		free(elem->we_path);
	if (elem->ea_path)
		free(elem->ea_path);
}

void	free_elements(char **double_pointer)
{
	int	i;

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
