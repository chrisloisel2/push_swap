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
    new->a = p->a;
    new->b = p->b;
    new->max = p->max;
    new->min = p->min;
    new->range = p->range / 2;
}
