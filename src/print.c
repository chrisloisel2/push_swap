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

void    ft_print_lst(t_lst *s, t_stack *r)
{
    int i;
    int cpy;
    
    if (r->lena > r->lenb)
        i = r->lena - 1;
    else
        i = r->lenb - 1;
    cpy = s->lenmax - 1;
    printf("  état de la stack %d\n-----------------------\n", s->core);
    printf("   {%d}            {%d}\nnum = ", r->lena, r->lenb);
    while (cpy > 0)
    {
        printf("%d , ", s->tl[cpy]);
        cpy--;
    }
    printf("%d\n", s->tl[cpy]);
    while (i >= 0)
    {
        if (r->lena > i)
            printf("|a[%d]",  r->a[i]);
        else
            printf("     ");
        printf("    %d       ", i);
        if (r->lenb > i)
            printf("b[%d]|\n",  r->b[i]);
        else
            printf("\n");
        i--;
    }
    printf("range = %d\n", s->range);
    printf("\n");
}

void    ft_print_lst2(t_lst *s, t_stack *r)
{
      int i;

    if (r->lena > r->lenb)
        i = r->lena - 1;
    else
        i = r->lenb - 1;
    printf("  état de la stack\n-----------------------\n");
    printf("   {%d}                   {%d}\n", r->lena, r->lenb);
    while (i >= 0)
    {    
        printf("|a[%d]",  r->a[i]);
        printf("    %d       ", i);
        printf("b[%d]|\n",  r->b[i]);
        i--;
    }
    printf("\n");
}
