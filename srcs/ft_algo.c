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

#include "pile.h"

int		ft_sort(t_dlist *a)
{
	t_node	*n;

	n = a->head;
	while (n->next)
	{
		if (n->v->index > n->next->v->index)
			return (0);
		n = n->next;
	}
	return (1);
}

int		ft_swap(t_ab *pile, t_node *n, int way)
{
	int		ret;

	ret = 0;
	ft_print_pile(pile->a);
	ft_print_pile(pile->b);
	printf("\nn = %d\n", n->v->index);
	if (pile->a->head && pile->a->head->v->index - 1 == pile->a->head->next->v->index)
		ft_pile_sa(pile);
	else if (pile->a->tail->v->index - 1 == pile->a->head->v->index)
		ft_pile_rra(pile);
	else if (pile->a->head->v->index == pile->min && ++ret && !ft_sort(pile->a))
	{
		ft_pile_pb(pile);
		pile->min++;
	}
	else if (n->v->index != pile->a->head->v->index)
	{
		while (n->v->index != pile->a->head->v->index)
		{
			if (way)
				ft_pile_ra(pile);
			else
				ft_pile_rra(pile);
		}
	}
	ft_print_pile(pile->a);
	ft_print_pile(pile->b);
	printf("\n");
	if (ft_sort(pile->a))
		return (1);
	return (ret);
}

void	ft_algo(t_ab *pile)
{
	int		swap;
	int		way;
	t_node	*n;
	int		pos;

	swap = 1;
	n = pile->a->head;
	while (swap)
	{
		swap = 0;
		pos = 0;
		way = 1;
		n = pile->a->head;
		while (n && n->next && ((n->v->index != pile->min && ++pos) || (n->v->index + 1 == n->next->v->index)))
			n = n->next;
		if (!ft_sort(pile->a))
		{
			if (pos > pile->a->len / 2)
				way = 0;
			while (!swap)
				swap = ft_swap(pile, n, way);
		}
	}
	while (pile->b && pile->b->head)
		ft_pile_pa(pile);
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
