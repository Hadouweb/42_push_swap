#ifndef PILE_H
# define PILE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct 		s_node
{
	int				v;
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
	t_dlist			**a;
	t_dlist			**b;
}					t_ab;

void				ft_pile_print(t_dlist *p);
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
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
int					ft_is_number(char *data);
void				ft_print_error();
void				ft_putchar(char c);
void				ft_putstr(char *str);
t_dlist				*ft_push_back(t_dlist *list, int nbr);
t_dlist				*ft_push_front(t_dlist *list, int nbr);
t_node				*ft_create_node(int nbr);
t_dlist 			*ft_list_insert(t_dlist *list, int nbr, int pos);
t_dlist				*ft_list_new(void);
t_dlist				*ft_remove_head(t_dlist *list);

#endif