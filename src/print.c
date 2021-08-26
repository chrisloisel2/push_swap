/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 20:29:13 by lchristo          #+#    #+#             */
/*   Updated: 2021/08/26 07:05:44 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swap.h"

void	ft_print_lst(t_lst *s, t_stack *r)
{
	int	i;

	if (r->lena > r->lenb)
		i = r->lena - 1;
	else
		i = r->lenb - 1;
	printf("  état de la stack %d\n-----------------------\n", s->core);
	printf("   {%d}            {%d}\nnum = ", r->lena, r->lenb);
	while (i >= 0)
	{
		if (r->lena > i)
			printf("|a[%d]", r->a[i]);
		else
			printf("     ");
		printf("    %d       ", i);
		if (r->lenb > i)
			printf("b[%d]|\n", r->b[i]);
		else
			printf("\n");
		i--;
	}
	printf("range = %d\n", s->range);
	printf("\n");
}

void	ft_print_core(t_lst *s)
{
	printf("----------core = %d----------\n", s->core);
	printf("  range[%d]\n", s->range);
	printf(" posmax[%d]\n", s->posmax);
	printf(" posmin[%d]\n", s->posmin);
	printf("    max[%d]\n", s->max);
	printf("    min[%d]\n", s->min);
	printf("   push[%d]\n", s->top);
	printf("   push[%d]\n", s->bot);
}

void	lstdelcore_two(t_lst **alst, int core)
{
	t_lst	*sup;
	t_lst	*after;
	t_lst	*before;

	sup = (lstlast(*alst));
	while (sup->prev != NULL && core != sup->core)
		sup = sup->prev;
	if (sup->prev == NULL && sup->next != NULL)
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

void	ft_setup(t_lst *s, t_stack *r)
{
	s->core = 1;
	s->next = NULL;
	s->prev = NULL;
	s->range = r->lena / 2;
	s->posmin = 0;
	s->bot = 0;
	s->top = 0;
	s->posmax = s->posmin + s->range - 1;
	s->max = r->tl[s->posmax];
	s->min = r->tl[s->posmin];
}
