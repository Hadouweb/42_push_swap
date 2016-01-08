#include "pile.h"

void    ft_cocktailv2(t_ab *pile)
{
    int     swap;
    int     ex;
    t_node  *n;

    swap = 1;
    ex = 1;
    n = pile->a->head;

    while (swap)
    {
        swap = 0;

        n = pile->a->head;
        while (n && n->next)
        {
            swap = ft_swap(pile, n);
            if (swap)
                n = pile->a->head;
            else
            {
            	n = n->next;
            }
            ex++;
            if (ex > 20)
            {
            	//printf("%d\n", ex);
                exit(1);
            }

        }  
    }
}


void    ft_cocktail(t_ab *pile)
{
    int     swap;
    t_node  *n;
    int     size;
    int     mid;
    int     tmp;

    swap = 1;
    n = pile->a->head;
    size = pile->a->len;
    mid = size / 2;

    while (swap)
    {
        swap = 0;
        //n = pile->a->tail->prev->prev;

        n = pile->a->head;
        while (n && n->next)
        {
            tmp = 0;
            if (n->v > n->next->v)
            {
                //printf("____1 %d > %d\n", size, mid);
                //if (size > mid)
                  //  ft_swap_right(pile, n->next, n);
                //else
                  //  ft_swap_left(pile, n->next, n);
                swap = 1;
            }
            else
            {
                if (!n->next && !swap)
                {
                    while (pile->b->head)
                        ft_pile_pa(pile);
                    ft_pile_pa(pile);
                }
            }
            size--;
            n = n->next;
        } 
       /* size = 0;
        n = pile->a->tail;
        while (n && n->prev)
        {
            if (n->v < n->prev->v)
            {
                //printf("____2 %d < %d\n", size, mid);
                if (size < mid)
                    ft_swap_left(pile, n, n->prev);
                else
                    ft_swap_right(pile, n, n->prev);

                swap = 1;
            }
            size++;
            n = n->prev;
        }*/ 
    }
}