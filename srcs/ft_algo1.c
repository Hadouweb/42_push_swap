#include "pile.h"

void 	ft_qswap(int tab[], int a, int b)
{
    int 	tmp;

    tmp = tab[a];
    tab[a] = tab[b];
    tab[b] = tmp;
}

void	ft_quicksort(int tab[], int begin, int end)
{
    int 	left;
    int 	right;
    int		pivot;
    int		out;

    left = begin;
    right = end;
    pivot = tab[begin];
    out = 1;

    if(begin < end)
    {
	    while(out)
	    {
	        while(tab[right] > pivot)
	        	right--;
	        while(tab[left] < pivot)
	        	left++;

	        printf("_______ : %d %d\n", left, right);

	        if(left < right)
	        {
	            ft_qswap(tab, left, right);
	            printf("permute : %d %d\n", tab[left], tab[right]);
	        }
	        else 
	        	out = 0;
	    }
	    printf("\n>>>>>>> : out\n");
    	ft_quicksort(tab, begin, right);
    	ft_quicksort(tab, right + 1, end);
	}
}