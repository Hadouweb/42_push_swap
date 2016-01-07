#include "pile.h"

void 	ft_qswap_v2(t_ab *pile, t_node *bot, t_node *top)
{
	int		i;

	i = 0;
		//printf("\n\x1b[32m[Swap %d %d]\x1b[0m\n", bot->v, top->v);
	if (top->v == (*pile->a)->head->v && bot->v == (*pile->a)->head->next->v)
		ft_pile_sa(pile);
	else
	{
		while (top->v != (*pile->a)->head->v && ++i)
			ft_pile_ra(pile);
		ft_pile_sa(pile);
		while(i--)
			ft_pile_rra(pile);
	}
}

void 	ft_permute_v2(t_ab *pile, t_node *bot, t_node *top)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	//printf("\n\x1b[36m[Permutation %d %d]\x1b[0m\n", bot->v, top->v);

	while (top->v != (*pile->a)->head->v && ++i)
		ft_pile_ra(pile);
	ft_pile_pb(pile);

	while (bot->v != (*pile->a)->head->v && ++j)
		ft_pile_ra(pile);
	ft_pile_pb(pile);

	ft_pile_sb(pile);

	ft_pile_pa(pile);
	while (j--)
		ft_pile_rra(pile);
	ft_pile_pa(pile);
	while (i--)
		ft_pile_rra(pile);

	if (bot)
		;
}

void	ft_best_swap(t_ab *pile, t_node *bot, t_node *top)
{

		//ft_pile_print(*pile->a);
		//printf("\n1 ___ bot %d top %d\n", bot->v, top->v);

		if (bot->v == (*pile->a)->tail->v && 
			top->v == (*pile->a)->head->v)
		{
			//printf("_______\n");
			ft_pile_rra(pile);
		}
		else if (bot->v == top->next->v)
			ft_qswap_v2(pile, bot, top);
		else
			ft_permute_v2(pile, bot, top);

		//ft_pile_print(*pile->a);
		//printf("\n");
}

void 	ft_algo(t_ab *pile, t_node *bot, t_node *top)
{
	/*while ((*pile->a)->len && (*pile->a)->tail->v < (*pile->a)->tail->prev->v)
	{
		ft_pile_pb(pile);
		if (!(*pile->a)->tail->prev)
		{
			ft_pile_pb(pile);
		}
	}
	while ((*pile->b)->len)
	{
		if ((*pile->b)->len > 1)
			ft_pile_rrb(pile);
		ft_pile_pa(pile);
	}
	ft_pile_print(*pile->a);
	ft_pile_print(*pile->b);
	//exit(1);
	*/
	if (bot)
		;
	if (top)
		;
	ft_quicksort_v2(pile, (*pile->a)->tail, (*pile->a)->head);
}

void	ft_quicksort_v2(t_ab *pile, t_node *bot, t_node *top)
{
	//printf("\n1 ___ bot %d top %d\n", bot->v, top->v);

	while (bot && bot->v > top->v)
		bot = bot->prev;
	while (top && top->v < top->v)
		top = top->prev;

	if (bot->v < top->v)
	{
		ft_best_swap(pile, bot, top);
		ft_quicksort_v2(pile, (*pile->a)->tail, (*pile->a)->head);
	}
	if (bot->v == top->v && bot->v != (*pile->a)->tail->v)
		ft_quicksort_v2(pile, (*pile->a)->tail, top->next);

}