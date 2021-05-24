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

void    ra(t_stack *s)
{
    int *test;
    int i;

    i = 0;
    test = malloc(sizeof(int)* s->stacka);
    test[0] = s->a[s->stacka - 1];
    while (i < s->stacka - 1)
    {
        test[i + 1] = s->a[i];
        i++;
    }
    printf("ra\n");
    free(s->a);
    s->a = test;
}

void    rb(t_stack *s)
{
    int *test;
    int i;

    i = 0;
    test = malloc(sizeof(int)* s->stackb);
    test[0] = s->b[s->stackb - 1];
    while (i < s->stackb - 1)
    {
        test[i + 1] = s->b[i];
        i++;
    }
    printf("rb\n");
    free(s->b);
    s->b = test;
}

void    ft_rb(t_stack *s)
{
    int *test;
    int i;

    i = 0;
    test = malloc(sizeof(int)* s->stackb);
    test[0] = s->b[s->stackb - 1];
    while (i < s->stackb - 1)
    {
        test[i + 1] = s->b[i];
        i++;
    }
    free(s->b);
    s->b = test;
}

void    ft_ra(t_stack *s)
{
    int *test;
    int i;

    i = 0;
    test = malloc(sizeof(int)* s->stacka);
    test[0] = s->a[s->stacka - 1];
    while (i < s->stacka - 1)
    {
        test[i + 1] = s->a[i];
        i++;
    }
    free(s->a);
    s->a = test;
}

void    rr(t_stack *s)
{
    ft_rb(s);
    ft_ra(s);
    printf("rr\n");
}