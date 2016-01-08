#include "pile.h"

void	ft_test(t_ab *pile)
{

	ft_pile_ra(pile);
}

void	ft_swap_simple(t_node *bot, t_node *top)
{
	int		tmp;

	tmp = bot->v;
	bot->v = top->v;
	top->v = tmp;
}

void    ft_cocktail_simple(t_dlist *b)
{
    int     swap;
    t_node  *n;
    int     size;
    int     mid;
    int     tmp;

    swap = 1;
    n = b->head;
    size = b->len;
    mid = size / 2;

    while (swap)
    {
        swap = 0;

        n = b->head;
        while (n && n->next)
        {
            tmp = 0;
            if (n->v > n->next->v)
            {
                ft_swap_simple(n->next, n);
                swap = 1;
            }
            size--;
            n = n->next;
        } 
    }
}

void    ft_prepare(t_dlist *b)
{
	t_node	*n;
	int		i;

	i = 0;
	n = b->head;
	while (n)
	{
		n->index = i;
		i++;
		n = n->next;
	}
}

void	ft_reset(t_dlist *b, t_dlist *a)
{
	t_node	*node_a;
	t_node	*node_b;

	node_b = b->head;
	while (node_b)
	{
		node_a = a->head;
		while (node_a)
		{
			if (node_b->v == node_a->v)
				node_a->index = node_b->index;
			node_a = node_a->next;
		}
		node_b = node_b->next;
	}
}

void	ft_clear_pile(t_dlist *b)
{
	t_node	*b_node;
	t_node	*tmp;

	b_node = b->head;
	while (b_node)
	{
		tmp = b_node;	
		b_node = b_node->next;
		free(tmp);
		tmp = NULL;
	}
	b->head = NULL;
	b->tail = NULL;
}

int		main(int argc, char **argv)
{
	t_dlist	*a;
	t_dlist	*b;
	t_ab	*pile;
	int		i;

	a = dlist_new();
	b = dlist_new();
	pile = (t_ab*)malloc(sizeof(t_ab));
	pile->a = a;
	pile->b = b;
	pile->size = 0;
	pile->print = 1;
	i = 1;

	if (argc > 1)
	{
		while (argv[i])
		{
			if (ft_is_number(argv[i]) && 
				ft_is_valid(argv[i]) && 
				ft_no_double(pile->a->head, ft_atoi(argv[i])))
			{
				dlist_push_back(pile->a, ft_atoi(argv[i]));
				dlist_push_back(pile->b, ft_atoi(argv[i]));
			}
			else
				ft_print_error();
			i++;
		}		
		ft_pile_print(a);
		ft_pile_print(b);
		printf("\n");
		ft_cocktail_simple(pile->b);
		ft_prepare(pile->b);
		ft_reset(pile->b, pile->a);
		ft_clear_pile(pile->b);
		//if (argc > 2)
		//	ft_cocktailv2(pile);
		ft_pile_print(a);
		ft_pile_print(b);
		printf("\n");
	}

	//pile->ret = ft_strjoin_free(pile->ret, "lol");
	//printf("%s\n", pile->ret);
	//ft_pile_print(a);
	//ft_test(pile);
	//ft_pile_print(a);
	//printf("\n");
	//printf("\nSize = %ld\n", pile->size);
	sleep(10);
	free(pile);
	free(a);
	free(b);
	return (0);
}
