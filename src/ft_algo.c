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
        return (0);
    if (i == -1 && s->stackb > 0)
    {
        y = 0;
        i = s->stackb - 1;
        while (s->ordb[i] == y && i >= 0)
        {
            y++;
            i--;
        }
        if (i == -1)
            return (0);
    }
    return (1);
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
            rb(s);
            y++;
        }
        pb(s);
        while (y > 0)
        {
            rrb(s);
            y--;
        }
    }
}

void    ft_split_half(t_stack *s)
{
    int i;

    i = s->stacka / 2;
    while (s->stacka > i)
    {
        if (s->orda[s->stacka - 1] >= i)
            smart_push_b(s);
        else if (s->orda[0] > i)
        {
            rra(s);
            smart_push_b(s);
        }
        else
        {
            if (s->orda[s->stacka - 1] > s->orda[0])
                rra(s);
            else
                ra(s);
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
    while (look_for_order(s))
    {
        ft_organizer(s);
    }
}