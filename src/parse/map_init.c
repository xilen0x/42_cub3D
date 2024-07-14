#include "cub3d.h"

/*Inicializacion de valores structura map*/
void	init_values(t_map *map)
{
	map->map_fd = -1;
	map->no = 0;
	map->so = 0;
	map->we = 0;
	map->ea = 0;
	map->f = 0;
	map->c = 0;
	map->w = 0;
	map->h = 0;
	map->matrix = NULL;
}
