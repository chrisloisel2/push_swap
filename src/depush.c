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

int    speed_depush(t_stack *s)
{
    int i;
    int y;

    i = 0;
    y = 0;
    while (s->num[i] != s->a[s->stacka - 1])
        i++;
    if (s->b[s->stackb - 1] == s->num[i - 1])
        pa(s);
    if (i > 0)
        return (1);
    return (0);
}
 
void     ft_depush(t_stack *s)
{
    int i;
    int milieu;

    i = s->stackb - 1;
    milieu = ft_milieu(s, 'b');
    while (s->stackb > ((i + 1) / 2))
    {
        while (s->b[s->stackb - 1] >= milieu)
            pa(s);
        while (s->b[0] > s->b[s->stackb - 1])
            rrb(s);
        while (s->b[s->stackb - 1] < milieu && s->stackb > ((i + 1) / 2))
            rb(s);
    }
}

void    ft_smart_depush(t_stack *s)
{
    int i;

    i = s->stackb - 1;
    if (ft_depush_first(s, s->b[i]) && ft_depush_sec(s, s->b[i - 1]))
        ft_depush(s);
}
