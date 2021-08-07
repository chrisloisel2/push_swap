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
    int     stacka;
    int     stackb;
    int     *num;
    int     max;
}               t_stack;

int     ft_recup(int num, char **argv, t_stack *s);
void    ft_print_stack(t_stack *s);
void    ft_print_stack2(t_stack *s);
void    ft_algo(t_stack *s);
void    ft_full_pb(t_stack *s);
void    order(int *d, int x, int *a);
int     ft_check_order(t_stack *s);
void    ft_smart_depush(t_stack *s);
void    ft_smart_push(t_stack *s);
int     speed_push(t_stack *s);
int     ft_milieu(t_stack *s, char c);
void    sa(t_stack *s);
void    sb(t_stack *s);
void    ss(t_stack *s);
void    pa(t_stack *s);
void    pb(t_stack *s);
void    ra(t_stack *s);
void    rb(t_stack *s);
void    rr(t_stack *s);
void    rra(t_stack *s);
void    rrb(t_stack *s);
void    rrr(t_stack *s);

#endif