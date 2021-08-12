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
    int     *num;
    int     max;

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
void    sa(t_lst *s);
void    sb(t_lst *s);
void    ss(t_lst *s);
void    pa(t_lst *s);
void    pb(t_lst *s);
void    ra(t_lst *s);
void    rb(t_lst *s);
void    rr(t_lst *s);
void    rra(t_lst *s);
void    rrb(t_lst *s);
void    rrr(t_lst *s);

#endif