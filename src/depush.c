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

int     speed_depush(t_stack *s)
{
    int topb;
    int topa;
    int bota;
    int botb;
    int seca;
    int secb;

    ft_print_stack(s);
    if (s->stackb > 0 && s->stacka > 0)
    {
        topb = pos(s, s->b[s->stackb - 1]);
        botb = pos(s, s->b[0]);
        topa = pos(s, s->a[s->stacka - 1]);
        bota = pos(s, s->a[0]);
        if (s->stackb > 1)
            secb = pos(s, s->b[s->stacka - 2]);
        if (s->stacka > 1)
            seca = pos(s, s->a[s->stacka - 2]);
        if (topb < s->max && s->num[topb + 1] == s->b[s->stackb - 1])
        {
            sb(s);
            return (1);
        }
//        printf("s->num[%d] == s->b[%d]\n",  s->num[seca - 1], s->b[s->stackb - 1]);
        if (seca > 0 && s->num[topa - 1] == s->b[s->stackb - 2])
        {
            sb(s);
            pa(s);
            return (1);
        }
        if (seca > 0 && s->num[seca - 1] == s->b[s->stackb - 2])
        {
            sb(s);
            pa(s);
            sa(s);
            return (1);
        }
    //    printf("s->num[%d] == s->b[%d]\n", s->num[topb + 1], s->b[0]);
        if (topb < s->max && s->num[topb + 1] == s->b[0])
        {
            rrb(s);
            return (1);
        }
    //    printf("s->num[%d] == s->b[%d]\n", s->num[topb + 1], s->b[s->stackb - 2]);
        if (topb > 0 && s->num[topb + 1] == s->b[s->stackb - 2])
        {
            sb(s);
            return (1);
        }
    //    printf("s->num[%d] == s->num[%d]\n", s->num[topb], s->num[s->max - 1]);
        if (s->stackb > 1 && s->num[topb] == s->num[s->max - 1])
        {
            rb(s);
            return (1);
        }
    //    printf("s->num[%d] == s->num[%d]\n", s->num[botb], s->num[topb - 1]);
        if (s->stackb > 1 && s->num[botb] == s->num[topb - 1])
        {
            rb(s);
            return (1);
        }
    //    printf("s->num[%d] == s->b[%d]\n", s->num[topb - 1], s->b[0]);
        if (s->num[topb - 1] == s->b[0])
        {
            rrb(s);
            return (1);
        }
    }
    return (0);
}

int     ft_depush_first(t_stack *s, int test)
{
    int i;

    i = 0;
    while (s->num[i] != test)
        i++;
    if (s->num[i + 1] == s->a[s->stacka - 1])
    {
        pa(s);
        return (0);
    }
    return (1);
}

int     ft_depush_sec(t_stack *s, int test)
{
    int i;

    i = 0;
    while (i < s->stackb && s->num[i] != test)
        i++;
    if (s->num[i + 1] == s->a[s->stacka - 1])
    {
        sb(s);
        pa(s);
        return (0);
    }
    return (1);
}
 
void     ft_depush(t_stack *s)
{
    int i;
    int y;
    int milieu;

    y = 0;
    i = s->stackb - 1;
    milieu = (s->max - s->stacka) / 10;
    milieu *= 10;
    while (s->stackb >= milieu && s->stackb > 0)
    {
        if (s->b[s->stackb - 1] == s->num[pos(s, s->a[s->stacka - 1]) - 1])
            pa(s);
        while (s->b[s->stackb - 1] != s->num[pos(s, s->a[s->stacka - 1]) - 1])
        {
            rb(s);
            y++;
        }
        while (s->b[s->stackb - 1] == s->num[pos(s, s->a[s->stacka - 1]) - 1])
            pa(s);
        while (y > 1)
        {
            rrb(s);
            y--;
        }
        while (s->a[s->stacka - 1] > s->a[s->stacka - 2])
        {
            sa(s);
            pb(s);
        }
    }
}

void    ft_smart_depush(t_stack *s)
{
    int i;

    i = s->stackb - 1;
    if (ft_depush_first(s, s->b[i]) && ft_depush_sec(s, s->b[i - 1]))
        ft_depush(s);
}
