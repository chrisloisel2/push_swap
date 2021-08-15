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

void	lstadd_back2(t_lst **alst, t_lst *new, int i)
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
    new->range = i / 2;
	new->tl = p->tl;
	new->move = 0;
	new->posmax = p->posmax;
	new->posmin = new->posmax - new->range;
    new->max = new->tl[new->posmax - 1];
    new->min = new->tl[new->posmin - 1];


	new->prev = p;
	new->push = 0;
}

int    slice(t_lst *s, t_stack *r)
{
    if  (s->range < 25)
        return (1);
        lstadd_back2(&s, lstnew(), s->range);
        lstadd_back2(&s, lstnew(), s->range);
        s = lstlast(s);
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
            ft_smart_push(s, r);
            ft_print_lst(s, r);
            if (ft_check_order(s, r) == 1)
                lstadd_back(&s, lstnew());
            s = (lstlast(s));
        }
        while (ft_check_order(s, r) == 2 && slice(s, r))
        {
            ft_depush(s , r);
            ft_print_lst(s, r);
            if (s->prev != NULL)
            {
                s = s->prev;
                lstdellast(&s);
            }
            ft_print_lst(s, r);
        }
    }
}