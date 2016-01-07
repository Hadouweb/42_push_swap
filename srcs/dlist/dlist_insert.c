/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 11:03:59 by nle-bret          #+#    #+#             */
/*   Updated: 2016/01/04 11:04:02 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

t_dlist 	*dist_insert(t_dlist *list, int nbr, int pos)
{
	t_node	*tmp;
	t_node	*n;
	int 	i;

	i = 1;
	tmp = list->head;
	n = NULL;
	while (tmp && i++ < pos)
		tmp = tmp->next;
	if (!tmp)
		dlist_push_back(list, nbr);
	else if (!tmp->prev)
		dlist_push_front(list, nbr);
	else
	{
		if ((n = dlist_create_node(nbr)))
		{
			tmp->prev->next = n;
			n->prev = tmp->prev;
			n->next = tmp;
			tmp->prev = n;
			list->len++;
		}
	}
	return (list);
}
