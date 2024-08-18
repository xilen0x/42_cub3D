#include "cub3d.h"

int	exist_colors(t_lmap *lmap)
{
	char	**elements;
	int		i;

	i = 0;
	elements = split_space_tab_comma(lmap->cont);
	while (elements[i] && *elements[i] != '\n')
		i++;
	free_elements(elements);
	if (i == 3)
		return (0);
	return (1);
}
