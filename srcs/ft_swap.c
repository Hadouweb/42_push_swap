#include "pile.h"

int		ft_swap(t_ab *pile, t_node *n, int min, int way)
{
	int		ret;

	ret = 0;

	//printf("||||||||||||||||||||||||\n");

	//ft_pile_print(pile->a);
	//ft_pile_print(pile->b);
	//printf("\x1b[32m[SWAP n %d]\x1b[0m", n->v->nbr);
	if (pile->a->head->v->index == min && ++ret)
	{
		//printf(" HERE _ 0 ");
		ft_pile_pb(pile);
	}
	else if (n->prev && n->v->index + 1 == n->prev->v->index && 
		n->prev->v->index == pile->a->head->v->index)
	{
		//printf(" HERE _ 1 ");
		ft_pile_sa(pile);
	}
	else if (n->v->index != pile->a->head->v->index)
	{
		while (n->v->index != pile->a->head->v->index)
		{
			if (way)
				ft_pile_ra(pile);
			else
				ft_pile_rra(pile);
		}
	}
	if (ft_sort(pile->a))
		return (1);

	//ft_pile_print(pile->a);
	//ft_pile_print(pile->b);
	return (ret);
}

void 	ft_swap_right(t_ab *pile, t_node *bot, t_node *top)
{
	int		i;

	i = 0;
	//ft_pile_printpile->a;
	//printf("\n\x1b[32m[Swap RIGHT %d %d]\x1b[0m", bot->v, top->v);
	if (top->v == pile->a->head->v && bot->v == pile->a->head->next->v)
		ft_pile_sa(pile);
	else
	{
		while (top->v != pile->a->head->v && ++i)
			ft_pile_ra(pile);
		ft_pile_sa(pile);
		while(i--)
			ft_pile_rra(pile);
	}
	//ft_pile_printpile->a;
}

void 	ft_swap_left(t_ab *pile, t_node *bot, t_node *top)
{
	int		i;

	i = 0;
	//ft_pile_printpile->a;
	//printf("\n\x1b[36m[Swap LEFT %d %d]\x1b[0m", bot->v, top->v);
	if (top->v == pile->a->head->v && bot->v == pile->a->head->next->v)
		ft_pile_sa(pile);
	else
	{
		while (top->v != pile->a->head->v && ++i)
			ft_pile_rra(pile);
		ft_pile_sa(pile);
		while(i--)
			ft_pile_ra(pile);
	}
	//ft_pile_printpile->a;
}

void 	ft_permute_v2(t_ab *pile, t_node *bot, t_node *top)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	printf("\x1b[36m[Permutation %d %d]\x1b[0m", bot->v->nbr, top->v->nbr);

	while (top->v != pile->a->head->v && ++i)
		ft_pile_ra(pile);
	ft_pile_pb(pile);

	while (bot->v != pile->a->head->v && ++j)
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
