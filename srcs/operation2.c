#include "pile.h"

void	ft_pile_ra(t_ab *pile)
{
	t_node	*first;

	first = pile->a->head;
	if (first && (first->prev || first->next))
	{
		pile->a->head = first->next;
		pile->a->head->prev = NULL;

		first->next = NULL;
		first->prev = pile->a->tail;

		pile->a->tail->next = first;
		pile->a->tail = first;
	}
	pile->size++;
	if (pile->print)
		ft_putstr("ra ");
}

void	ft_pile_rra(t_ab *pile)
{
	t_node	*last;

	last = pile->a->tail;
	if (last && (last->prev || last->next))
	{
		pile->a->tail = last->prev;
		pile->a->tail->next = NULL;

		last->prev = NULL;
		last->next = pile->a->head;

		pile->a->head->prev = last;
		pile->a->head = last;
	}
	pile->size++;
	if (pile->print)
		ft_putstr("rra ");
}

void	ft_pile_rb(t_ab *pile)
{
	t_node	*first;

	first = pile->b->head;
	if (first && (first->prev || first->next))
	{
		pile->b->head = first->next;
		pile->b->head->prev = NULL;

		first->next = NULL;
		first->prev = pile->b->tail;

		pile->b->tail->next = first;
		pile->b->tail = first;
	}
	pile->size++;
	if (pile->print)
		ft_putstr("rb ");
}

void	ft_pile_rr(t_ab *pile)
{
	ft_pile_ra(pile);
	ft_pile_rb(pile);
	if (pile->print)
		ft_putstr("rr ");
}

void	ft_pile_rrb(t_ab *pile)
{
	t_node	*last;

	last = pile->b->tail;
	printf("%d\n", last->v->nbr);
	if (last && (last->prev || last->next))
	{
		pile->b->tail = last->prev;
		pile->b->tail->next = NULL;

		last->prev = NULL;
		last->next = pile->b->head;

		pile->b->head->prev = last;
		pile->b->head = last;
	}
	pile->size++;
	if (pile->print)
		ft_putstr("rrb ");
}

void	ft_pile_rrr(t_ab *pile)
{
	ft_pile_rra(pile);
	ft_pile_rrb(pile);
	pile->size++;
	if (pile->print)
		ft_putstr("rrr ");
}