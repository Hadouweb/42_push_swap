#include "pile.h"

void	ft_print_pile(t_dlist	*lst)
{
	t_node	*n;

	n = lst->tail;
	ft_putchar('\n');
	while (n)
	{
		ft_putnbr(n->v->nbr);
		ft_putchar('[');
		ft_putnbr(n->v->index);
		ft_putchar(']');
		ft_putchar(' ');
		n = n->prev;
	}
}