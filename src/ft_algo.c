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
	new->move = 0;
	new->prev = p;
	new->push = 0;
}

void    reorder_three(t_lst *s, t_stack *r)
{
    while (ft_check_order(s, r) == 1)
    {
        if (r->a[r->lena - 1] == r->tl[s->lenmax - 1])
            ra(s, r);
        if (r->a[0] < r->a[r->lena - 1])
            rra(s, r);
        if (r->a[r->lena - 1] > r->a[r->lena - 2] || r->a[r->lena - 2] == r->tl[s->lenmax -1])
            sa(r);
    }
}

int    slice_two(t_lst *s, t_stack *r)
{
    int i;
    t_lst copy;
    int core;

    i = s->range;
    if (s->range < 25)
        return (1);
    copy = *s;
    core = s->core;
    i = s->max;
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
        s->max = r->tl[s->posmax - 1];
        if (s->posmin == 0)
            s->min = r->tl[0];
        else
            s->min = r->tl[s->posmin - 1];
    }
    lstdelcore(&s, core);
    return (1);
}

void    ft_algo(t_lst *s, t_stack *r)
{
    int i;
    i = 0;
    s->core = 1;
    s->move = 0;
    s->next = NULL;
    s->prev = NULL;
    s->range = r->lena / 2;
    s->posmin = 0;
	s->push = 0;
    s->posmax = s->posmin + s->range - 1;
    s->max = r->tl[s->posmax];
    s->min = r->tl[s->posmin];
    while ((i = ft_check_order(s, r)) > 0)
    {
        while (ft_check_order(s, r) == 1)
        {
            if (r->lena > 3)
                ft_smart_push(s, r);
            else
                reorder_three(s, r);
            if (ft_check_order(s, r) == 1 && r->lena > 3)
            {
                lstadd_back(&s, lstnew(), r);
                s = (lstlast(s));
            }
        }
        while (ft_check_order(s, r) == 2 && slice_two(s, r) == 1)
        {
            s = lstlast(s);
            ft_depush(s , r);
            if (s->prev != NULL)
            {
                s = s->prev;
                lstdellast(&s);
            }
        }
    }
}