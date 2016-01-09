#include "pile.h"

int     ft_sort(t_dlist *a)
{
    t_node  *n;

    n = a->head;
    while (n->next)
    {
        if (n->v->index > n->next->v->index)
            return (0);
        n = n->next;
    }
    return (1);
}

void    ft_cocktailv2(t_ab *pile)
{
    int     swap;
    int     way;
    int     min;
    int     pos1;
    int     pos2;
    t_node  *n;
    t_node  *nbr1;
    t_node  *nbr2;

    swap = 1;
    way = 1;
    n = pile->a->head;
    min = 0;
    pos1 = 0;
    pos2 = 0;
    nbr1 = n;
    nbr2 = n;

    while (swap)
    {
        swap = 0;
        pos1 = 0;
        pos2 = 0;
        way = 1;

        n = pile->a->head;
        while (n && n->next && n->v->index != (min + 1) && ++pos2)
            n = n->next;
        nbr2 = n;

        n = pile->a->head;
        while (n && n->next && n->v->index != min && ++pos1)
            n = n->next;
        nbr1 = n;

        if (pos2 < pos1 + 2)
        {
            n = nbr2;
            min--;
        }
        printf("%d[%d] %d[%d]\n", nbr1->v->nbr, pos1, nbr2->v->nbr, pos2);
        if (!ft_sort(pile->a))
        {
            if (pos1 > pile->a->len / 2)
                way = 0;
            while (!swap)
                swap = ft_swap(pile, n, min, way);
            min++;
           // printf("MIN %d SWAP %d\n", min, swap);
        }
    }
    while (pile->b && pile->b->head)
        ft_pile_pa(pile);
    //printf("MIN = %d[%d]", n->v->nbr, n->v->index);
}