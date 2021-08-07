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

void    ft_marks(t_stack *s)
{
    int i;
    int y;
    int test;

    i = s->stacka - 1;
    s->i = i;
    y = 1;
    test = 2147483647;
    while (i >= 0)
    {
        if (s->a[i] < test)
            test = s->a[i];
        i--;
    }
    s->num[0] = test;
    test = 2147483647;
    while (y < s->stacka)
    {
        while (i < s->stacka)
        {         
            if (s->a[i] < test && s->a[i] > s->num[y - 1])        
                test = s->a[i];
            i++;
        }
        s->num[y] = test;
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
    ft_marks(s);
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
}
