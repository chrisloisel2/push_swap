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

void    order(int *d, int x, int *a)
{
    int i;
    int y;
    int test;

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
    test = 2147483647;
    i = 0;
    while (y <= x)
    {
        while (i <= x)
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

int     ft_push_swap(int num, char **argv)
{
    t_stack *s;
    s = malloc(sizeof(t_stack));
    if (ft_recup(num, argv, s) == -1)
        return (-1);
    order(s->num, s->stacka, s->a);
    ft_algo(s);
    free(s->a);
    free(s->b);
    free(s->num);
    free(s);
    return (0);
}

int     main(int argc, char **argv)
{
    if (argc  < 2)
    {
        printf("ERROR ARG");
        return (0);
    }
    else
        ft_push_swap(argc, argv);
    return (0);
}
