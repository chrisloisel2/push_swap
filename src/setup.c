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

int     ft_test(char *str, t_stack *s, int max)
{
    int i;
    long test;

    test = ft_atoi(str);
    if (test > 2147483647 || test < -2147483648)
        return (0);
    i = 0;
    while (i < max)
    {
        if (s->a[i] == test)
            return (0);
        i++;
    }
    return (1);
}

int     ft_fill_stack(int num, char **argv, t_stack *s)
{
    int i;
    int y;

    y = 0;
    i = 0;
    s->a = malloc(sizeof(int)* num + 1);
    s->b = malloc(sizeof(int)* num + 1);
    while (num > 0)
    {
        while (argv[num][i] != '\0' && (ft_isdigit(argv[num][i]) || 
                argv[num][i] == '-'))
            i++;
        if (!((argv[num][i] == '\0') && ft_test(argv[num], s, y)))
            return (-1);
        s->a[y] = ft_atoi(argv[num]);
        y++;
        i = 0;
        num--;
    }
    return(1);
}

int     ft_check_arg(int num, char **argv, t_stack *s)
{
    int i;

    i = 0;
    s->stacka = num;
    s->stackb = 0;
    while (num > 0)
    {
        while (argv[num][i] != '\0' && (ft_isdigit(argv[num][i]) || 
                argv[num][i] == '-'))
            i++;
        if (!(argv[num][i] == '\0'))
            return (-1);
        i = 0;
        num--;
    }
    return(1);
}

void    ft_print_stack(t_stack *s)
{
    int i;

    if (s->stacka > s->stackb)
        i = s->stacka - 1;
    else
        i = s->stackb - 1;
    printf("  état de la stack\n-----------------------\n");
    printf("   {%d}            {%d}\n", s->stacka, s->stackb);
    while (i >= 0)
    {
        printf("|a[%d] =%d          b[%d] =%d|\n", i, s->a[i], i, s->b[i]);
        i--;
    }
    printf("\n");
}

int     ft_recup(int num, char **argv, t_stack *s)
{
    if (ft_check_arg(num - 1, argv, s) == -1 || 
        ft_fill_stack(num -1, argv, s) == -1)
    {
        printf("ERROR");
        return (-1);
    }
    return (0);
}
