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

void    ft_print_stack(t_stack *s)
{
    int i;
    int cpy;
    
    if (s->stacka > s->stackb)
        i = s->stacka - 1;
    else
        i = s->stackb - 1;
    cpy = s->max - 1;
    printf("  état de la stack\n-----------------------\n");
    printf("   {%d}            {%d}\nnum = ", s->stacka, s->stackb);
    while (cpy > 0)
    {
        printf("%d , ", s->num[cpy]);
        cpy--;
    }
    printf("%d\n", s->num[cpy]);
    while (i >= 0)
    {
        if (s->stacka > i)
            printf("|a[%d]", s->a[i]);
        else
            printf("     ");
        printf("    %d       ", i);
        if (s->stackb > i)
            printf("b[%d]|\n", s->b[i]);
        else
            printf("\n");
        i--;
    }
    printf("\n");
}

void    ft_print_stack2(t_stack *s)
{
      int i;

    if (s->stacka > s->stackb)
        i = s->stacka - 1;
    else
        i = s->stackb - 1;
    printf("  état de la stack\n-----------------------\n");
    printf("   {%d}                   {%d}\n", s->stacka, s->stackb);
    while (i >= 0)
    {    
        printf("|a[%d]", s->a[i]);
        printf("    %d       ", i);
        printf("b[%d]|\n", s->b[i]);
        i--;
    }
    printf("\n");
}
