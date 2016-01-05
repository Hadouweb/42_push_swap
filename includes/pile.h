#ifndef PILE_H
# define PILE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

typedef struct  	s_ab
{
	t_dlist			**a;
	t_dlist			**b;
}					t_ab;

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
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
int					ft_is_number(char *data);
void				ft_print_error();

void 				ft_quicksort(t_dlist *a, int debut, int fin, t_node *n_pivot);

#endif