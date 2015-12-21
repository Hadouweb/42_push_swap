#include "pile.h"

void	ft_pile_push(t_pile **p, int nbr)
{
	t_pile	*new;

	new = (t_pile *)malloc(sizeof(t_pile));
	if (new)
	{
		new->value = nbr;
		new->prev = *p;
		*p = new;
			
	}
}

void	ft_pile_pop(t_pile **p)
{
	t_pile	*tmp;

	if (*p)
	{
		tmp = (*p)->prev;
		free(*p);
		*p = NULL;
		*p = tmp;
	}
}

void	ft_pile_clean(t_pile **p)
{
	while (*p)
	{
		ft_pile_pop(p);
		*p = (*p)->prev;
	}
}

void	ft_pile_print(t_pile *p)
{
	while (p)
	{
		printf("%d ", p->value);
		p = p->prev;
	}
	printf("\n___________________________\n");
}
