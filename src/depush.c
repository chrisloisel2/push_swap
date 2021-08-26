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


int     ft_smart_depush(t_lst *s, t_stack *r)
{
    int milieu;
    int target;
    int nex;
    int i;

    if (r->lenb > 0)
        nex = next(r, r->b[r->lenb - 1]);
    else
        nex = next(r, r->b[r->lenb]);
    target = prev(r, r->a[r->lena - 1]);
    i = pos(r, r->a[r->lena - 1]) - s->posmin;
    milieu = r->tl[(s->posmin + (i/ 2))];
    if (r->lenb > 0 && target == r->b[r->lenb - 1])
        return (pa(r));
    if (target == r->b[0])
        return (rrb(r) + pa(r));
    if (target == r->a[0])
        return (rra(r));
    if (r->lenb > 0 && r->swap == 0 && r->b[r->lenb - 1] == nex)
    {
        r->swap = r->b[r->lenb - 1];
        return (pa(r));
    }
    if (r->lenb > 0 && r->b[r->lenb - 1] == r->swap)
    {
        while (r->lena > 0 && r->a[r->lena - 1] != prev(r, r->swap))
        {
            s->bot++;
            ra(r);
        }
        pa(r);
        while (s->bot > 0)
        {
            s->bot--;
            rra(r);
        }
        r->swap = 0;
        return (0);
    }
    return (ft_reversed_depusha(r));
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
        rrb(r);
    else
        rb(r);
        //ft_reversed_depushb(r);
}

int     ft_stop_depush(t_lst *s, t_stack *r)
{
    if (s->min == r->a[r->lena - 1] && ft_check_order(r) == 0)
        return (0);
    if (s->min == r->a[r->lena - 1] && ft_check_order(r) == 2)
        return (0);
    return (1);
}

void     ft_depush(t_lst *s, t_stack *r)
{
    while (ft_stop_depush(s, r))
    {
        if (prev(r, r->a[r->lena - 1]) == r->b[0] || prev(r, r->a[r->lena - 1]) == r->a[0])
            ft_smart_depush(s, r);
        else if (r->b[r->lenb - 1] >= s->min && r->b[r->lenb - 1] <= s->max)
            ft_smart_depush(s, r);
        else
            ft_smart_roll(s, r);
    }
}
