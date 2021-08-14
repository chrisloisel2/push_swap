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

int     linking(t_lst *s, t_stack *r)
{
    if (s->tl[pos(s,  r->a[r->lena - 1], r) + 1] ==  r->a[r->lena - 3])
        return (sa(s, r));
    if (s->tl[pos(s,  r->a[r->lena - 1], r) - 1] ==  r->b[r->lenb - 2])
        return ((sb(s, r) + pa(s, r)) - 1);
    if (s->tl[pos(s,  r->a[r->lena - 1], r) - 1] ==  r->b[r->lenb - 1])
        return (pa(s, r));
    if (s->tl[pos(s,  r->a[r->lena - 1], r) - 1] ==  r->a[0])
        return (rra(s, r));
    if (s->tl[pos(s,  r->a[r->lena - 1], r) - 1] ==  r->b[0])
        return (rrb(s, r) + pa(s, r));
    return (0);
}

int     ft_inversed_push(t_lst *s, int i, t_stack *r)
{
    int t;
    int y;

    y = 0;
    t = 0;
    while (i > 2)
    {
        while (i > 2 &&  r->b[r->lenb - 1] < s->min)
        {
            rb(s, r);
            i--;
            t++;
        }
        while (i > 2 &&  r->b[r->lenb - 1] >= s->min)
        {
            pa(s, r);
            while ( r->a[0] != s->tl[s->lenmax - 1] &&  r->a[0] >  r->a[r->lena - 1])
            {
                rra(s, r);
                sa(s, r);
                y++;
            }
            while (y > 0)
            {
                y--;
                ra(s, r);
            }
            ra(s, r);
            i--;
        }
        ft_print_lst(s, r);
    }
    return (t);
}

int     ft_depush_two(t_lst *s, int i, t_stack *r)
{
    int t;

    t = ft_inversed_push(s, i, r);
    sb(s, r);
    pa(s, r);
    while (t > 0)
    {
        if (linking(s, r) == 2)
            t--;
        else
        {
            rrb(s, r);
            t--;
        }
    }
    return (1);
}

int     speed_depush(t_lst *s, t_stack *r)
{
    int topa;

    if (r->lenb > 0 && r->lena > 0)
    {
        topa = pos(s,  r->a[r->lena - 1], r);
        int i;

        i = 1;
        if (s->tl[pos(s,  r->a[r->lena - 1], r) + 1] ==  r->a[r->lena - 3])
            return (sa(s, r));
        while (i <= r->lenb && s->tl[topa - 1] !=  r->b[r->lenb - i])
            i++;
        if (i > r->lenb)
            return (1);
        if (i > 2)
            return (ft_depush_two(s, i, r));
        if (i == 2)
            return (sb(s, r) + pb(s, r) - 1);
        if (s->tl[topa - 1] ==  r->b[r->lenb - 1])
            return (pa(s, r));
        if ( r->b[r->lenb - 1] >= s->tl[s->posmin + (s->range / 2)])
            return (pa(s, r));
    }
    return (0);
}

void     ft_depush(t_lst *s, t_stack *r)
{
    while (s->move > 0 && r->a[r->lena - 1] != s->min)
    {
        linking(s, r);
        if ( r->b[r->lenb - 1] >= s->min &&  r->b[r->lenb - 1] <= s->max)
            speed_depush(s, r);
        else
        {
            rb(s, r);
            s->push++;
        }
    }
    while (s->push > 0)
    {
        rrb(s, r);
        if (linking(s, r) == 2)
            s->push--;
        s->push--;
    }
}
