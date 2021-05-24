/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 20:29:13 by lchristo          #+#    #+#             */
/*   Updated: 2019/10/11 15:01:27 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swap.h"

void    up_pos(t_stack *s, int pos)
{
    if (pos >= (s->stacka / 2))
        while (pos < s->stacka - 1)
        {
            ra(s);
            pos++;
        }
    if (pos < (s->stacka / 2))
        rra(s);
}

int     look_for_order(t_stack *s)
{
    int i;

    i = 0;
    if (s->stackb != 0)
        return (1);
    while ((s->a[i] > s->a[i + 1]) && i < s->stacka)
        i++;
    if (i == s->stacka)
        return (0);
    return (1);
}

void    ft_look_organise(t_stack *s)
{
    int i;
    int min;
    int pos;

    if (s->stacka == 0)
        return ;
    min = s->a[0]; 
    i = 0;
    pos = 0;
    while (i < s->stacka)
    {
        if (min > s->a[i])
        {
            min = s->a[i];
            pos = i;
        }
        i++;
    }
    if (pos == s->stacka - 1)
        pb(s);
    else
        up_pos(s, pos);
}

int     ft_check_return_order(t_stack *s)
{
    int i;
    int y;

    y = 0;
    i = s->stacka - 1;
    while (i > 0 && (s->a[i] < s->a[i - 1]))
        i++;
    while (y > 0 && (s->a[i] > s->a[i - 1]))
        y++;
    if (i == 0 && y == 0)
       return (1);
    return (0);
}

int     ft_organizer(t_stack *s)
{
    ft_look_organise(s);
    if (ft_check_return_order(s))
        return (1);
    return (0);
}

void    ft_reorganizer(t_stack *s)
{
    while (s->stackb > 0)
        pa(s);
}

void    ft_algo(t_stack *s)
{
   // ft_print_stack(s);
    while (look_for_order(s))
    {
        if (ft_organizer(s))
            ft_reorganizer(s);
   //     ft_print_stack(s);
    }
  //  ft_print_stack(s);
}