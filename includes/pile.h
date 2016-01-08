#ifndef PILE_H
# define PILE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

typedef struct 		s_node
{
	int				v;
	int 			index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct 		s_dlist
{
	size_t			len;
	t_node			*tail;
	t_node			*head;
}					t_dlist;

typedef struct  	s_ab
{
	t_dlist			*a;
	t_dlist			*b;
	long			size;
	int				print;
}					t_ab;

t_node				*dlist_create_node(int nbr);
t_dlist				*dlist_new(void);
t_dlist				*dlist_push_back(t_dlist *list, int nbr);
t_dlist				*dlist_push_front(t_dlist *list, int nbr);
t_dlist				*dlist_remove_head(t_dlist *list);
t_dlist				*dlist_remove_tail(t_dlist *list);
t_dlist 			*dist_insert(t_dlist *list, int nbr, int pos);

void				ft_pile_sa(t_ab *pile);
void				ft_pile_sb(t_ab *pile);
void				ft_pile_ss(t_ab *pile);
void				ft_pile_pa(t_ab *pile);
void				ft_pile_pb(t_ab *pile);
void				ft_pile_ra(t_ab *pile);
void				ft_pile_rb(t_ab *pile);
void				ft_pile_rr(t_ab *pile);
void				ft_pile_rra(t_ab *pile);
void				ft_pile_rrb(t_ab *pile);
void				ft_pile_rrr(t_ab *pile);

void				ft_pile_print(t_dlist *p);
int					ft_isdigit(int c);
int					ft_is_number(char *data);
void				ft_print_error();

void				ft_pair(t_ab *pile);
void    			ft_cocktail(t_ab *pile);
void    			ft_cocktailv2(t_ab *pile);
int					ft_is_valid(char *argv);
int					ft_no_double(t_node *lst, int nbr);
void 				ft_swap_right(t_ab *pile, t_node *bot, t_node *top);
void 				ft_swap_left(t_ab *pile, t_node *bot, t_node *top);
void 				ft_permute_v2(t_ab *pile, t_node *bot, t_node *top);
void				ft_best_swap(t_ab *pile, t_node *bot, t_node *top);
int 				ft_swap(t_ab *pile, t_node *n);

#endif