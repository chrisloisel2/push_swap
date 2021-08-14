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
	if (p->prev != NULL)
	{
		end = p->prev;
		end->next = NULL;
		free(p);
	}
}

void	lstadd_back(t_lst **alst, t_lst *new)
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
    new->range = p->range / 2;
	new->tl = p->tl;
	new->move = 0;
	new->posmin = p->posmax + 1;
	new->posmax = new->posmin + new->range;
    new->max = new->tl[new->posmax - 1];
    new->min = new->tl[new->posmin - 1];


	new->prev = p;
	new->push = 0;
}
