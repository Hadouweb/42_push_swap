/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 11:03:42 by nle-bret          #+#    #+#             */
/*   Updated: 2016/01/04 11:03:46 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node		*dlist_create_node(t_value *value)
{
	t_node	*n;

	n = (t_node*)malloc(sizeof(t_node));
	if (n)
	{
		n->v = value;
		n->prev = NULL;
		n->next = NULL;
	}
	return (n);
}
