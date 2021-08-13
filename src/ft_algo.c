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

int     ft_milieu(t_lst *s, char c)
{
    int res;
    int *nb;

    nb = malloc(sizeof(int)* s->lenmax + 1);
    if (c == 'a')
    {
        order(nb, s->lena, s->a);
        res = nb[(s->lena - 1)/2];
        free(nb);
    }
    else
    {
        res = (s->a[s->lena - 1] / 10);
        free(nb);
        res *= 10;
    }
    return (res);
}

void    ft_organizer(t_lst *s, int i)
{
    
}

void    ft_algo(t_lst *s)
{
    int i;
    i = 0;
    s->range = (s->lena + 1) / 2;
    s->posmin = 0;
    s->posmax = s->posmin + s->range - 1;
    s->max = s->tl[s->posmax];
    s->min = s->tl[s->posmin];
    while ((i = ft_check_order(s)) > 0)
    {
        if (i == 1)
        {
            ft_smart_push(s);
            ft_print_lst(s);
            lstadd_back(&s, lstnew());
            s = (lstlast(s));
        }
        else
        {
            ft_depush(s);
            ft_print_lst(s);
            s = s->prev;
        }
    }
}