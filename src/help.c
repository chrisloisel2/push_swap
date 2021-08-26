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

int     prev(t_stack *r, int nb)
{
    int i;

    i = 0;
    while (r->tl[i] != nb)
        i++;
    if (i == 0)
        return (0);
    return (r->tl[i - 1]);
}

int     next(t_stack *r, int nb)
{
    int i;

    i = 0;
    while (i < r->lenmax && r->tl[i] != nb)
        i++;
    if (i == r->lenmax)
        return (0);
    return (r->tl[i + 1]);
}

int     pos(t_stack *r, int t)
{
    int i;

    i = 0;
    while (i < r->lenmax && r->tl[i] != t)
        i++;
    return (i);
}

int     ft_reversed_depusha(t_stack *r)
{
    int test;

    test = r->a[r->lena - 1];
    while (r->a[0] != r->tl[r->lenmax - 1] && r->a[0] > r->b[r->lenb - 1])
        rra(r);
    pa(r);
    while (next(r, r->a[r->lena - 1]) == r->b[r->lenb - 1])
    {
        ra(r);
        pa(r);
    }
    ra(r);
    while (r->a[r->lena - 1] != test)
        ra(r);
    return (0);
}

int     ft_reversed_depushb(t_stack *r)
{
    int test;

    test = r->b[0];
    if (r->b[0] == r->tl[0] || (r->b[r->lenb - 1] > r->b[0]))
        return (rb(r));
    pa(r);
    while (r->b[0] != r->tl[0] && r->b[0] > r->a[r->lena - 1])
        rrb(r);
    pb(r);
    rb(r);
    while (r->b[0] != test)
        rb(r);
    return (0);
}
