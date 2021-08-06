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
        pa(s);
    return (0);
}

int     ft_check_last(t_stack *s, int test)
{
    int i;

    i = 0;
    while (s->num[i] != test)
        i++;
    if (s->num[i + 1] == s->a[s->stacka - 1])
    {
        rb(s);
        pa(s);
    }
    return (0);
}

void    ft_smart_depush(t_stack *s)
{
    int i;

    i = s->stackb - 1;
    ft_check_first(s, s->b[i]);
    ft_check_last(s, s->b[0]);
}

void    ft_smart_push(t_stack *s)
{
    int i;
    int milieu;

    i = s->stacka - 1;
    milieu = ft_milieu(s, 1);
    while (s->a[i] < milieu)
    {
        pb(s);
        i--;
    }
    i = 0;
    while (s->a[i] <= milieu)
    {
        rra(s);
        pb(s);
    }
}

void    ft_organizer(t_stack *s, int i)
{
    if (i == 1)
        ft_smart_push(s);
    else
        ft_smart_depush(s);
}

void    ft_algo(t_stack *s)
{
    int i;
    i = 0;
    while ((i = ft_check_order(s)) > 0 || s->stackb > 0)
        ft_organizer(s, i);
}