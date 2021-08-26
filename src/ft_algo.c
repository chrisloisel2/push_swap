/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 20:29:13 by lchristo          #+#    #+#             */
/*   Updated: 2021/08/26 07:57:42 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swap.h"

void	lstadd_back2(t_lst **alst, t_lst *new)
{
	t_lst	*p;

	if (*alst == NULL)
	{
		new->next = NULL;
		*alst = new;
	}
	p = (lstlast(*alst));
	p->next = new;
	new->next = NULL;
	new->core = p->core + 1;
	new->prev = p;
	new->top = 0;
	new->bot = 0;
}

void	reorder_three(t_stack *r)
{
	while (ft_check_order(r) == 1)
	{
		if (r->a[r->lena - 1] == r->tl[r->lenmax - 1])
			ra(r);
		if (r->a[0] < r->a[r->lena - 1])
			rra(r);
		if (r->a[r->lena - 1] > r->a[r->lena - 2])
			sa(r);
		if (r->a[r->lena - 2] == r->tl[r->lenmax - 1])
			sa(r);
	}
}

void	ft_setup_two(t_lst *s, t_stack *r, t_lst *copy)
{
	lstadd_back2(&s, lstnew());
	s = lstlast(s);
	if (copy->range >= 25)
		s->range = copy->range / 2;
	else
		s->range = copy->range;
	copy->range -= s->range;
	s->posmin = copy->posmin;
	copy->posmin += s->range;
	s->posmax = s->posmin + s->range;
	copy->max = 0;
	s->max = r->tl[s->posmax];
	if (s->posmin == 0)
		s->min = r->tl[0];
	else
		s->min = r->tl[s->posmin];
}

t_lst	*slice_two(t_lst *s, t_stack *r)
{
	int		i;
	t_lst	*copy;
	int		core;

	i = s->range;
	if (s->range < 25)
		return (s);
	copy = s;
	core = s->core;
	i = s->max;
	while (copy->max == i || s->max != i)
	{
		ft_setup_two(s, r, copy);
		if (s->max > i)
			s->max = i;
	}
	lstdelcore(&s, core);
	return (lstlast(s));
}

t_lst	*ft_algo(t_lst *s, t_stack *r)
{
	ft_setup(s, r);
	while (ft_check_order(r) > 0)
	{
		while (ft_check_order(r) == 1)
		{
			if (r->lena > 3)
				ft_smart_push(s, r);
			else
				reorder_three(r);
			if (ft_check_order(r) == 1 && r->lena > 3)
			{
				lstadd_back(&s, lstnew(), r);
				s = lstlast(s);
			}
		}
		while (ft_check_order(r) == 2)
		{
			s = slice_two(s, r);
			ft_depush(s, r);
			s = lstdellast(&s);
		}
	}
	return (s = lstlast(s));
}
