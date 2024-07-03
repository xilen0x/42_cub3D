/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:28:40 by castorga          #+#    #+#             */
/*   Updated: 2023/07/07 10:28:44 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// ----------- in case of character -----------
void	ft_putchar_len(char c, int *len)
{
	if (*len != -1)
	{
		if (write(1, &c, 1) < 0)
		{
			(*len) = -1;
			return ;
		}
		(*len)++;
	}
}

// ----------- in case of string -----------
void	ft_string2(char *args, int *len)
{
	unsigned int	i;

	i = 0;
	if (args == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			*len = -1;
		else
			(*len) += 6;
		return ;
	}
	while (args[i] != '\0' && *len != -1)
	{
		ft_putchar_len(args[i], len);
		i++;
	}
}
