/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 11:04:07 by nle-bret          #+#    #+#             */
/*   Updated: 2016/01/04 11:04:08 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist		*dlist_new(void)
{
	t_dlist	*list;

	list = (t_dlist*)malloc(sizeof(t_dlist));
	if (list)
	{
		list->len = 0;
		list->tail = NULL;
		list->head = NULL;
	}
	return (list);
}
