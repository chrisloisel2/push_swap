/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 20:29:13 by lchristo          #+#    #+#             */
/*   Updated: 2021/08/26 06:46:09 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swap.h"

int	ft_test(char *str, int max, t_stack *r)
{
	int		i;
	long	test;

	test = ft_atoi(str);
	if (test > 2147483647 || test < -2147483648)
		return (0);
	i = 0;
	while (i < max)
	{
		if (r->a[i] == test)
			return (0);
		i++;
	}
	return (1);
}

int	ft_fill_stack2(char **argv, int num, t_stack *r)
{
	int		i;
	int		y;
	char	**tab;

	y = 0;
	i = 0;
	r->lenmax = r->lena;
	tab = ft_split(argv[1], ' ');
	while (num >= 0)
	{
		while (tab[num][i] != '\0' && (ft_isdigit(tab[num][i]) ||
					(tab[num][i] == '-' && i == 0)))
			i++;
		if (i != ft_strlen(tab[num]))
			return (1);
		if (!((tab[num][i] == '\0') && ft_test(tab[num], y, r)))
			return (1);
		r->a[y] = ft_atoi(tab[num]);
		y++;
		i = 0;
		num--;
	}
	r->lena = r->lenmax;
	return (0);
}

int	ft_fill_stack(int num, char **argv, t_stack *r)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	r->lenmax = num;
	while (num > 0)
	{
		while (argv[num][i] != '\0' && (ft_isdigit(argv[num][i]) ||
					(argv[num][i] == '-' && i == 0)))
			i++;
		if (i != ft_strlen(argv[num]))
			return (-1);
		if (!((argv[num][i] == '\0') && ft_test(argv[num], y, r)))
			return (-1);
		r->a[y] = ft_atoi(argv[num]);
		y++;
		i = 0;
		num--;
	}
	return (1);
}

int	ft_recup_split(char **argv, t_stack *r)
{
	int	i;
	int	len;

	len = ft_strlen(argv[1]) - 1;
	i = 0;
	r->lena = 1;
	r->lenb = 0;
	while (argv[1][i] != '\0' && (ft_isdigit(argv[1][i + 1]) ||
				argv[1][i + 1] == '-' || argv[1][i + 1] == ' '))
	{
		if (argv[1][i] == ' ' && (ft_isdigit(argv[1][i + 1]) ||
					argv[1][i + 1] == '-'))
			r->lena++;
		i++;
	}
	if (i == len)
		return (ft_fill_stack2(argv, r->lena - 1, r));
	return (1);
}

int	ft_recup(int num, char **argv, t_stack *r)
{
	r->a = malloc(sizeof(int) * num + 1);
	r->b = malloc(sizeof(int) * num + 1);
	r->tl = malloc(sizeof(int) * num + 1);
	if (num == 2 && (ft_strlen(argv[1]) > 2) && ft_recup_split(argv, r) == 1)
	{
		printf("ERROR\n");
		return (-1);
	}
	else if (num > 2 && (ft_check_arg(num - 1, argv, r) == -1))
	{
		printf("ERROR\n");
		return (-1);
	}
	if (num > 2 && ft_fill_stack(num - 1, argv, r) == -1)
	{
		printf("ERROR\n");
		return (-1);
	}
	return (0);
}
