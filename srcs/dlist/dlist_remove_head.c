/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_remove_head.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 11:04:18 by nle-bret          #+#    #+#             */
/*   Updated: 2016/01/04 11:04:19 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

t_dlist		*dlist_remove_head(t_dlist *list)
{
	t_node	*tmp;

	tmp = list->head;
	list->head = list->head->next;
	if (list->head)
		list->head->prev = NULL;
	else
	{
		list->tail = NULL;
		list->head = NULL;
	}
	tmp->prev = NULL;
	tmp->next = NULL;
	//free(tmp);
	//free(tmp);
	if (list->len)
		list->len--;
	return (list);
}
