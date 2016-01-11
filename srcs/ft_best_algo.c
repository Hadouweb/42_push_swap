/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 22:49:24 by nle-bret          #+#    #+#             */
/*   Updated: 2016/01/09 22:49:26 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_sa(t_ab *pile, t_node *n, int way)
{
	int		rev;

	rev = 0;
	if (way)
	{
		while (n->v->index != pile->a->head->v->index && ++rev)
			ft_pile_ra(pile);
		ft_pile_sa(pile);
		if (!ft_sort(pile->a))
		{
			while (rev--)
				ft_pile_rra(pile);
		}
	}
	else
	{
		while (n->v->index != pile->a->head->v->index && ++rev)
			ft_pile_rra(pile);
		ft_pile_sa(pile);
		if (!ft_sort(pile->a))
		{
			while (rev--)
				ft_pile_ra(pile);
		}
	}
}

void	ft_check_sa(t_ab *pile)
{
	t_node	*n;
	int		pos;
	int		swap;
	int		way;

	pos = 0;
	swap = 1;
	n = pile->a->head;
	while (swap)
	{
		swap = 0;
		way = 1;
		while (n && n->next && n->next->v->index - 1 == n->v->index && ++pos)
			n = n->next;
		if (n && n->next)
			n = n->next;
		if (n->next && n->next->v->index + 1 == n->v->index)
		{
			if (pos > pile->a->len / 2)
				way = 0;
			ft_swap_sa(pile, n, way);
			swap = 1;
		}
	}
}

void	ft_swap_simple(t_node *bot, t_node *top)
{
	t_value		*tmp;

	tmp = bot->v;
	bot->v = top->v;
	top->v = tmp;
}

void	ft_cocktail_simple(t_dlist *b)
{
	int		swap;
	t_node	*n;
	int		tmp;

	swap = 1;
	n = b->head;
	while (swap)
	{
		swap = 0;
		n = b->head;
		while (n && n->next)
		{
			tmp = 0;
			if (n->v->nbr > n->next->v->nbr)
			{
				ft_swap_simple(n->next, n);
				swap = 1;
			}
			n = n->next;
		}
	}
}
