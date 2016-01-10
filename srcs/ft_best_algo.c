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

void	ft_init_ptr(t_ab *pile, int *tab)
{
	void	(*op[8])(t_ab *pile);
	int 	i;

	op[1] = ft_pile_sa;
	op[2] = ft_pile_ra;
	op[3] = ft_pile_rra;
	i = 0;
	while (tab[i])
	{
		op[tab[i]](pile);
		i++;
	}
}

int		ft_permute(int *tab, int index, int size)
{
	int 	i;

	i = 0;

	if (index <= size)
	{
		while (i < size)
		{
			printf("%d ", tab[i]);
			i++;
		}
		printf("\n");
	}
	else
	{
		i = 0;
		while (tab[i])
		{
			i++;
		}
		ft_permute(tab, index + 1, size);
	}

	return (1);
}

void	ft_best_algo(t_ab *pile)
{
	int 	tab[3];
	int 	i;
	int 	sort;

	i = 0;
	sort = 0;
	tab[0] = 10;
	tab[1] = 20;
	tab[2] = 30;
	ft_permute(tab, 0, 3);
	if (pile)
		;
}
