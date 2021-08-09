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

void    rra(t_stack *s)
{
    int *test;
    int i;

    i = 0;
    s->rra++;
    s->coups++;
    test = malloc(sizeof(int)* s->max + 1);
    test[s->stacka - 1] = s->a[0];
    while (i < s->stacka - 1)
    {
        test[i] = s->a[i + 1];
        i++;
    }
    printf("rra\n");
    free(s->a);
    s->a = test;
}

void    rrb(t_stack *s)
{
    int *test;
    int i;

    i = 0;
    s->rrb++;
    s->coups++;
    test = malloc(sizeof(int)* s->max + 1);
    test[s->stackb - 1] = s->b[0];
    while (i < s->stackb - 1)
    {
        test[i] = s->b[i + 1];
        i++;
    }
    printf("rrb\n");
    free(s->b);
    s->b = test;
}

void    ft_rra(t_stack *s)
{
    int *test;
    int i;

    i = 0;
    test = malloc(sizeof(int)* s->max + 1);
    test[s->stacka - 1] = s->a[0];
    while (i < s->stacka - 1)
    {
        test[i] = s->a[i + 1];
        i++;
    }
    free(s->a);
    s->a = test;
}

void    ft_rrb(t_stack *s)
{
    int *test;
    int i;

    i = 0;
    test = malloc(sizeof(int)* s->max + 1);
    test[s->stackb - 1] = s->b[0];
    while (i < s->stackb - 1)
    {
        test[i] = s->b[i + 1];
        i++;
    }
    free(s->b);
    s->b = test;
}

void    rrr(t_stack *s)
{
    s->rrr++;
    s->coups++;
    ft_rra(s);
    ft_rrb(s);
    printf("rrr\n");
}