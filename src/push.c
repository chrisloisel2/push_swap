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

int     pos(t_stack *s, int t)
{
    int i;

    i = 0;
    while (i < s->max && s->num[i] != t)
        i++;
    return (i);
}

int     push_last_n(t_stack *s, int topa)
{
    if (s->stacka > 1 && s->num[topa] == s->num[s->max - 1] && s->a[s->stacka - 2] == s->num[(topa - 1)])
    {
        int y;

        y = 0;
        pb(s);
        while (s->stacka > 1 && s->a[s->stacka - 2] == s->num[(pos(s, s->a[s->stacka - 1]) - 1)])
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

int     speed_push(t_stack *s)
{
    int topb;
    int topa;
    int bota;
    int botb;

    ft_print_stack(s);
    if (s->stackb > 0 && s->stacka > 0)
    {
        topb = pos(s, s->a[s->stackb - 1]);
        botb = pos(s, s->a[0]);
        if (topb < s->max && s->num[topb + 1] == s->b[0])
        {
            rrb(s);
            return (1);
        }
    }
    if (s->stacka > 0)
    {
        topa = pos(s, s->a[s->stacka - 1]);
        bota = pos(s, s->a[0]);
        if (s->stacka > 2 && s->num[(pos(s, s->a[s->stacka - 3])) - 1] == s->a[s->stacka - 1])
        {
            sa(s);
            return (1);
        }
        if (topa > 0 && s->num[topa - 1] == s->a[s->stacka - 2])
        {
            sa(s);
            return (1);
        }
        if (push_last_n(s, topa))
            return (1);
        if (s->stacka > 1 && s->num[topa] == s->num[s->max - 1])
        {
            ra(s);
            return (1);
        }
        if (s->stacka > 1 && s->num[bota] == s->num[topa - 1])
        {
            ra(s);
            return (1);
        }
        if (s->num[topa - 1] == s->a[0])
        {
            rra(s);
            return (1);
        }
    }
    return (0);
}

void    ft_smart_push(t_stack *s)
{
    int i;
    int milieu;

    i = s->stacka - 1;
    milieu = ft_milieu(s, 'a');
    while (s->stacka > ((i + 1) / 2) && (ft_check_order(s) == 1))
    {
        while (s->a[s->stacka - 1] <= milieu && !speed_push(s))
            pb(s);
        while (s->a[0] < s->a[s->stacka - 1] && !speed_push(s))
            rra(s);
        while (s->a[s->stacka - 1] > milieu && s->stacka > ((i + 1) / 2) && !speed_push(s))
            ra(s);
    }
}
