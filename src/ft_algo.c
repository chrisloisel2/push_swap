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

void    ft_spdfix(t_stack *s)
{
    while (s->stacka > 1 && s->a[s->stacka - 1] > s->a[0])
        ra(s);
    while (s->stackb > 1 && s->b[s->stackb - 1] < s->b[0])
        rb(s);
    while (s->stacka > 1 && s->a[s->stacka - 1] < s->a[0])
        rra(s);
    while (s->stackb > 1 && s->b[s->stackb - 1] > s->b[0])
        rrb(s);
    if (s->stackb > 1 && s->b[s->stackb - 1] < s->b[s->stackb - 2] && s->a[s->stacka - 1] > s->a[s->stacka - 2])
        ss(s);
    if (s->stackb > 1 && s->b[s->stackb - 1] < s->b[s->stackb - 2])
        sb(s);
    if (s->stacka > 1 && s->a[s->stacka - 1] > s->a[s->stacka - 2])
        sa(s);
}

int     ft_check_order(t_stack *s)
{
    int i;

    i = s->stacka - 1;
    while (i > 0 && (s->a[i] < s->a[i - 1]))
        i--;
    if (i != 0)
        return (1);
    if (i == 0 && s->stackb == 0)
        return (0);
    i = s->stackb - 1;
    while (i > 0 && s->a[i] > s->a[i - 1])
        i--;
    if (i != 0)
        return (2);
    return (0);
}

int     ft_milieu(t_stack *s, int d)
{
    int i;
    int res;

    i = 0;
    res = 0;
    if (d == 1)
    {
        while (i <= s->stacka - 1)
        {
            res += s->a[i];
            i++;
        }
    }
    else
    {
        while (i <= s->stackb - 1)
        {
            res += s->b[i];
            i++;
        }
    }
    res /= i;
    return (res);
}

int     ft_check_first(t_stack *s, int test)
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

int     ft_reorg(t_stack *s, int test)
{
    int i;
    int y;

    y = 0;
    i = 0;
    while (s->num[i] != test)
        i++;
    ft_print_stack(s);
    while (s->num[i + 1] != s->b[s->stackb - 1])
    {
        printf("%d != %d\n", s->num[i + 1], s->b[s->stackb - 1]);
        rb(s);
        y++;
    }
    while (s->num[i + 1] == s->b[s->stackb - 1])
    {
        pb(s);
        i++;
    }
    while (y > 0)
    {
        rb(s);
        y--;
    }
    return (0);
}

int     ft_check_sec(t_stack *s, int test)
{
    int i;

    i = 0;
    while (s->num[i] != test)
        i++;
    if (s->num[i + 1] == s->a[s->stacka - 1])
    {
        sb(s);
        pa(s);
        return (0);
    }
    return (1);
}

void    ft_smart_depush(t_stack *s)
{
    int i;

    i = s->stackb - 1;
    ft_spdfix(s);
    if (ft_check_first(s, s->b[i]) && ft_check_sec(s, s->b[i - 1]))
        ft_reorg(s, s->b[i]);
}

void    ft_smart_push(t_stack *s)
{
    int i;
    int milieu;

    i = s->stacka - 1;
    milieu = ft_milieu(s, 1);
    while (s->stacka > ((i + 1) / 2))
    {
        ft_spdfix(s);
        while (s->a[s->stacka - 1] <= milieu)
            pb(s);
        while (s->a[0] <= milieu)
        {
            rra(s);
            pb(s);
        }
        while (s->a[s->stacka - 1] > milieu && s->stacka > ((i + 1) / 2))
            ra(s);
    }
}

void    ft_organizer(t_stack *s, int i)
{
    ft_spdfix(s);
    if (i == 1)
        ft_smart_push(s);
    else
        ft_smart_depush(s);
}

void    ft_algo(t_stack *s)
{
    int i;
    i = 0;
    ft_spdfix(s);
    while ((i = ft_check_order(s)) > 0 || s->stackb > 0)
        ft_organizer(s, i);
}