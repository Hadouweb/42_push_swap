#include "pile.h"

void	ft_pile_ra(t_ab *pile)
{
	t_node	*first;

	first = (*pile->a)->head;
	if (first)
	{
		*pile->a = dlist_remove_head(*pile->a);
		first->prev = NULL;
		first->next = NULL;
		dlist_push_back(*pile->a, first->v);
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
		*pile->b = dlist_remove_head(*pile->b);
		first->prev = NULL;
		first->next = NULL;
		dlist_push_back(*pile->b, first->v);
		first = NULL;
		free(first);
	}
}

void	ft_pile_rr(t_ab *pile)
{
	ft_pile_ra(pile);
	ft_pile_rb(pile);
}

void	ft_pile_rra(t_ab *pile)
{
	t_node	*last;

	last = (*pile->a)->tail;
	if (last)
	{
		*pile->a = dlist_remove_tail(*pile->a);
		last->prev = NULL;
		last->next = NULL;
		dlist_push_front(*pile->a, last->v);
		last = NULL;
		free(last);
	}
}

void	ft_pile_rrb(t_ab *pile)
{
	t_node	*last;

	last = (*pile->b)->tail;
	if (last)
	{
		*pile->b = dlist_remove_tail(*pile->b);
		last->prev = NULL;
		last->next = NULL;
		dlist_push_front(*pile->b, last->v);
		last = NULL;
		free(last);
	}
}

void	ft_pile_rrr(t_ab *pile)
{
	ft_pile_rra(pile);
	ft_pile_rrb(pile);
}