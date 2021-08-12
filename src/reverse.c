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

void    ra(t_lst *s)
{
    int *test;
    int i;

    i = 0;
    test = malloc(sizeof(int)* s->lenmax);
    test[0] = s->a[s->lena - 1];
    while (i < s->lena - 1)
    {
        test[i + 1] = s->a[i];
        i++;
    }
    free(s->a);
    s->a = test;
    printf("ra\n");
}

void    rb(t_lst *s)
{
    int *test;
    int i;

    if (s->lenb < 2)
        return ;
    i = 0;
    test = malloc(sizeof(int)* s->lenmax);
    test[0] = s->b[s->lenb - 1];
    while (i < s->lenb - 1)
    {
        test[i + 1] = s->b[i];
        i++;
    }
    free(s->b);
    s->b = test;
    printf("rb\n");
}

void    ft_rb(t_lst *s)
{
    int *test;
    int i;

    i = 0;
    test = malloc(sizeof(int)* s->lenmax);
    test[0] = s->b[s->lenb - 1];
    while (i < s->lenb - 1)
    {
        test[i + 1] = s->b[i];
        i++;
    }
    free(s->b);
    s->b = test;
}

void    ft_ra(t_lst *s)
{
    int *test;
    int i;

    i = 0;
    test = malloc(sizeof(int)* s->lenmax);
    test[0] = s->a[s->lena - 1];
    while (i < s->lena - 1)
    {
        test[i + 1] = s->a[i];
        i++;
    }
    free(s->a);
    s->a = test;
}

void    rr(t_lst *s)
{
    ft_rb(s);
    ft_ra(s);
    printf("rr\n");
}
