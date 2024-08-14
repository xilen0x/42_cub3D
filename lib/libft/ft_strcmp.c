#include "libft.h"

int	ft_strcmp(char c1, char c2)
{
	if (c1 > c2)
		return (1);
	else if (c1 == c2)
		return (0);
	else
		return (-1);
}
