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

int     speed_push(t_stack *r)
{
    while (r->lenb > 1 && r->b[r->lenb - 1] < r->b[0])
        rb(r);
    if (r->lenb > 3 && r->b[r->lenb - 2] == r->tl[0])
    {
        sb(r);
        rrb(r);
    }
    if (r->lenb > 0 && r->lena > 0)
    {
        if (r->lenb > 3 && prev(r, r->b[r->lenb - 1]) == r->b[0])
            return (rrb(r) + sb(r) + rb(r) + rb(r));
        if (r->lenb > 1 && r->b[r->lenb - 1] < r->b[r->lenb - 2])
            sb(r);
        if (r->b[r->lenb - 1] != r->tl[r->lenmax - 1] && next(r, r->b[r->lenb - 1]) == r->b[0])
             return (rrb(r));
        if (r->lena > 3 && prev(r,  r->a[r->lena - 3]) ==  r->a[r->lena - 1])
            return (sa(r));
        if (r->a[r->lena - 1] > r->tl[0] && prev(r, r->a[r->lena - 1]) == r->a[r->lena - 2])
            return (sa(r));
    }
    return (0);
}

void     ft_smart_roll2(t_lst *s, t_stack *r)
{
    int i;
    int y;

    i = r->lena - 1;
    y = 0;
    while (i > 0 && !(r->a[i] >= s->min &&  r->a[i] <= s->max))
        i--;
    y = (r->lena - 1) - i;
    i = 0;
    while (i < (r->lena - 1) && !(r->a[i] >= s->min && r->a[i] <= s->max))
        i++;
    if (y > i)
        rra(r);
    else
        ra(r);
}

void    ft_smart_push(t_lst *s, t_stack *r)
{
    int i;

    i = r->lenb + s->range;
    while (r->lenb < i && (ft_check_order(r) == 1))
    {
        speed_push(r);
        if (r->a[r->lena - 1] >= s->min && r->a[r->lena - 1] <= s->max && r->lenb < i)
            pb(r);
        else
            ft_smart_roll2(s, r);
    }
}
