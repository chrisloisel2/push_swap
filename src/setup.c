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

int     ft_test(char *str,  t_lst *s, int max)
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

int     ft_fill_stack2(char **argv,  t_lst *s, int num)
{
    int i;
    int y;
    char **tab;

    y = 0;
    i = 0;
    s->lenmax = s->lena;
    s->a = malloc(sizeof(int)* s->lenmax + 1);
    s->b = malloc(sizeof(int)* s->lenmax + 1);
    s->tl = malloc(sizeof(int)* s->lenmax + 1);
    tab = ft_split(argv[1], ' ');
    while (num >= 0)
    {
        while (tab[num][i] != '\0' && (ft_isdigit(tab[num][i]) || 
                (tab[num][i] == '-' && i == 0)))
            i++;
        if (i != ft_strlen(tab[num]))
            return (1);
        if (!((tab[num][i] == '\0') && ft_test(tab[num], s, y)))
            return (1);
        s->a[y] = ft_atoi(tab[num]);
        y++;
        i = 0;
        num--;
    }
    s->lena = s->lenmax;
    return(0);
}

int     ft_fill_stack(int num, char **argv,  t_lst *s)
{
    int i;
    int y;

    y = 0;
    i = 0;
    s->lenmax = num;
    s->a = malloc(sizeof(int)* num + 1);
    s->b = malloc(sizeof(int)* num + 1);
    s->tl = malloc(sizeof(int)* num + 1);
    while (num > 0)
    {
        while (argv[num][i] != '\0' && (ft_isdigit(argv[num][i]) || 
                (argv[num][i] == '-' && i == 0)))
            i++;
        if (i != ft_strlen(argv[num]))
            return (-1);
        if (!((argv[num][i] == '\0') && ft_test(argv[num], s, y)))
            return (-1);
        s->a[y] = ft_atoi(argv[num]);
        y++;
        i = 0;
        num--;
    }
    return(1);
}

int     ft_check_arg(int num, char **argv,  t_lst *s)
{
    int i;

    i = 0;
    s->lena = num;
    s->lenb = 0;
    while (num > 0)
    {
        while (argv[num][i] != '\0' && (ft_isdigit(argv[num][i]) || 
                (argv[num][i] == '-' && i == 0)))
            i++;
        if (i != ft_strlen(argv[num]))
            return (-1);
        if (!(argv[num][i] == '\0'))
            return (-1);
        i = 0;
        num--;
    }
    return(1);
}

int     ft_recup_split(char **argv,  t_lst *s)
{
    int i;
    int len;

    len = ft_strlen(argv[1]) - 1;
    i = 0;
    s->lena = 1;
    s->lenb = 0;
    while (argv[1][i] != '\0' && (ft_isdigit(argv[1][i + 1]) || 
                argv[1][i + 1] == '-' || argv[1][i + 1] == ' '))
    {
        if (argv[1][i] == ' ' && (ft_isdigit(argv[1][i + 1]) || 
                argv[1][i + 1] == '-'))
            s->lena++;
        i++;
    }
    if (i == len)
        return(ft_fill_stack2(argv, s, s->lena - 1));
    return (1);
}

int     ft_recup(int num, char **argv,  t_lst *s)
{
    if (num == 2 && (ft_strlen(argv[1]) > 2) && ft_recup_split(argv, s) == 1)
    {
        printf("ERROR\n");
        return (-1);
    }
    else if (num > 2 && (ft_check_arg(num - 1, argv, s) == -1 || 
        ft_fill_stack(num -1, argv, s) == -1))
    {
        printf("ERROR\n");
        return (-1);
    }
    return (0);
}
