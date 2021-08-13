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

typedef struct  s_lst
{
    int     *a;
    int     *b;
    int     lena;
    int     lenb;
    int     lenmax;
    int     *tl;
    int     min;
    int     max;
    int     range;
    int     posmax;
	int     posmin;

    int push;
    struct s_lst *next;
    struct s_lst *prev;
}               t_lst;

int     ft_recup(int num, char **argv, t_lst *s);
void    ft_print_lst(t_lst *s);
void    ft_print_lst2(t_lst *s);
void    ft_algo(t_lst *s);
void    ft_full_pb(t_lst *s);
void    order(int *d, int x, int *a);
int     ft_check_order(t_lst *s);
void    ft_smart_depush(t_lst *s);
void    ft_smart_push(t_lst *s);
int     speed_push(t_lst *s);
int     ft_milieu(t_lst *s, char c);
int     pos(t_lst *s, int t);
void     ft_depush(t_lst *s);
void    order(int *d, int x, int *a);
int     ft_check_order(t_lst *s);
int     sa(t_lst *s);
int     sb(t_lst *s);
int     ss(t_lst *s);
int     pa(t_lst *s);
int     pb(t_lst *s);
int     ra(t_lst *s);
int     rb(t_lst *s);
int     rr(t_lst *s);
int     rra(t_lst *s);
int     rrb(t_lst *s);
int     rrr(t_lst *s);
void	lstdellast(t_lst **alst);
void	lstadd_back(t_lst **alst, t_lst *new);
t_lst	*lstlast(t_lst *lst);
t_lst	*lstnew();

#endif