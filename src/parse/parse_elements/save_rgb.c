#include "cub3d.h"

void	save_rgb_values(t_lmap *lmap, t_colors *colors)
{
	t_lmap	*temp;
	int		i;
	int		j;
	int		count;

	temp = lmap;
	while (temp)
	{
		if (temp->cont[0] == 'F' || temp->cont[0] == 'C')
		{
			i = 0;
			j = 0;
			count = 0;
			while (temp->cont[i])
			{
				if (temp->cont[i] == ' ' || temp->cont[i] == '\t')
					i++;
				if (temp->cont[i] >= '0' && temp->cont[i] <= '9')
				{
					if (temp->cont[0] == 'F')
					{
						colors->f = 1;
						if (count == 0)
							colors->f_color[j++] = ft_atoi(&temp->cont[i]);
						else if (count == 1)
							colors->f_color[j++] = ft_atoi(&temp->cont[i]);
						else if (count == 2)
							colors->f_color[j++] = ft_atoi(&temp->cont[i]);
					}
					else if (temp->cont[0] == 'C')
					{
						colors->c = 2;
						if (count == 0)
							colors->c_color[j++] = ft_atoi(&temp->cont[i]);
						else if (count == 1)
							colors->c_color[j++] = ft_atoi(&temp->cont[i]);
						else if (count == 2)
							colors->c_color[j++] = ft_atoi(&temp->cont[i]);
					}
					while (temp->cont[i] >= '0' && temp->cont[i] <= '9')
						i++;
					count++;
				}
				if (count == 3)
				{
					return ;
				}
				i++;
			}
		}
		temp = temp->next;
	}
}
