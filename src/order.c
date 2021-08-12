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

void    order(int *d, int x, int *a)
{
    int i;
    int y;
    int test;

    i = x - 1;
    y = 1;
    test = 2147483647;
    while (i >= 0)
    {
        if (a[i] < test)
            test = a[i];
        i--;
    }
    d[0] = test;
    test = 2147483647;
    i = 0;
    while (y <= x)
    {
        while (i <= x)
        {         
            if (a[i] < test && a[i] > d[y - 1])        
                test = a[i];
            i++;
        }
        d[y] = test;
        test = 2147483647;
        y++;
        i = 0;
    }
}

int     ft_check_order(t_lst *s)
{
    int i;
    int y;
    int test;

    y = s->max - 1;
    i = 0;
    if (s->lena == 0)
        return (2);
    test = s->tl[y];
    while (i < s->lena && (s->a[i] == s->tl[y]))
    {
        i++;
        y--;
    }
    if (y == -1)
        return (0);
    if (i == s->lena)
        return (2);
    return (1);
}

