/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_push_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 11:04:12 by nle-bret          #+#    #+#             */
/*   Updated: 2016/01/04 11:04:14 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

t_dlist		*dlist_push_front(t_dlist *list, int nbr, int index)
{
	t_node	*n;

	if (list)
	{
		n = (t_node*)ft_memalloc(sizeof(t_node));
		if (n)
		{

			n->v = (t_value*)ft_memalloc(sizeof(t_value));
			n->v->nbr = nbr;
			n->v->index = index;
			n->prev = NULL;
			if (!list->head)
			{
				n->next = NULL;
				list->tail = n;
				list->head = n;
			}
			else
			{
				list->head->prev = n;
				n->next = list->head;
				list->head = n; 
			}
			list->len++;
		}
	}
	return (list);
}
