#include "pile.h"

int		main(int argc, char **argv)
{
	t_pile	*a;
	t_pile 	*b;
	t_ab	*pile;
	int		i;

	a = NULL;
	b = NULL;
	pile = (t_ab*)malloc(sizeof(t_ab));
	pile->a = &a;
	pile->b = &b;
	i = 1;

	if (argc > 1)
	{
		while (argv[i])
		{
			if (ft_is_number(argv[i]))
				ft_pile_push(pile->a, ft_atoi(argv[i++]));
			else
				ft_print_error();
		}
		ft_pile_print(*pile->a);
	}

	return (0);
}
