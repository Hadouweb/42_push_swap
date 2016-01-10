/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 23:21:41 by nle-bret          #+#    #+#             */
/*   Updated: 2016/01/09 23:21:44 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

t_ab	*ft_init_pile(void)
{
	t_ab	*pile;
	t_dlist	*a;
	t_dlist	*b;

	a = dlist_new();
	b = dlist_new();
	pile = (t_ab*)malloc(sizeof(t_ab));
	pile->a = a;
	pile->b = b;
	pile->size = 0;
	pile->print = 1;
	pile->min = 0;
	return (pile);
}

void	ft_resolve(t_ab *pile, int nb_elem)
{
	ft_cocktail_simple(pile->b);
	ft_prepare(pile);
	ft_reset(pile->b, pile->a);
	ft_clear_pile(pile->b);
	ft_print_pile(pile->a);
	if (nb_elem > 1)
		ft_algo(pile);
	ft_print_pile(pile->a);
	ft_putnbr(pile->size);
	//else if (nb_elem < 4)
	//	ft_best_algo(pile);
}

int		main(int argc, char **argv)
{
	t_ab	*pile;
	int		i;

	pile = ft_init_pile();
	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			if (ft_is_number(argv[i]) && ft_is_valid(argv[i]) &&
				ft_no_double(pile->a->head, ft_atoi(argv[i])))
			{
				dlist_push_back(pile->a, ft_atoi(argv[i]), 0);
				dlist_push_back(pile->b, ft_atoi(argv[i]), 0);
			}
			else
				ft_print_error();
			i++;
		}
		ft_resolve(pile, argc - 1);
	}
	return (0);
}
