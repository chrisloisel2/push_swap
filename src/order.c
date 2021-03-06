/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 20:29:13 by lchristo          #+#    #+#             */
/*   Updated: 2021/08/26 07:29:09 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swap.h"

void	order_two(int *d, int x, int *a)
{
	int	i;
	int	y;
	int	test;

	y = 1;
	test = 2147483647;
	i = 0;
	while (y < x)
	{
		while (i < x)
		{
			if (a[i] < test && a[i] > d[y - 1])
				test = a[i];
			i++;
		}
		d[y] = test;
		test = 2147483647;
		y++;
		i = 0;
	}
}

void	order(int *d, int x, int *a)
{
	int	i;
	int	y;
	int	test;

	i = x - 1;
	y = 1;
	test = 2147483647;
	while (i >= 0)
	{
		if (a[i] < test)
			test = a[i];
		i--;
	}
	d[0] = test;
	order_two(d, x, a);
}

int	ft_check_order(t_stack *r)
{
	int	i;
	int	y;

	y = r->lenmax - 1;
	i = 0;
	if (r->lena == 0)
		return (2);
	while (i < r->lena && (r->a[i] == r->tl[y]))
	{
		i++;
		y--;
	}
	if (y == -1)
		return (0);
	if (i == r->lena)
		return (2);
	return (1);
}
