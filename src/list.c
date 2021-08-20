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

t_lst	*lstnew()
{
	t_lst *lsnext;

	if (!(lsnext = malloc(sizeof(t_lst))))
		return (NULL);
	lsnext->next = NULL;
	return (lsnext);
}

t_lst	*lstlast(t_lst *lst)
{
	t_lst	*t;

	t = lst;
	if (lst != NULL)
	{
		while (t->next != NULL)
			t = t->next;
	}
	return (t);
}

void	lstdellast(t_lst **alst)
{
	t_lst *p;
	t_lst *end;

	p = (lstlast(*alst));
	if (p != NULL && p->prev != NULL)
	{
		end = p->prev;
		end->next = NULL;
		free(p);
		p = NULL;
	}
}

void	lstdelcore(t_lst **alst, int core)
{
	t_lst *sup;
	t_lst *after;
	t_lst *before;

	sup = (lstlast(*alst));
	while (sup->prev != NULL && core != sup->core)
		sup = sup->prev;
	if (sup->prev != NULL && sup->next != NULL)
	{
		after = sup->next;
		before = sup->prev;
		before->next = after;
		after->prev = before;
		free(sup);
		sup = NULL;
	}
	else if (sup->prev == NULL && sup->next != NULL)
	{
		after = sup->next;
		alst = &after;
		after->prev = NULL;
		free(sup);
		sup = NULL;
	}
	else if (sup->prev != NULL && sup->next == NULL)
	{
		before = sup->prev;
		before = NULL;
		free(sup);
		sup = NULL;
	}
}

void	lstadd_back(t_lst **alst, t_lst *new, t_stack *r)
{
	t_lst *p;
	int i;

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
    i = p->range / 2;
	new->range = p->range - i;
	new->move = 0;
	new->posmin = p->posmax + 1;
	new->posmax = new->posmin + new->range;
    new->max = r->tl[new->posmax - 1];
    new->min = r->tl[new->posmin - 1];
	new->push = 0;


	new->prev = p;
	new->push = 0;
}
