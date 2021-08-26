/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 20:29:13 by lchristo          #+#    #+#             */
/*   Updated: 2021/08/26 06:49:32 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swap.h"

int	rra(t_stack *r)
{
	int	*test;
	int	i;

	i = 0;
	test = malloc(sizeof(int) * r->lenmax + 1);
	test[r->lena - 1] = r->a[0];
	while (i < r->lena - 1)
	{
		test[i] = r->a[i + 1];
		i++;
	}
	printf("rra\n");
	free(r->a);
	r->a = test;
	r->coup++;
	r->rra++;
	return (1);
}

int	rrb(t_stack *r)
{
	int	*test;
	int	i;

	i = 0;
	test = malloc(sizeof(int) * r->lenmax + 1);
	test[r->lenb - 1] = r->b[0];
	while (i < r->lenb - 1)
	{
		test[i] = r->b[i + 1];
		i++;
	}
	printf("rrb\n");
	free(r->b);
	r->b = test;
	r->coup++;
	r->rrb++;
	return (1);
}

void	ft_rra(t_stack *r)
{
	int	*test;
	int	i;

	i = 0;
	test = malloc(sizeof(int) * r->lenmax + 1);
	test[r->lena - 1] = r->a[0];
	while (i < r->lena - 1)
	{
		test[i] = r->a[i + 1];
		i++;
	}
	free(r->a);
	r->a = test;
}

void	ft_rrb(t_stack *r)
{
	int	*test;
	int	i;

	i = 0;
	test = malloc(sizeof(int) * r->lenmax + 1);
	test[r->lenb - 1] = r->b[0];
	while (i < r->lenb - 1)
	{
		test[i] = r->b[i + 1];
		i++;
	}
	free(r->b);
	r->b = test;
}

int	rrr(t_stack *r)
{
	ft_rra(r);
	ft_rrb(r);
	r->rrr++;
	r->coup++;
	printf("rrr\n");
	return (1);
}
