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

int     ft_depush_first(t_stack *s, int test)
{
    int i;

    i = 0;
    while (s->num[i] != test)
        i++;
    if (s->num[i + 1] == s->a[s->stacka - 1])
    {
        pa(s);
        return (0);
    }
    return (1);
}

int     ft_depush_sec(t_stack *s, int test)
{
    int i;

    i = 0;
    while (i < s->stackb && s->num[i] != test)
        i++;
    if (s->num[i + 1] == s->a[s->stacka - 1])
    {
        sb(s);
        pa(s);
        return (0);
    }
    return (1);
}

int    speed_depush(t_stack *s)
{
    int i;
    int y;

    i = 0;
    y = 0;
    while (s->num[i] != s->a[s->stacka - 1])
        i++;
    if (s->b[s->stackb - 1] == s->num[i - 1])
        pa(s);
    if (i > 0)
        return (1);
    return (0);
}
 
int     ft_depush_reorganizer(t_stack *s, int test)
{
    int i;
    int y;

    y = 0;
    i = 0;
    while (i < s->stackb && s->num[i] != test)
        i++;
    while (s->stackb > 1 && s->num[i - 1] != s->b[s->stackb - 1] && speed_depush(s))
    {
        rb(s);
        y++;
    }
    while (s->num[i - 1] == s->b[s->stackb - 1] && speed_depush(s))
    {
        pa(s);
        i++;
    }
    while (y > 0 && speed_depush(s))
    {
        rrb(s);
        y--;
    }
    return (0);
}

void    ft_smart_depush(t_stack *s)
{
    int i;

    i = s->stackb - 1;
    if (ft_depush_first(s, s->b[i]) && ft_depush_sec(s, s->b[i - 1]))
        ft_depush_reorganizer(s, s->a[s->stacka - 1]);
}
