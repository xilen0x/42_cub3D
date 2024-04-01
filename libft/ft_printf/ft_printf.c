/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:22:25 by castorga          #+#    #+#             */
/*   Updated: 2023/06/19 10:22:28 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_options(char op, va_list *args, int *len, int *i)
{
	if (*len == -1)
		return ;
	if (op == 's')
		ft_string2(va_arg(*args, char *), len);
	else if (op == 'd' || op == 'i')
		ft_putnbr2(va_arg(*args, int), len);
	else if (op == 'u')
		ft_unsigned_int(va_arg(*args, unsigned int), len);
	else if (op == 'x' || op == 'X')
		ft_hexadecimal(va_arg(*args, unsigned int), len, op);
	else if (op == 'p')
		ft_pointer(va_arg(*args, unsigned long), len);
	else if (op == 'c')
		ft_putchar_len(va_arg(*args, int), len);
	else if (op == '%')
		ft_putchar_len('%', len);
	else
		(*i)--;
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i] && len != -1)
	{
		if (str[i] == '%')
		{
			i++;
			ft_printf_options(str[i], &args, &len, &i);
			i++;
		}
		else
		{
			ft_putchar_len(str[i], &len);
			i++;
		}
	}
	va_end(args);
	return (len);
}

/*
int	main(void)
{
	ft_printf("Cadena sin modificador     :    HolaMundo\n");
	   printf("Cadena sin modificador     :    HolaMundo\n");

	ft_printf("Caracter                   :    %c\n", 'A');
	   printf("Caracter                   :    %c\n", 'A');

	ft_printf("Cadena                     :    %s\n", "HolaMundo");
	   printf("Cadena                     :    %s\n", "HolaMundo");

	ft_printf("Entero en base10 (d)       :    %d\n", 42);
	   printf("Entero en base10 (d)       :    %d\n", 42);

	ft_printf("Entero en base10 (i)       :    %i\n", 052);//imprime 42
	   printf("Entero en base10 (i)       :    %i\n", 052);

	ft_printf("Simbolo porcentaje         :    %%\n");
	   printf("Simbolo porcentaje         :    %%\n");

	ft_printf("Entero en base10 sin signo :    %u\n", -42);
	   printf("Entero en base10 sin signo :    %u\n", -42);

	ft_printf("Hexadecimal(base 16) en min:    %x\n", 0xdeadbeef);
	   printf("Hexadecimal(base 16) en min:    %x\n", 0xdeadbeef);

	ft_printf("Hexadecimal(base 16) en may:    %X\n", 0xDEADBEEF);
	   printf("Hexadecimal(base 16) en may:    %X\n", 0xDEADBEEF);

	ft_printf("Pointer                    :    %p\n", (void *)0xDEADBEEF);
	   printf("Pointer                    :    %p\n", (void *)0xDEADBEEF);

	return (0);
}
*/