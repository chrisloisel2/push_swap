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

int     linking(t_lst *s)
{
    if (s->tl[pos(s, s->a[s->lena - 1]) + 1] == s->a[s->lena - 3])
        return (sa(s));
    if (s->tl[pos(s, s->a[s->lena - 1]) - 1] == s->b[s->lenb - 2])
        return ((sb(s) + pa(s)) - 1);
    if (s->tl[pos(s, s->a[s->lena - 1]) - 1] == s->b[s->lenb - 1])
        return (pa(s));
    if (s->tl[pos(s, s->a[s->lena - 1]) - 1] == s->a[0])
        return (rra(s));
    if (s->tl[pos(s, s->a[s->lena - 1]) - 1] == s->b[0])
        return (rrb(s) + pa(s));
    return (0);
}

int     ft_inversed_push(t_lst *s, int i)
{
    int t;
    int y;

    y = 0;
    t = 0;
    while (i > 2)
    {
        while (i > 2 && s->b[s->lenb - 1] < s->min)
        {
            rb(s);
            i--;
            t++;
        }
        while (i > 2 && s->b[s->lenb - 1] >= s->min)
        {
            pa(s);
            while (s->a[0] != s->tl[s->lenmax - 1] && s->a[0] > s->a[s->lena - 1])
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

int     ft_depush_two(t_lst *s, int i)
{
    int t;

    t = ft_inversed_push(s, i);
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
    return (1);
}

int     speed_depush(t_lst *s)
{
    int topa;

    if (s->lenb > 0 && s->lena > 0)
    {
        topa = pos(s, s->a[s->lena - 1]);
        int i;

        i = 1;
        if (s->tl[pos(s, s->a[s->lena - 1]) + 1] == s->a[s->lena - 3])
            return (sa(s));
        while (i <= s->lenb && s->tl[topa - 1] != s->b[s->lenb - i])
            i++;
        if (i > s->lenb)
            return (1);
        if (i > 2)
            return (ft_depush_two(s, i));
        if (i == 2)
            return (sb(s) + pb(s) - 1);
        if (s->tl[topa - 1] == s->b[s->lenb - 1])
            return (pa(s));
        if (s->b[s->lenb - 1] >= s->tl[s->posmin + (s->range / 2)])
            return (pa(s));
    }
    return (0);
}

void     ft_depush(t_lst *s)
{
    while (s->lenb > (s->lenmax - s->range) && ft_check_order(s) != 2)
    {
        linking(s);
        if (s->b[s->lenb - 1] >= s->min && s->b[s->lenb - 1] <= s->max)
            speed_depush(s);
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
