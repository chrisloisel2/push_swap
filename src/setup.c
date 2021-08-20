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

int     ft_test(char *str, int max, t_stack *r)
{
    int i;
    long test;

    test = ft_atoi(str);
    if (test > 2147483647 || test < -2147483648)
        return (0);
    i = 0;
    while (i < max)
    {
        if ( r->a[i] == test)
            return (0);
        i++;
    }
    return (1);
}

int     ft_fill_stack2(char **argv,  t_lst *s, int num, t_stack *r)
{
    int i;
    int y;
    char **tab;

    y = 0;
    i = 0;
    s->lenmax = r->lena;
     r->a = malloc(sizeof(int)* s->lenmax + 1);
     r->b = malloc(sizeof(int)* s->lenmax + 1);
    r->tl = malloc(sizeof(int)* s->lenmax + 1);
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
    r->lena = s->lenmax;
    return(0);
}

int     ft_fill_stack(int num, char **argv,  t_lst *s, t_stack *r)
{
    int i;
    int y;

    y = 0;
    i = 0;
    s->lenmax = num;
    r->a = malloc(sizeof(int)* num + 1);
    r->b = malloc(sizeof(int)* num + 1);
    r->tl = malloc(sizeof(int)* num + 1);
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
    return(1);
}

int     ft_check_arg(int num, char **argv, t_stack *r)
{
    int i;

    i = 0;
    r->lena = num;
    r->lenb = 0;
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

int     ft_recup_split(char **argv,  t_lst *s, t_stack *r)
{
    int i;
    int len;

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
        return(ft_fill_stack2(argv, s, r->lena - 1, r));
    return (1);
}

int     ft_recup(int num, char **argv,  t_lst *s, t_stack *r)
{
    if (num == 2 && (ft_strlen(argv[1]) > 2) && ft_recup_split(argv, s, r) == 1)
    {
        printf("ERROR\n");
        return (-1);
    }
    else if (num > 2 && (ft_check_arg(num - 1, argv, r) == -1 || 
        ft_fill_stack(num -1, argv, s, r) == -1))
    {
        printf("ERROR\n");
        return (-1);
    }
    return (0);
}
