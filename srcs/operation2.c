#include "pile.h"

void	ft_pile_ra(t_ab *pile)
{
	t_node	*first;

	first = (*pile->a)->head;
	if (first && (first->prev || first->next))
	{
		*pile->a = dlist_remove_head(*pile->a);
		first->prev = NULL;
		first->next = NULL;
		dlist_push_back(*pile->a, first->v);
		(*pile->a)->tail->index = (*pile->a)->tail->prev->index + 1;
		first = NULL;
		free(first);
	}
	ft_putstr("ra ");
}

void	ft_pile_rb(t_ab *pile)
{
	t_node	*first;

	first = (*pile->b)->head;
	if (first && (first->prev || first->next))
	{
		*pile->b = dlist_remove_head(*pile->b);
		first->prev = NULL;
		first->next = NULL;
		dlist_push_back(*pile->b, first->v);
		(*pile->b)->tail->index = (*pile->b)->tail->prev->index + 1;
		first = NULL;
		free(first);
	}
	ft_putstr("rb ");
}

void	ft_pile_rr(t_ab *pile)
{
	ft_pile_ra(pile);
	ft_pile_rb(pile);
	ft_putstr("rr ");
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
		(*pile->a)->head->index = (*pile->a)->head->next->index - 1;
		last = NULL;
		free(last);
	}
	ft_putstr("rra ");
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
		(*pile->b)->head->index = (*pile->b)->head->next->index - 1;
		last = NULL;
		free(last);
	}
	ft_putstr("rrb ");
}

void	ft_pile_rrr(t_ab *pile)
{
	ft_pile_rra(pile);
	ft_pile_rrb(pile);
	ft_putstr("rrr ");
}