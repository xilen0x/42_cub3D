/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:19:16 by castorga          #+#    #+#             */
/*   Updated: 2024/11/26 10:19:22 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	floor_to_image(t_img *img, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < (img->h / 2))
	{
		x = 0;
		while (x < img->w)
		{
			set_pixel_to_image(img, x, y, color);
			x++;
		}
		y++;
	}
}

void	ceiling_to_image(t_img *img, int color)
{
	int	x;
	int	y;

	y = img->h / 2;
	while (y < img->h)
	{
		x = 0;
		while (x < img->w)
		{
			set_pixel_to_image(img, x, y, color);
			x++;
		}
		y++;
	}
}
