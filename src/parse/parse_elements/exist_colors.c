
#include "cub3d.h"

// int	count_f_c(char **elements)
// {
// 	int		i;
// 	int		count;

// 	count = 0;
// 	i = 0;
// 	while (elements[i] && count < 2)
// 	{
// 		if (ft_strlen(elements[i]) == 1)
// 		{
// 			if (ft_strncmp(elements[i], "F", 1) == 0)
// 				count++;
// 			else if (ft_strncmp(elements[i], "C", 1) == 0)
// 				count++;
// 		}
// 		i++;
// 	}
// 	return (count);
// }


int	exist_colors(t_lmap *lmap)
{
	char	**elements;
	int		i;

	i = 0;
	elements = split_space_tab_comma(lmap->content);
	while (elements[i] && *elements[i] != '\n')
		i++;
	free_elements(elements);
	if (i == 3)
		return (0);
	return (1);
}
