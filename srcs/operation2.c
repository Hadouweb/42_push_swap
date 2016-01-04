#include "pile.h"

void	ft_pile_ra(t_ab *pile)
{
	t_node	*first;

	first = (*pile->a)->head;
	if (first)
	{
		ft_remove_head(*pile->a);
		first->prev = NULL;
		first->next = NULL;
		ft_push_back(*pile->a, first->v);
		first = NULL;
		free(first);
	}
}

void	ft_pile_rb(t_ab *pile)
{
	t_node	*first;

	first = (*pile->b)->head;
	if (first)
	{
		ft_remove_head(*pile->b);
		first->prev = NULL;
		first->next = NULL;
		ft_push_back(*pile->b, first->v);
		first = NULL;
		free(first);
	}
}

void	ft_pile_rr(t_ab *pile)
{
	ft_pile_ra(pile);
	ft_pile_rb(pile);
}
/*
void	ft_pile_rra(t_ab *pile)
{
	t_pile	*tmp;
	t_pile	*tmp2;
	t_pile	*last;
	int		i;

	tmp2 = *pile->a;
	i = 0;
	while (tmp2->prev)
	{
		tmp2 = tmp2->prev;
		i++;
	}
	while (i--)
	{
		tmp = *pile->a;
		while (tmp->prev->prev)
			tmp = tmp->prev;
		last = tmp->prev;
		tmp->prev = NULL;
		last->prev = *pile->a;
		*pile->a = last;
	}
}

void	ft_pile_rrb(t_ab *pile)
{
	t_pile	*tmp;
	t_pile	*tmp2;
	t_pile	*last;
	int		i;

	tmp2 = *pile->b;
	i = 0;
	while (tmp2->prev)
	{
		tmp2 = tmp2->prev;
		i++;
	}
	while (i--)
	{
		tmp = *pile->b;
		while (tmp->prev->prev)
			tmp = tmp->prev;
		last = tmp->prev;
		tmp->prev = NULL;
		last->prev = *pile->b;
		*pile->b = last;
	}
}

void	ft_pile_rrr(t_ab *pile)
{
	ft_pile_rra(pile);
	ft_pile_rrb(pile);
}*/