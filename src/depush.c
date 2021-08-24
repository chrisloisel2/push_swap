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
    if (r->tl[pos(s,  r->a[r->lena - 1], r) + 1] ==  r->a[r->lena - 3])
        return (sa(r));
    if (r->tl[pos(s,  r->a[r->lena - 1], r) - 1] ==  r->b[r->lenb - 2])
        return ((sb(r) + pa(s, r)) - 1);
    if (r->tl[pos(s,  r->a[r->lena - 1], r) - 1] ==  r->b[r->lenb - 1])
        return (pa(s, r));
    if (r->tl[pos(s,  r->a[r->lena - 1], r) - 1] ==  r->a[0])
        return (rra(s, r));
    if (r->tl[pos(s,  r->a[r->lena - 1], r) - 1] ==  r->b[0])
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
        while (i > 2 && r->b[r->lenb - 1] >= s->min)
        {
            pa(s, r);
            while (r->a[0] != r->tl[s->lenmax - 1] &&  r->a[0] > r->a[r->lena - 1])
            {
                rra(s, r);
                sa(r);
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
    }
    return (t);
}

int     ft_depush_two(t_lst *s, int i, t_stack *r)
{
    int t;

    t = ft_inversed_push(s, i, r);
    sb(r);
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
        if (r->tl[pos(s,  r->a[r->lena - 1], r) + 1] ==  r->a[r->lena - 3])
            return (sa(r));
        while (i <= r->lenb && r->tl[topa - 1] !=  r->b[r->lenb - i])
            i++;
        if (i > r->lenb)
            return (1);
        if (i > 2)
            return (ft_depush_two(s, i, r));
        if (i == 2)
            return (sb(r) + pb(s, r) - 1);
        if (r->tl[topa - 1] ==  r->b[r->lenb - 1])
            return (pa(s, r));
        if ( r->b[r->lenb - 1] >= r->tl[s->posmin + (s->range / 2)])
            return (pa(s, r));
    }
    return (0);
}

void     ft_smart_roll(t_lst *s, t_stack *r)
{
    int i;
    int y;

    i = r->lenb - 1;
    y = 0;
    while (i > 0 && !(r->b[i] >= s->min &&  r->b[i] <= s->max))
        i--;
    y = (r->lenb - 1) - i;
    i = 0;
    while (i < (r->lenb - 1) && !(r->b[i] >= s->min && r->b[i] <= s->max))
        i++;
    if (y > i)
        rrb(s, r);
    else
        rb(s, r);
    s->bot++;
}

void     ft_depush(t_lst *s, t_stack *r)
{
    int i;
    
    i = 1;
    while (i != 2 && i != 0)
    {
        if (!linking(s, r))
        {
            if ( r->b[r->lenb - 1] >= s->min &&  r->b[r->lenb - 1] <= s->max)
                speed_depush(s, r);
            else if (!(r->a[r->lena - 1] <= s->min || r->lenb == 0))
                ft_smart_roll(s, r);
        }
        if (r->a[r->lena - 1] <= s->min || r->lenb == 0)
            i = ft_check_order(s, r);
    }
    while (s->bot > 0)
    {
        rrb(s, r);
        if (linking(s, r) == 2)
            s->bot--;
        s->bot--;
    }
}
