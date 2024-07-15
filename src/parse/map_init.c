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
	map->no_path = NULL;
    map->so_path = NULL;
    map->we_path = NULL;
    map->ea_path = NULL;
	map->w = 0;
	map->h = 0;
	map->matrix = NULL;
}