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
	//ft_putstr("sa ");
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
	//ft_putstr("sb ");
}

void	ft_pile_ss(t_ab *pile)
{
	ft_pile_sa(pile);
	ft_pile_sb(pile);
	ft_putstr("ss ");
}

void	ft_pile_pa(t_ab *pile)
{
	if ((*pile->b)->head)
	{
		dlist_push_front(*pile->a, (*pile->b)->head->v);
		*pile->b = dlist_remove_head(*pile->b);
	}
	//ft_putstr("pa ");
}

void	ft_pile_pb(t_ab *pile)
{
	if ((*pile->a)->head)
	{
		dlist_push_front(*pile->b, (*pile->a)->head->v);
		*pile->a = dlist_remove_head(*pile->a);
	}
	//ft_putstr("pb ");
}
