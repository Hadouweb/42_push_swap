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

#include "pile.h"

t_dlist		*dlist_remove_tail(t_dlist *list)
{
	t_node	*tmp;

	tmp = list->tail;
	list->tail = list->tail->prev;
	if (list->tail)
		list->tail->next = NULL;
	else
	{
		list->tail = NULL;
		list->head = NULL;
	}
	tmp->prev = NULL;
	tmp->next = NULL;
	//tmp = NULL;
			//free(tmp);
	if (list->len)
		list->len--;
	return (list);
}
