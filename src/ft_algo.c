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

void    ft_algo(t_lst *s, t_stack *r)
{
    int i;
    i = 0;
    s->core = 1;
    s->move = 0;
    s->range = r->lena / 2;
    s->posmin = 0;
    s->posmax = s->posmin + s->range - 1;
    s->max = s->tl[s->posmax];
    s->min = s->tl[s->posmin];
    while ((i = ft_check_order(s, r)) > 0)
    {
        while (ft_check_order(s, r) == 1)
        {
            ft_smart_push(s, r);
            ft_print_lst(s, r);
            lstadd_back(&s, lstnew());
            s = (lstlast(s));
        }
        while (r->lenb > 0)
        {
            ft_depush(s , r);
            ft_print_lst(s, r);
            s = s->prev;
            ft_print_lst(s, r);
        }
    }
}