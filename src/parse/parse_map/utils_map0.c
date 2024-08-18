#include "cub3d.h"

void	spaces_to_ones(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->h)
	{
		j = 0;
		while (j < map->w)
		{
			if (map->matrix[i][j] == ' ')
				map->matrix[i][j] = '1';
			j++;
		}
		i++;
	}
}
