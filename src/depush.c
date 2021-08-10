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

int     speed_depush(t_stack *s, int min, int max, int milieu)
{
    int topb;
    int topa;
    int bota;
    int botb;

    ft_print_stack(s);
    if (s->stackb > 0 && s->stacka > 0)
    {
        topb = pos(s, s->b[s->stackb - 1]);
        botb = pos(s, s->b[0]);
        topa = pos(s, s->a[s->stacka - 1]);
        bota = pos(s, s->a[0]);
        if (s->num[topa - 1] == s->b[s->stackb - 1])
        {
            pa(s);
            return (1);
        }
        if (s->b[s->stackb - 1] >= milieu)
        {
            pa(s);
            return (1);
        }
    }
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
    mil = (s->max - milieu) / 2;
    min = s->num[(milieu) - 1];
    max = s->num[(milieu) + 9];
    while (s->stackb >= milieu && s->stackb > 0)
    {
        if (s->b[s->stackb - 1] >= min && s->b[s->stackb - 1] <= max)
            speed_depush(s, min, max, mil);
        else
        {
                rb(s);
                s->push++;
        }
        if  (ft_check_order(s) == 1)
        {
            ft_print_stack(s);
        }
    }
}
