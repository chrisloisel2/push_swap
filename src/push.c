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

int     pos(t_lst *s, int t)
{
    int i;

    i = 0;
    while (i < s->lenmax && s->tl[i] != t)
        i++;
    return (i);
}

int     push_last_n(t_lst *s, int topa, t_stack *r)
{
    if (r->lena > 1 && s->tl[topa] == s->tl[s->lenmax - 1] &&  r->a[r->lena - 2] == s->tl[(topa - 1)])
    {
        int y;

        y = 0;
        pb(s, r);
        while (r->lena > 1 &&  r->a[r->lena - 2] == s->tl[(pos(s,  r->a[r->lena - 1]) - 1)])
        {
            pb(s, r);
            y++;
        }
        ra(s, r);
        while(y >= 0)
        {
            pa(s, r);
            ra(s, r);
            y--;
        }
        return (1);
    }
    return (0);
}

int     speed_push(t_lst *s, t_stack *r)
{
    int topb;
    int topa;
    int bota;

    if (r->lenb > 0 && r->lena > 0)
    {
        topb = pos(s,  r->a[r->lenb - 1]);
        if (topb < s->lenmax && s->tl[topb + 1] ==  r->b[0])
        {
            rrb(s, r);
            return (1);
        }
    }
    if (r->lena > 0)
    {
        topa = pos(s,  r->a[r->lena - 1]);
        bota = pos(s,  r->a[0]);
        if (r->lena > 2 && s->tl[(pos(s,  r->a[r->lena - 3])) - 1] ==  r->a[r->lena - 1])
        {
            sa(r);
            return (1);
        }
        if (topa > 0 && s->tl[topa - 1] ==  r->a[r->lena - 2])
        {
            sa(r);
            return (1);
        }
        if (push_last_n(s, topa, r))
            return (1);
        if (r->lena > 1 && s->tl[topa] == s->tl[s->lenmax - 1])
        {
            ra(s, r);
            return (1);
        }
        if (r->lena > 1 && s->tl[bota] == s->tl[topa - 1])
        {
            ra(s, r);
            return (1);
        }
        if (s->tl[topa - 1] ==  r->a[0])
        {
            rra(s, r);
            return (1);
        }
    }
    return (0);
}

void    ft_smart_push(t_lst *s, t_stack *r)
{
    int i;

    i = r->lena - s->range;
    while (r->lena > i && (ft_check_order(s, r) == 1))
    {
        while ( r->a[r->lena - 1] <= s->max && !speed_push(s, r))
            pb(s, r);
        while ( r->a[0] <  r->a[r->lena - 1] && !speed_push(s, r))
            rra(s, r);
        while ( r->a[r->lena - 1] > s->max && r->lena > i && !speed_push(s, r))
            ra(s, r);
    }
}
