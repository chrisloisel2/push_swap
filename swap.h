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
    int push;
}               t_stack;

typedef struct  s_lst
{
    int     core;
    int     lenmax;
    int     *tl;
    int     min;
    int     max;
    int     range;
    int     posmax;
	int     posmin;
    int     move;
    int push;
    struct s_lst *next;
    struct s_lst *prev;
}               t_lst;

int     ft_recup(int num, char **argv, t_lst *s, t_stack *r);
void    ft_print_lst(t_lst *s, t_stack *r);
void    ft_print_lst2(t_lst *s, t_stack *r);
void    ft_algo(t_lst *s, t_stack *r);
void    ft_full_pb(t_lst *s, t_stack *r);
void    order(int *d, int x, int *a);
int     ft_check_order(t_lst *s, t_stack *r);
void    ft_smart_depush(t_lst *s, t_stack *r);
void    ft_smart_push(t_lst *s, t_stack *r);
int     speed_push(t_lst *s, t_stack *r);
int     pos(t_lst *s, int t, t_stack *r);
void    ft_depush(t_lst *s, t_stack *r);
int     sa(t_lst *s, t_stack *r);
int     sb(t_lst *s, t_stack *r);
int     ss(t_lst *s, t_stack *r);
int     pa(t_lst *s, t_stack *r);
int     pb(t_lst *s, t_stack *r);
int     ra(t_lst *s, t_stack *r);
int     rb(t_lst *s, t_stack *r);
int     rr(t_lst *s, t_stack *r);
int     rra(t_lst *s, t_stack *r);
int     rrb(t_lst *s, t_stack *r);
int     rrr(t_lst *s, t_stack *r);
void	lstdellast(t_lst **alst);
void	lstadd_back(t_lst **alst, t_lst *new);
t_lst	*lstlast(t_lst *lst);
t_lst	*lstnew();

#endif