/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spereyra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:56:44 by spereyra          #+#    #+#             */
/*   Updated: 2024/09/23 16:09:15 by spereyra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_sine(float *sine_arr)
{
	float	angle;
	int		i;

	angle = 0.0f;
	i = 0;
	while (i < 628)
	{
		angle = i / 100.0f;
		sine_arr[i] = sinf(angle);
		i++;
	}
}

void	set_cosine(float *cos_arr)
{
	float	angle;
	int		i;

	angle = 0.0f;
	i = 0;
	while (i < 628)
	{
		angle = i / 100.0f;
		cos_arr[i] = cosf(angle);
		i++;
	}
}

void	set_tan(float *tan_arr)
{
	float	angle;
	int		i;

	angle = 0.0f;
	i = 0;
	while (i < 628)
	{
		angle = i / 100.0f;
		tan_arr[i] = tanf(angle);
		i++;
	}
}