#include "pile.h"

t_dlist		*ft_push_back(t_dlist *list, int nbr)
{
	t_node	*n;

	if (list)
	{
		n = (t_node*)malloc(sizeof(t_node));
		if (n)
		{
			n->v = nbr;
			n->next = NULL;
			if (!list->tail)
			{
				n->prev = NULL;
				list->tail = n;
				list->head = n;
			}
			else
			{
				list->tail->next = n;
				n->prev = list->tail;
				list->tail = n; 
			}
			list->len++;
		}
	}
	return (list);
}

t_dlist		*ft_push_front(t_dlist *list, int nbr)
{
	t_node	*n;

	if (list)
	{
		n = (t_node*)malloc(sizeof(t_node));
		if (n)
		{
			n->v = nbr;
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

t_node		*ft_create_node(int nbr)
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

t_dlist 	*ft_list_insert(t_dlist *list, int nbr, int pos)
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
		ft_push_back(list, nbr);
	else if (!tmp->prev)
		ft_push_front(list, nbr);
	else
	{
		if ((n = ft_create_node(nbr)))
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

t_dlist		*ft_list_new(void)
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