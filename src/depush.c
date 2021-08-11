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

int     linking(t_stack *s)
{
    if (s->num[pos(s, s->a[s->stacka - 1]) + 1] == s->a[s->stacka - 3])
    {
        sa(s);
        return (1);
    }
    if (s->num[pos(s, s->a[s->stacka - 1]) - 1] == s->b[s->stackb - 2])
    {
        sb(s);
        pa(s);
        return (1);
    }
    if (s->num[pos(s, s->a[s->stacka - 1]) - 1] == s->b[s->stackb - 1])
    {
        pa(s);
        return (1);
    }
    if (s->num[pos(s, s->a[s->stacka - 1]) - 1] == s->a[0])
    {
        rra(s);
        return (1);
    }
    if (s->num[pos(s, s->a[s->stacka - 1]) - 1] == s->b[0])
    {
        rrb(s);
        pa(s);
        return (2);
    }
    return (0);
}

int     ft_inversed_push(t_stack *s, int i, int min)
{
    int t;
    int y;

    y = 0;
    t = 0;
    while (i > 2)
    {
        while (i > 2 && s->b[s->stackb - 1] < min)
        {
            rb(s);
            i--;
            t++;
        }
        while (i > 2 && s->b[s->stackb - 1] >= min)
        {
            pa(s);
            while (s->a[0] != s->num[s->max - 1] && s->a[0] > s->a[s->stacka - 1])
            {
                rra(s);
                sa(s);
                y++;
            }
            while (y > 0)
            {
                y--;
                ra(s);
            }
            ra(s);
            i--;
        }
    }
    return (t);
}

int     ft_depush_two(t_stack *s, int i, int min)
{
    int t;

    t = ft_inversed_push(s, i, min);
    sb(s);
    pa(s);
    while (t > 0)
    {
        if (linking(s) == 2)
            t--;
        else
        {
            rrb(s);
            t--;
        }
    }
    return (0);
}

int     speed_depush(t_stack *s, int min, int max, int milieu)
{
    int topb;
    int topa;
    int bota;
    int botb;

    if (s->stackb > 0 && s->stacka > 0)
    {
        topb = pos(s, s->b[s->stackb - 1]);
        botb = pos(s, s->b[0]);
        topa = pos(s, s->a[s->stacka - 1]);
        bota = pos(s, s->a[0]);
        int i;

        i = 1;
        if (s->num[pos(s, s->a[s->stacka - 1]) + 1] == s->a[s->stacka - 3])
        {
            sa(s);
            return (1);
        }
        while (i <= s->stackb && s->num[topa - 1] != s->b[s->stackb - i])
            i++;
        if (i > s->stackb)
            return (1);
        if (i > 2)
        {
            ft_depush_two(s, i, min);
            return (1);
        }
        if (i == 2)
        {
            sb(s);
            pb(s);
            return (1);
        }
        if (s->num[topa - 1] == s->b[s->stackb - 1])
        {
            pa(s);
            return (1);
        }
        if (s->b[s->stackb - 1] >= s->num[milieu])
        {
            pa(s);
            return (1);
        }
    }
    return (0);
}

int     ft_fixing(t_stack *s)
{
    linking(s);
    return (0);
}

void     ft_depush(t_stack *s)
{
    int i;
    int y;
    int max;
    int min;
    int milieu;
    int mil;

    y = 0;
    i = s->stackb - 1;
    milieu = (s->max - s->stacka) / 10;
    milieu *= 10;
    mil = s->num[(5 + milieu)];
    min = s->num[(milieu) - 1];
    if (milieu == 0)
        min = s->num[0];
    max = s->num[(milieu) + 9];
    while (s->stackb >= milieu && s->stackb > 0)
    {
        ft_fixing(s);
        if (s->b[s->stackb - 1] >= min && s->b[s->stackb - 1] <= max)
            speed_depush(s, min, max, mil);
        else
        {
            rb(s);
            s->push++;
        }
    }
    while (s->push > 0)
    {
        rrb(s);
        if (linking(s) == 2)
            s->push--;
        s->push--;
    }
}
