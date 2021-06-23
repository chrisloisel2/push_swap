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

int     look_for_order(t_stack *s)
{
    int i;
    int y;

    y = 0;
    i = s->stacka - 1;
    while (s->orda[i] == y && i >= 0)
    {
        y++;
        i--;
    }
    if (i == -1 && s->stackb == 0)
        return (i);
    if (i == -1 && s->stackb > 0)
    {
        y = 0;
        i = s->stackb - 1;
        while (s->ordb[i] == i && i >= 0)
        {
            y++;
            i--;
        }
        if (i == -1)
            return (i);
    }
    return (i);
}

void    smart_push_b(t_stack *s)
{
    int i;
    int y;

    i = s->orda[s->stacka - 1];
    y = 0;
    if (s->stackb == 0)
        pb(s);
    else if (i < s->ordb[0])
    {
        pb(s);
        rb(s);
    }
    else
    {
        while (i < s->ordb[s->stackb - 1])
        {
            rrb(s);
            y++;
        }
        pb(s);
        while (y > 0)
        {
            rb(s);
            y--;
        }
    }
}

int    smart_roll_a(t_stack *s, int i)
{
    int minus;
    int maximus;
    int cpt;

    cpt = 0;
    maximus = 0;
    minus = 0;
    while (cpt < i)
    {
        minus += s->orda[cpt];
        cpt++;
    }
    while (cpt < s->stacka)
    {
        maximus += s->orda[cpt];
        cpt++;
    }
    if (minus > maximus)
        return (0);
    return (1);
}

void    ft_split_half(t_stack *s)
{
    int i;
    int y;

    i = s->stacka / 2;
    while (s->stacka > i)
    {
        ft_print_stack(s);
        if (s->orda[s->stacka - 1] >= i)
            smart_push_b(s);
        else if (s->orda[0] > i)
        {
            rra(s);
            smart_push_b(s);
        }
        else
        {
            if (smart_roll_a(s, i))
            {
                y = s->stacka - 1;
                while (s->orda[y] < i)
                {
                    y--;
                    ra(s);
                }
            }
            else
            {
                y = 0;
                while (s->orda[y] < i)
                {
                    y++;
                    ra(s);
                }
            }
            
        }
    }
}

int     ft_organizer(t_stack *s)
{
    ft_split_half(s);
    ft_print_stack(s);
    return (0);
}

void    ft_algo(t_stack *s)
{
    int i;

    i = 0;
    ft_organizer(s);
    while ((i = look_for_order(s)) != -1)
    {

    }
    if (s->stackb > 0)
        ft_full_pb(s);
}