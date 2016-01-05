#include "pile.h"

void	ft_test(t_ab *pile)
{
	ft_pile_print(*pile->a);
	ft_pile_print(*pile->b);
	ft_pile_pb(pile);
	ft_pile_pb(pile);
	ft_pile_pb(pile);
	ft_pile_print(*pile->a);
	ft_pile_print(*pile->b);
	ft_pile_ra(pile);
	ft_pile_print(*pile->a);
	ft_pile_print(*pile->b);
	ft_pile_pa(pile);
	ft_pile_print(*pile->a);
	ft_pile_print(*pile->b);
	ft_pile_ra(pile);
	ft_pile_ra(pile);
	ft_pile_print(*pile->a);
	ft_pile_print(*pile->b);
	ft_pile_rb(pile);
	ft_pile_print(*pile->a);
	ft_pile_print(*pile->b);
	ft_pile_pa(pile);
	ft_pile_print(*pile->a);
	ft_pile_print(*pile->b);
	ft_pile_ra(pile);
	ft_pile_ra(pile);
	ft_pile_print(*pile->a);
	ft_pile_print(*pile->b);
	ft_pile_pa(pile);
	ft_pile_print(*pile->a);
	ft_pile_print(*pile->b);
	ft_pile_ra(pile);
	ft_pile_ra(pile);
	ft_pile_print(*pile->a);
	ft_pile_print(*pile->b);
}

int		main(int argc, char **argv)
{
	t_dlist	*a;
	t_dlist	*b;
	t_ab	*pile;
	int		i;

	a = dlist_new();
	b = dlist_new();
	pile = (t_ab*)malloc(sizeof(t_ab));
	pile->a = &a;
	pile->b = &b;
	i = 1;

	if (argc > 1)
	{
		while (argv[i])
		{
			if (ft_is_number(argv[i]))
				dlist_push_back(*pile->a, ft_atoi(argv[i++]));
			else
				ft_print_error();
		}
	}
	ft_quicksort(a, 0, a->len, a->head);
	return (0);
}
