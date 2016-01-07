#include "pile.h"

void	ft_test(t_ab *pile)
{

	ft_pile_ra(pile);
	ft_pile_pb(pile);
	
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
			if (ft_is_number(argv[i]) && 
				ft_is_valid(argv[i]) && 
				ft_no_double((*pile->a)->head, ft_atoi(argv[i])))
				dlist_push_back(*pile->a, ft_atoi(argv[i]));
			else
				ft_print_error();
			i++;
		}		
		//ft_pile_print(a);
		//printf("\n");
		//if (argc > 2)
		//	ft_algo(pile, (*pile->a)->tail, (*pile->a)->head);
		ft_pile_print(a);
	}

	ft_test(pile);
	//ft_pile_print(a);
	sleep(20);
	return (0);
}
