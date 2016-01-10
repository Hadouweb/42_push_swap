/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_ab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 23:19:19 by nle-bret          #+#    #+#             */
/*   Updated: 2016/01/09 23:19:20 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

void	ft_pile_ss(t_ab *pile)
{
	ft_pile_sa(pile);
	ft_pile_sb(pile);
	if (pile->print)
		ft_putstr("ss ");
}

void	ft_pile_rr(t_ab *pile)
{
	ft_pile_ra(pile);
	ft_pile_rb(pile);
	if (pile->print)
		ft_putstr("rr ");
}

void	ft_pile_rrr(t_ab *pile)
{
	ft_pile_rra(pile);
	ft_pile_rrb(pile);
	pile->size++;
	if (pile->print)
		ft_putstr("rrr ");
}
