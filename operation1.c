#include "pile.h"

void	ft_pile_sa(t_ab *pile)
{
	int		tmp;
	t_pile	**p;

	tmp = 0;
	p = pile->a;
	if (*p && (*p)->prev)
	{
		tmp = (*p)->value;
		(*p)->value = (*p)->prev->value;
		(*p)->prev->value = tmp;
	}
}

void	ft_pile_sb(t_ab *pile)
{
	int		tmp;
	t_pile	**p;

	tmp = 0;
	p = pile->b;
	if (*p && (*p)->prev)
	{
		tmp = (*p)->value;
		(*p)->value = (*p)->prev->value;
		(*p)->prev->value = tmp;
	}
}

void	ft_pile_ss(t_ab *pile)
{
	ft_pile_sa(pile);
	ft_pile_sb(pile);
}

void	ft_pile_pa(t_ab *pile)
{
	int		v;

	v = 0;
	if (pile->b)
	{
		v = (*pile->b)->value;
		ft_pile_push(pile->a, v);
		ft_pile_pop(pile->b);
	}
}

void	ft_pile_pb(t_ab *pile)
{
	int		v;

	v = 0;
	if (pile->a)
	{
		v = (*pile->a)->value;
		ft_pile_push(pile->b, v);
		ft_pile_pop(pile->a);
	}
}
