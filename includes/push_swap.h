/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 04:38:47 by nle-bret          #+#    #+#             */
/*   Updated: 2016/01/11 04:38:50 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct		s_value
{
	int				nbr;
	int				index;
}					t_value;

typedef struct		s_node
{
	t_value			*v;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_dlist
{
	int				len;
	t_node			*tail;
	t_node			*head;
}					t_dlist;

typedef struct		s_ab
{
	t_dlist			*a;
	t_dlist			*b;
	long			size;
	int				print;
	int				min;
	char			*seq;
}					t_ab;

t_node				*dlist_create_node(t_value *value);
t_dlist				*dlist_new(void);
t_dlist				*dlist_push_back(t_dlist *list, int nbr, int index);
t_dlist				*dlist_push_front(t_dlist *list, int nbr, int index);
t_dlist				*dlist_remove_head(t_dlist *list);
t_dlist				*dlist_remove_tail(t_dlist *list);

int					ft_sort(t_dlist *a);
int					ft_swap(t_ab *pile, t_node *n, int way);
void				ft_algo(t_ab *pile);

void				ft_swap_sa(t_ab	*pile, t_node *n, int way);
void				ft_check_sa(t_ab *pile);
void				ft_swap_simple(t_node *bot, t_node *top);
void				ft_cocktail_simple(t_dlist *b);

void				ft_print_error();
int					ft_no_double(t_node *lst, int nbr);
int					ft_is_number(char *data);
int					ft_is_valid(char *argv);
void				ft_print_pile(t_dlist *lst);

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

void				ft_reset(t_dlist *b, t_dlist *a);
void				ft_clear_pile(t_dlist *b);
void				ft_prepare(t_ab	*pile);

t_ab				*ft_init_pile(void);
void				ft_resolve(t_ab *pile, int nb_elem);

#endif
