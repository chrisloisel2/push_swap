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

int    ra(t_lst *s, t_stack *r)
{
    int *test;
    int i;

    i = 0;
    test = malloc(sizeof(int)* s->lenmax);
    test[0] =  r->a[r->lena - 1];
    while (i < r->lena - 1)
    {
        test[i + 1] =  r->a[i];
        i++;
    }
    free( r->a);
     r->a = test;
    r->coup++;
    r->ra++;
    printf("ra\n");
    return (1);
}

int    rb(t_lst *s, t_stack *r)
{
    int *test;
    int i;

    if (r->lenb < 2)
        return (1);
    i = 0;
    test = malloc(sizeof(int)* s->lenmax);
    test[0] =  r->b[r->lenb - 1];
    while (i < r->lenb - 1)
    {
        test[i + 1] =  r->b[i];
        i++;
    }
    free( r->b);
    r->b = test;
    r->coup++;
    r->rb++;
    printf("rb\n");
    return (1);
}

void    ft_rb(t_lst *s, t_stack *r)
{
    int *test;
    int i;

    i = 0;
    test = malloc(sizeof(int)* s->lenmax);
    test[0] =  r->b[r->lenb - 1];
    while (i < r->lenb - 1)
    {
        test[i + 1] =  r->b[i];
        i++;
    }
    free( r->b);
    r->b = test;
}

void    ft_ra(t_lst *s, t_stack *r)
{
    int *test;
    int i;

    i = 0;
    test = malloc(sizeof(int)* s->lenmax);
    test[0] =  r->a[r->lena - 1];
    while (i < r->lena - 1)
    {
        test[i + 1] =  r->a[i];
        i++;
    }
    free( r->a);
    r->a = test;
}

int    rr(t_lst *s, t_stack *r)
{
    ft_rb(s, r);
    ft_ra(s, r);
    r->coup++;
    r->rr++;
    printf("rr\n");
    return (1);
}
