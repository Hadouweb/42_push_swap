#include "pile.h"

void 	ft_qswap(t_ab *pile, t_node *top, t_node *bot)
{
    int 	tmp;

    tmp = 0;
    while (top->v != (*pile->a)->head->v)
    	ft_pile_ra(pile);

	ft_pile_print(*pile->a);
	ft_pile_print(*pile->b);

    ft_pile_pb(pile);

	ft_pile_print(*pile->a);
	ft_pile_print(*pile->b);

    while (bot->v != (*pile->a)->tail->v)
    	ft_pile_ra(pile);

	ft_pile_print(*pile->a);
	ft_pile_print(*pile->b);

    ft_pile_pa(pile);

	ft_pile_print(*pile->a);
	ft_pile_print(*pile->b);

    ft_pile_ra(pile);

	ft_pile_print(*pile->a);
	ft_pile_print(*pile->b);

	ft_pile_print(*pile->a);
	ft_pile_print(*pile->b);
	

}

void	ft_quicksort(t_ab *pile, t_node *top, t_node *bot, t_node *pivot)
{
	t_node	*n_top;
	t_node	*n_bot;
    int		out;

    n_top = top;
    n_bot = bot;
    out = 1;

printf("\npivot %d\n", pivot->v);	
printf("\n1\nn_top %d(%d)\nn_bot %d(%d)\ntop %d(%d)\nbot %d(%d) \n", n_top->v, n_top->index, n_bot->v, n_bot->index, top->v, top->index, bot->v, bot->index);

    if(n_top->index < n_bot->index)
    {
	    while(out)
	    {
	        while(n_bot->prev && n_bot->v > pivot->v)
	        	n_bot = n_bot->prev;
	        while(n_top->next && n_top->v < pivot->v)
	        	n_top = n_top->next;

	        if(n_top->index < n_bot->index)
	        {
	        	printf("PERMUTATION : %d %d", n_top->v, n_bot->v);
	            ft_qswap(pile, n_top, n_bot);
	            //exit(1);
	        }
	        else 
	        	out = 0;
	
printf("\n2\nn_top %d(%d)\nn_bot %d(%d)\ntop %d(%d)\nbot %d(%d) \n", n_top->v, n_top->index, n_bot->v, n_bot->index, top->v, top->index, bot->v, bot->index);

	        //printf("recur %d %d\n", (*pile->a)->head->v, n_bot->v);
	        //exit(1);
	    }
    	//ft_quicksort(pile, bot, n_top, (*pile->a)->tail);
    	if (pivot->prev)
    	{

printf("\n3\nn_top %d(%d)\nn_bot %d(%d)\ntop %d(%d)\nbot %d(%d) \n", n_top->v, n_top->index, n_bot->v, n_bot->index, top->v, top->index, bot->v, bot->index);
    		
    		ft_quicksort(pile, (*pile->a)->head, (*pile->a)->tail, (*pile->a)->tail->prev);
    	}
	}
}