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

#include "libft.h"

t_node		*dlist_create_node(int nbr)
{
	t_node	*n;

	n = (t_node*)malloc(sizeof(t_node));
	if (n)
	{
		n->v = nbr;
		n->prev = NULL;
		n->next = NULL;
	}
	return (n);
}
