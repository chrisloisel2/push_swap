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

void	lstadd_back2(t_lst **alst, t_lst *new)
{
	t_lst *p;

	if (*alst == NULL)
	{
		new->next = NULL;
		*alst = new;
	}
	p = (lstlast(*alst));
	p->next = new;
	new->next = NULL;
	new->lenmax = p->lenmax;
	new->core = p->core + 1;
	new->tl = p->tl;
	new->move = 0;
	new->prev = p;
	new->push = 0;
}

int    slice_two(t_lst *s)
{
    int i;
    t_lst copy;

    i = s->range;
    if (s->range < 25)
        return (1);
    copy = *s;
    i = s->max;
    s = s->prev;
    lstdellast(&s);
    while (copy.max == i || s->max != i)
    {
        lstadd_back2( &s, lstnew());
        s = lstlast(s);
        if (copy.range >= 25)
            s->range = copy.range / 2;
        else
            s->range = copy.range;
        copy.range -= s->range;
        s->posmin = copy.posmin;
        copy.posmin += s->range;
	    s->posmax = s->posmin + s->range;
        copy.max = 0;
        s->max = copy.tl[s->posmax - 1];
        s->min = copy.tl[s->posmin - 1];
        ft_print_core(s);
    }
    return (1);
}

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
            ft_print_lst(s, r);
            ft_print_core(s);
            ft_smart_push(s, r);
            ft_print_lst(s, r);
            if (ft_check_order(s, r) == 1)
                lstadd_back(&s, lstnew());
            s = (lstlast(s));
        }
        while (ft_check_order(s, r) == 2 && slice_two(s) == 1)
        {
            s = lstlast(s);
            ft_depush(s , r);
            ft_print_lst(s, r);
            ft_print_core(s);
            if (s->prev != NULL)
            {
                s = s->prev;
                lstdellast(&s);
            }
            ft_print_lst(s, r);
        }
    }
}