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
    int y;
    int test;

    y = s->max - 1;
    i = 0;
    if (s->stacka == 0)
        return (2);
    test = s->num[y];
    while (i < s->stacka && (s->a[i] == s->num[y]))
    {
        i++;
        y--;
    }
    if (y == -1)
        return (0);
    if (i == s->stacka)
        return (2);
    return (1);
}

int     ft_milieu(t_stack *s, char c)
{
    int res;
    int *nb;

    nb = malloc(sizeof(int)* s->max + 1);
    if (c == 'a')
    {
        order(nb, s->stacka, s->a);
        res = nb[(s->stacka - 1)/2];
        free(nb);
    }
    else
    {
        res = (s->a[s->stacka - 1] / 10);
        free(nb);
        res *= 10;
    }
    return (res);
}

void    ft_organizer(t_stack *s, int i)
{
    if (i == 1)
        ft_smart_push(s);
    else
        ft_depush(s);
}

void    ft_algo(t_stack *s)
{
    int i;
    i = 0;
    while ((i = ft_check_order(s)) > 0 || s->stackb > 0)
    {
        ft_organizer(s, i);
        ft_print_stack(s);
    }
}