#include "pile.h"

void	ft_pile_sa(t_ab *pile)
{
	int		tmp;
	t_node	*n;

	tmp = 0;
	n = (*pile->a)->head;
	if (n && n->next)
	{
		tmp = n->v;
		n->v = n->next->v;
		n->next->v = tmp;
	}
}

void	ft_pile_sb(t_ab *pile)
{
	int		tmp;
	t_node	*n;

	tmp = 0;
	n = (*pile->b)->head;
	if (n && n->next)
	{
		tmp = n->v;
		n->v = n->next->v;
		n->next->v = tmp;
	}
}

void	ft_pile_ss(t_ab *pile)
{
	ft_pile_sa(pile);
	ft_pile_sb(pile);
}

void	ft_pile_pa(t_ab *pile)
{
	if ((*pile->b)->head)
	{
		ft_push_front(*pile->a, (*pile->b)->head->v);
		*pile->b = ft_remove_head(*pile->b);
	}
}

void	ft_pile_pb(t_ab *pile)
{
	if ((*pile->a)->head)
	{
		ft_push_front(*pile->b, (*pile->a)->head->v);
		*pile->a = ft_remove_head(*pile->a);
	}
}
