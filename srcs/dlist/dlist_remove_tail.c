/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_remove_tail.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 11:04:24 by nle-bret          #+#    #+#             */
/*   Updated: 2016/01/04 11:04:25 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist		*dlist_remove_tail(t_dlist *list)
{
	t_node	*last;

	last = list->tail;
	list->tail = list->tail->prev;
	if (list->tail)
		list->tail->next = NULL;
	else
	{
		list->tail = NULL;
		list->head = NULL;
	}
	last->prev = NULL;
	last->next = NULL;
	free(last->v);
	last->v = NULL;
	free(last);
	last = NULL;
	if (list->len)
		list->len--;
	return (list);
}
