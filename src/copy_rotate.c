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

void    rra_order(t_stack *s)
{
    int *test;
    int i;

    i = 0;
    test = malloc(sizeof(int)* s->stacka);
    test[s->stacka - 1] = s->orda[0];
    while (i < s->stacka - 1)
    {
        test[i] = s->orda[i + 1];
        i++;
    }
    free(s->orda);
    s->orda = test;
}

void    rrb_order(t_stack *s)
{
    int *test;
    int i;

    i = 0;
    test = malloc(sizeof(int)* s->stackb);
    test[s->stackb - 1] = s->ordb[0];
    while (i < s->stackb - 1)
    {
        test[i] = s->ordb[i + 1];
        i++;
    }
    free(s->ordb);
    s->ordb = test;
}

void    ft_rra_order(t_stack *s)
{
    int *test;
    int i;

    i = 0;
    test = malloc(sizeof(int)* s->stacka);
    test[s->stacka - 1] = s->orda[0];
    while (i < s->stacka - 1)
    {
        test[i] = s->orda[i + 1];
        i++;
    }
    free(s->orda);
    s->orda = test;
}

void    ft_rrb_order(t_stack *s)
{
    int *test;
    int i;

    i = 0;
    test = malloc(sizeof(int)* s->stackb);
    test[s->stackb - 1] = s->ordb[0];
    while (i < s->stackb - 1)
    {
        test[i] = s->ordb[i + 1];
        i++;
    }
    free(s->ordb);
    s->ordb = test;
}

void    rrr_order(t_stack *s)
{
    ft_rra_order(s);
    ft_rrb_order(s);
}