#include "pile.h"

void 	ft_qswap(t_node *a, t_node *b)
{
    int 	tmp;

    tmp = a->v;
    a->v = b->v;
    b->v = tmp;
}

void	ft_quicksort(t_dlist *a, int begin, int end, t_node *n_pivot)
{
	t_node	*n_left;
	t_node	*n_right;
    int		left;
    int		right;
    int		pivot;
    int		out;


    n_left = a->tail;
    n_right = a->head;
    left = begin;
    right = end;
    pivot = n_pivot->v;
    out = 1;

	printf("pivot %d\n", pivot);
    
    if(begin < end)
    {
	    while(out)
	    {
	    	n_left = a->tail;
	        while(n_left->prev && n_left->v > pivot)
	        {
	        	n_left = n_left->prev;
	        	right--;
	        }
	        n_right = a->head;
	        while(n_right->next && n_right->v < pivot)
	        {
	        	n_right = n_right->next;
	        	left++;
	        }
	        printf("lr %d %d\n", left, right);
	        if(left < right)
	        {
	            ft_qswap(n_left, n_right);
	        }
	        else 
	        	out = 0;
	        ft_pile_print(a);
	    }
    	ft_quicksort(a, begin, right, n_pivot);
    	ft_quicksort(a, right , end, n_pivot->next);
	}
}