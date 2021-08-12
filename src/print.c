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

void    ft_print_lst(t_lst *s)
{
    int i;
    int cpy;
    
    if (s->lena > s->lenb)
        i = s->lena - 1;
    else
        i = s->lenb - 1;
    cpy = s->max - 1;
    printf("  état de la stack\n-----------------------\n");
    printf("   {%d}            {%d}\nnum = ", s->lena, s->lenb);
    while (cpy > 0)
    {
        printf("%d , ", s->tl[cpy]);
        cpy--;
    }
    printf("%d\n", s->tl[cpy]);
    while (i >= 0)
    {
        if (s->lena > i)
            printf("|a[%d]", s->a[i]);
        else
            printf("     ");
        printf("    %d       ", i);
        if (s->lenb > i)
            printf("b[%d]|\n", s->b[i]);
        else
            printf("\n");
        i--;
    }
    printf("\n");
}

void    ft_print_lst2(t_lst *s)
{
      int i;

    if (s->lena > s->lenb)
        i = s->lena - 1;
    else
        i = s->lenb - 1;
    printf("  état de la stack\n-----------------------\n");
    printf("   {%d}                   {%d}\n", s->lena, s->lenb);
    while (i >= 0)
    {    
        printf("|a[%d]", s->a[i]);
        printf("    %d       ", i);
        printf("b[%d]|\n", s->b[i]);
        i--;
    }
    printf("\n");
}
