#include "pile.h"

void 	ft_qswap_v2()
{

}

void 	ft_permute_v2(t_ab *pile, t_node *bot, t_node *top)
{
	int		i;

	i = 1;
	ft_pile_print(*pile->a);
	printf("\nPermutation %d %d\n", bot->v, top->v);
	while (top->v != (*pile->a)->head->v && i++)
		ft_pile_ra(pile);
	ft_pile_pb(pile);
	while (bot->v != (*pile->a)->head->v && i++)
		ft_pile_ra(pile);
	ft_pile_pb(pile);
	ft_pile_print(*pile->b);
	ft_pile_pa(pile);
	ft_pile_pa(pile);
	while (i--)
		ft_pile_rra(pile);
	ft_pile_print(*pile->a);
	printf("\n");
	ft_quicksort_v2(pile, (*pile->a)->tail, (*pile->a)->head);
	if (bot)
		;
}

void	ft_quicksort_v2(t_ab *pile, t_node *bot, t_node *top)
{
	int		pivot;

	pivot = top->v;

	while (top->v < pivot)
		top = top->next;

	while (bot->v > pivot)
		bot = bot->prev;

	//printf("bot %d top %d\n", bot->next->v, top->v);
	if (top->v != bot->v)
	{
	
			ft_permute_v2(pile, bot, top);
	}

}