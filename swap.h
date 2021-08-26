/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 20:29:13 by lchristo          #+#    #+#             */
/*   Updated: 2019/10/11 15:01:27 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H
#include "libft/libft.h"

typedef struct  s_stack
{
    int     *a;
    int     *b;
    int     lena;
    int     lenb;
    int     coup;
    int     lenmax;
    int     swap;
    int     *tl;

    int     pb;
    int     pa;
    int     sa;
    int     sb;
    int     ss;
    int     ra;
    int     rb;
    int     rr;
    int     rra;
    int     rrb;
    int     rrr;
}               t_stack;

typedef struct  s_lst
{
    int     core;
    int     min;
    int     max;
    int     range;
    int     posmax;
	int     posmin;
    int     top;
    int     bot;
    struct s_lst *next;
    struct s_lst *prev;
}               t_lst;

void	lstdelcore_two(t_lst **alst, int core);
int     ft_recup(int num, char **argv, t_stack *r);
void    ft_print_lst(t_lst *s, t_stack *r);
int     ft_check_arg(int num, char **argv, t_stack *r);
void    ft_print_lst2(t_lst *s, t_stack *r);
t_lst	*ft_algo(t_lst *s, t_stack *r);
void    ft_full_pb(t_lst *s, t_stack *r);
void    order(int *d, int x, int *a);
int     ft_check_order(t_stack *r);
int     ft_smart_depush(t_lst *s, t_stack *r);
void    ft_smart_push(t_lst *s, t_stack *r);
int     speed_push(t_stack *r);
void    ft_depush(t_lst *s, t_stack *r);
int     sa(t_stack *r);
int     sb(t_stack *r);
int     ss(t_stack *r);
int     pa( t_stack *r);
int     pb(t_stack *r);
int     ra(t_stack *r);
int     rb(t_stack *r);
int     rr(t_stack *r);
int     rra(t_stack *r);
int     rrb(t_stack *r);
int     rrr(t_stack *r);
void	ft_setup(t_lst *s, t_stack *r);
t_lst	*lstdellast(t_lst **alst);
void	lstadd_back(t_lst **alst, t_lst *new, t_stack *r);
t_lst	*lstlast(t_lst *lst);
int     pos(t_stack *r, int t);
t_lst	*lstnew();
void    ft_print_core(t_lst *s);
int     next(t_stack *r, int nb);
int     prev(t_stack *r, int nb);
int     ft_reversed_depusha(t_stack *r);
int     ft_reversed_depushb(t_stack *r);
void	lstdelcore(t_lst **alst, int core);

#endif