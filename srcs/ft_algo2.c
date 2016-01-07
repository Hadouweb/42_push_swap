#include "pile.h"

void 	ft_qswap_v2()
{

}

void 	ft_permute_v2(t_ab *pile, t_node *bot, t_node *top)
{
	int		i;

	i = 0;
	ft_pile_print(*pile->a);
	printf("\nPermutation %d %d\n", bot->v, top->v);
	while (top->v != (*pile->a)->head->v && ++i)
		ft_pile_ra(pile);
	ft_pile_pb(pile);
	while (bot->v != (*pile->a)->head->v && ++i)
		ft_pile_ra(pile);
	ft_pile_pb(pile);
	//ft_pile_sb(pile);
	//ft_pile_print(*pile->b);
	while (i-- -1)
		ft_pile_rra(pile);
	ft_pile_pa(pile);
	ft_pile_pa(pile);
	ft_pile_print(*pile->a);
	printf("\n");
	ft_quicksort_v2(pile, (*pile->a)->tail, top);
	if (bot)
		;
}

void	ft_quicksort_v2(t_ab *pile, t_node *bot, t_node *top)
{
	int		pivot;

	pivot = top->v;

	printf("\nPivot %d\n", pivot);


	printf("bot %d top %d\n", bot->v, top->v);
	if (bot->v < top->v)
	{
		//top = (*pile->a)->head;
		while (top->v < pivot)
			top = top->next;

		//bot = (*pile->a)->tail;
		while (bot->v > pivot)
			bot = bot->prev;
		//if (bot->prev->v == top->v)
		//	printf("AAAAA");
		//else	
		ft_permute_v2(pile, (*pile->a)->tail, top);	
	}
	else
		ft_permute_v2(pile, top, (*pile->a)->head->next);
}