#ifndef PILE_H
# define PILE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct 		s_pile
{
	int				value;
	struct s_pile 	*prev;
}					t_pile;

typedef struct  	s_ab
{
	t_pile			**a;
	t_pile			**b;
}					t_ab;

void				ft_pile_push(t_pile **p, int nbr);
void				ft_pile_pop(t_pile **p);
void				ft_pile_clean(t_pile **p);
void				ft_pile_print(t_pile *p);
void				ft_pile_sa(t_ab *pile);
void				ft_pile_sb(t_ab *pile);
void				ft_pile_ss(t_ab *pile);
void				ft_pile_pb(t_ab *pile);
void				ft_pile_ra(t_ab *pile);
void				ft_pile_rb(t_ab *pile);
void				ft_pile_rr(t_ab *pile);
void				ft_pile_rra(t_ab *pile);
void				ft_pile_rrb(t_ab *pile);
void				ft_pile_rrr(t_ab *pile);

#endif