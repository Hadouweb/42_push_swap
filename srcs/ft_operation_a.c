/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 23:19:05 by nle-bret          #+#    #+#             */
/*   Updated: 2016/01/09 23:19:07 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

void	ft_pile_sa(t_ab *pile)
{
	t_value	*tmp;
	t_node	*n;

	tmp = 0;
	n = pile->a->head;
	if (n && n->next)
	{
		tmp = n->v;
		n->v = n->next->v;
		n->next->v = tmp;
	}
	pile->size++;
	if (pile->print)
		ft_putstr("sa ");
}

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

void	ft_pile_pa(t_ab *pile)
{
	if (pile->b->head)
	{
		dlist_push_front(pile->a, pile->b->head->v->nbr,
			pile->b->head->v->index);
		pile->b = dlist_remove_head(pile->b);
	}
	pile->size++;
	if (pile->print)
		ft_putstr("pa ");
}
