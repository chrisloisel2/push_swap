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

int     push_last_n(t_lst *s, int topa)
{
    if (s->lena > 1 && s->tl[topa] == s->tl[s->lenmax - 1] && s->a[s->lena - 2] == s->tl[(topa - 1)])
    {
        int y;

        y = 0;
        pb(s);
        while (s->lena > 1 && s->a[s->lena - 2] == s->tl[(pos(s, s->a[s->lena - 1]) - 1)])
        {
            pb(s);
            y++;
        }
        ra(s);
        while(y >= 0)
        {
            pa(s);
            ra(s);
            y--;
        }
        return (1);
    }
    return (0);
}

int     speed_push(t_lst *s)
{
    int topb;
    int topa;
    int bota;

    if (s->lenb > 0 && s->lena > 0)
    {
        topb = pos(s, s->a[s->lenb - 1]);
        if (topb < s->lenmax && s->tl[topb + 1] == s->b[0])
        {
            rrb(s);
            return (1);
        }
    }
    if (s->lena > 0)
    {
        topa = pos(s, s->a[s->lena - 1]);
        bota = pos(s, s->a[0]);
        if (s->lena > 2 && s->tl[(pos(s, s->a[s->lena - 3])) - 1] == s->a[s->lena - 1])
        {
            sa(s);
            return (1);
        }
        if (topa > 0 && s->tl[topa - 1] == s->a[s->lena - 2])
        {
            sa(s);
            return (1);
        }
        if (push_last_n(s, topa))
            return (1);
        if (s->lena > 1 && s->tl[topa] == s->tl[s->lenmax - 1])
        {
            ra(s);
            return (1);
        }
        if (s->lena > 1 && s->tl[bota] == s->tl[topa - 1])
        {
            ra(s);
            return (1);
        }
        if (s->tl[topa - 1] == s->a[0])
        {
            rra(s);
            return (1);
        }
    }
    return (0);
}

void    ft_smart_push(t_lst *s)
{
    int i;

    i = s->lena - 1;
    while (s->lena > s->range && (ft_check_order(s) == 1))
    {
        while (s->a[s->lena - 1] <= s->max && !speed_push(s))
            pb(s);
        while (s->a[0] < s->a[s->lena - 1] && !speed_push(s))
            rra(s);
        while (s->a[s->lena - 1] > s->max && s->lena > s->range && !speed_push(s))
            ra(s);
    }
}
