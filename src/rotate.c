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

int    rra(t_lst *s)
{
    int *test;
    int i;

    i = 0;
    test = malloc(sizeof(int)* s->lenmax + 1);
    test[s->lena - 1] = s->a[0];
    while (i < s->lena - 1)
    {
        test[i] = s->a[i + 1];
        i++;
    }
    printf("rra\n");
    free(s->a);
    s->a = test;
    return (1);
}

int    rrb(t_lst *s)
{
    int *test;
    int i;

    i = 0;
    test = malloc(sizeof(int)* s->lenmax + 1);
    test[s->lenb - 1] = s->b[0];
    while (i < s->lenb - 1)
    {
        test[i] = s->b[i + 1];
        i++;
    }
    printf("rrb\n");
    free(s->b);
    s->b = test;
    return (1);
}

void    ft_rra(t_lst *s)
{
    int *test;
    int i;

    i = 0;
    test = malloc(sizeof(int)* s->lenmax + 1);
    test[s->lena - 1] = s->a[0];
    while (i < s->lena - 1)
    {
        test[i] = s->a[i + 1];
        i++;
    }
    free(s->a);
    s->a = test;
}

void    ft_rrb(t_lst *s)
{
    int *test;
    int i;

    i = 0;
    test = malloc(sizeof(int)* s->lenmax + 1);
    test[s->lenb - 1] = s->b[0];
    while (i < s->lenb - 1)
    {
        test[i] = s->b[i + 1];
        i++;
    }
    free(s->b);
    s->b = test;
}

int    rrr(t_lst *s)
{
    ft_rra(s);
    ft_rrb(s);
    printf("rrr\n");
    return (1);
}