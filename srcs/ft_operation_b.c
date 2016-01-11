/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 23:19:15 by nle-bret          #+#    #+#             */
/*   Updated: 2016/01/09 23:19:16 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pile_sb(t_ab *pile)
{
	t_value	*tmp;
	t_node	*n;

	tmp = 0;
	n = pile->b->head;
	if (n && n->next)
	{
		tmp = n->v;
		n->v = n->next->v;
		n->next->v = tmp;
	}
	pile->size++;
	pile->seq = ft_strjoin_free(pile->seq, "sb ");
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
	pile->seq = ft_strjoin_free(pile->seq, "rb ");
}

void	ft_pile_rrb(t_ab *pile)
{
	t_node	*last;

	last = pile->b->tail;
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
	pile->seq = ft_strjoin_free(pile->seq, "rrb ");
}

void	ft_pile_pb(t_ab *pile)
{
	if (pile->a->head)
	{
		dlist_push_front(pile->b, pile->a->head->v->nbr,
			pile->a->head->v->index);
		pile->a = dlist_remove_head(pile->a);
	}
	pile->size++;
	pile->seq = ft_strjoin_free(pile->seq, "pb ");
}
