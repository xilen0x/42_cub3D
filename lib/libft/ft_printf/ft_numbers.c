/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:29:04 by castorga          #+#    #+#             */
/*   Updated: 2023/07/07 10:29:09 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// ----------- in case of number %d or %i-----------

void	ft_putnbr2(int nb, int *len)
{
	if (nb == -2147483648)
	{
		if (write(1, "-2147483648", 11) < 0)
		{
			(*len) = -1;
			return ;
		}
		*len += 11;
		return ;
	}
	if (nb < 0)
	{
		ft_putchar_len('-', len);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr2(nb / 10, len);
	}
	ft_putchar_len(nb % 10 + '0', len);
}

// ----------- in case of unsigned int-----------
void	ft_unsigned_int(unsigned int nb, int *len)
{
	if (nb >= 10)
	{
		ft_putnbr2(nb / 10, len);
	}
	ft_putchar_len(nb % 10 + '0', len);
}

// ----------- in case of hexadecimal -----------
void	ft_hexadecimal(unsigned int exa, int *len, char op)
{
	char	str[20];
	char	*base;
	int		i;

	i = 0;
	if (op == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (exa == 0)
	{
		ft_putchar_len('0', len);
		return ;
	}
	while (exa != 0)
	{
		str[i] = base [exa % 16];
		exa = exa / 16;
		i++;
	}
	while (i--)
		ft_putchar_len(str[i], len);
}

// ----------- in case of pointer -----------
void	ft_pointer(unsigned long pointer, int *len)
{
	char	str[20];
	char	*base;
	int		i;

	base = "0123456789abcdef";
	i = 0;
	if (write(1, "0x", 2) < 0)
	{
		(*len) = -1;
		return ;
	}
	(*len) += 2;
	if (pointer == 0)
	{
		ft_putchar_len('0', len);
		return ;
	}
	while (pointer != 0)
	{
		str[i] = base[pointer % 16];
		pointer = pointer / 16;
		i++;
	}
	while (i--)
		ft_putchar_len(str[i], len);
}
