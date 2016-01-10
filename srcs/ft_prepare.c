#include "pile.h"

void	ft_reset(t_dlist *b, t_dlist *a)
{
	t_node	*node_a;
	t_node	*node_b;

	node_b = b->head;
	while (node_b)
	{
		node_a = a->head;
		while (node_a)
		{
			if (node_b->v->nbr == node_a->v->nbr)
				node_a->v->index = node_b->v->index;
			node_a = node_a->next;
		}
		node_b = node_b->next;
	}
}

void	ft_clear_pile(t_dlist *b)
{
	t_node	*b_node;
	t_node	*tmp;
	t_value	*value;

	b_node = b->head;
	while (b_node)
	{
		tmp = b_node;
		value = tmp->v;
		b_node = b_node->next;
		free(tmp);
		tmp = NULL;
		free(value);
		value = NULL;
	}
	b->head = NULL;
	b->tail = NULL;
}

void	ft_prepare(t_ab *pile)
{
	t_node	*n;
	int		i;

	i = 0;
	n = pile->b->head;
	while (n)
	{
		n->v->index = i;
		i++;
		n = n->next;
	}
}