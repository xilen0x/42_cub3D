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
	write (2, "Error\n", 6);
	write (2, msg, ft_strlen(msg));
	exit(1);
}
