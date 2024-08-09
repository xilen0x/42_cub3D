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

int	ft_errors2(int n)
{
	if (n == 4)
	{
		write (2, "Error\n", 6);
		write (2, "Invalid route in map!\n", 22);
		exit(1);
	}
	else if (n == 5)
	{
		write (2, "Error\n", 6);
		write (2, "It was not possible to initialize the program!\n", 47);
		exit(1);
	}
	else if (n == 6)
	{
		write (2, "Error\n", 6);
		write (2, "The file does not have a .cub extension.\n", 41);
		exit(1);
	}
	else if (n == 7)
	{
		write (2, "Error\n", 6);
		write (2, "The texture path is not valid.\n", 31);
		exit(1);
	}
	return (1);
}

/*Funcion que muestra mensajes de error*/
int	ft_errors(int n)
{
	if (n == 1)
	{
		write (2, "Error\n", 6);
		write (2, "Use: ./cub3d <map.cub>\n", 23);
		
		exit(1);
	}
	else if (n == 2)
	{
		write (2, "Error\n", 6);
		write (2, "It was not possible to open the file\n", 37);
		exit(1);
	}
	else if (n == 3)
	{
		write (2, "Error\n", 6);
		write (2, "Invalid map file!\n", 18);
		return (1);
	}
	return (1);
}
