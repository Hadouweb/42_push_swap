#include "pile.h"

int		main(void)
{
	t_pile	*a;
	t_pile 	*b;
	t_ab	*pile;

	a = NULL;
	b = NULL;
	pile = (t_ab*)malloc(sizeof(t_ab));
	pile->a = &a;
	pile->b = &b;

	ft_pile_push(pile->a, 1);
	ft_pile_push(pile->a, 2);
	ft_pile_push(pile->a, 3);
	ft_pile_print(*pile->a);

	ft_pile_push(pile->b, 10);
	ft_pile_push(pile->b, 20);
	ft_pile_push(pile->b, 30);
	ft_pile_print(*pile->b);

	ft_pile_rr(pile);
	ft_pile_print(*pile->a);
	ft_pile_print(*pile->b);

	ft_pile_rrr(pile);
	ft_pile_print(*pile->a);
	ft_pile_print(*pile->b);

	return (0);
}
