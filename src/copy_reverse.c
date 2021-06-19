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

void    ra_order(t_stack *s)
{
    int *test;
    int i;

    i = 0;
    test = malloc(sizeof(int)* s->stacka);
    test[0] = s->orda[s->stacka - 1];
    while (i < s->stacka - 1)
    {
        test[i + 1] = s->orda[i];
        i++;
    }
    free(s->orda);
    s->orda = test;
}

void    rb_order(t_stack *s)
{
    int *test;
    int i;

    i = 0;
    test = malloc(sizeof(int)* s->stackb);
    test[0] = s->ordb[s->stackb - 1];
    while (i < s->stackb - 1)
    {
        test[i + 1] = s->ordb[i];
        i++;
    }
    free(s->ordb);
    s->ordb = test;
}

void    ft_rb_order(t_stack *s)
{
    int *test;
    int i;

    i = 0;
    test = malloc(sizeof(int)* s->stackb);
    test[0] = s->ordb[s->stackb - 1];
    while (i < s->stackb - 1)
    {
        test[i + 1] = s->ordb[i];
        i++;
    }
    free(s->ordb);
    s->ordb = test;
}

void    ft_ra_order(t_stack *s)
{
    int *test;
    int i;

    i = 0;
    test = malloc(sizeof(int)* s->stacka);
    test[0] = s->orda[s->stacka - 1];
    while (i < s->stacka - 1)
    {
        test[i + 1] = s->orda[i];
        i++;
    }
    free(s->orda);
    s->orda = test;
}

void    rr_order(t_stack *s)
{
    ft_rb_order(s);
    ft_ra_order(s);
}
