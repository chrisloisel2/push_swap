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
}               t_stack;

int     ft_recup(int num, char **argv, t_stack *s);
void    ft_print_stack(t_stack *s);
void    ft_algo(t_stack *s);
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