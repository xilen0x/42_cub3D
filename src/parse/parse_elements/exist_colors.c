
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
	int		temp;

	// while (lmap)
	// {
		elements = split_space_tab_comma(lmap->content);
		// temp = count_f_c(elements);
		temp = ft_strlen(*elements);
		free_elements(elements);
		// lmap = lmap->next;
		if (temp == 3)
			return (0);
	// }
	return (1);
}
