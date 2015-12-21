#include "pile.h"

void	ft_print_error()
{
	ft_putstr("Error\n");
	exit(1);
}

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}


int		ft_is_number(char *data)
{
	int		i;

	i = 0;
	while (data[i])
	{
		if (!ft_isdigit(data[i]))
			return (0);
		i++;
	}
	return (1);
}