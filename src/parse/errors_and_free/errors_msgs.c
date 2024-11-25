/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_msgs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:19:54 by castorga          #+#    #+#             */
/*   Updated: 2024/08/02 15:19:56 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Funcion que muestra mensajes de error*/
int	ft_errors(char *msg)
{
	// write (2, "Error\n", 6);
	// write (2, msg, ft_strlen(msg));
	ft_printf("Error\n%s", msg);
	exit(1);
}

void	print_map(t_game *g)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < g->map.mapH)
	{
		j = 0;
		while (j < g->map.mapW)
		{
			ft_printf("%c", g->map.map[k]);
			k++;
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
