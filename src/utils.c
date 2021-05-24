/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 20:29:13 by lchristo          #+#    #+#             */
/*   Updated: 2019/10/11 15:01:27 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../swap.h"

void    sa(t_stack *s)
{
    int i;
    int indexa;
    int indexb;
    
    if (s->stacka < 2)
        return ;
    indexa = s->stacka - 1;
    indexb = s->stacka - 2;
    i = s->a[indexb];
    s->a[indexb] = s->a[indexa];
    s->a[indexa] = i;
    printf("sa\n");
}

void    sb(t_stack *s)
{ 
    int i;
    int indexa;
    int indexb;
    
    if (s->stackb < 2)
        return ;
    indexa = s->stackb - 1;
    indexb = s->stackb - 2;
    i = s->b[indexb];
    s->b[indexb] = s->b[indexa];
    s->b[indexa] = i;
    printf("sb\n");
}

void    ss(t_stack *s)
{
    int i;
    int indexa;
    int indexb;
    
    if (s->stacka < 2 || s->stackb < 2)
        return ;
    indexa = s->stacka - 1;
    indexb = s->stacka - 2;
    i = s->a[indexb];
    s->a[indexb] = s->a[indexa];
    s->a[indexa] = i;
    indexa = s->stackb - 1;
    indexb = s->stackb - 2;
    i = s->b[indexb];
    s->b[indexb] = s->b[indexa];
    s->b[indexa] = i;
    printf("ss\n");

}

void    pa(t_stack *s)
{
    if (s->stackb < 1)
        return ;
    s->stackb--;
    s->a[s->stacka] = s->b[s->stackb];
    s->b[s->stackb] = 0;
    s->stacka++;
    printf("pa\n");
}

void    pb(t_stack *s)
{
    if (s->stacka < 1)
        return ;
    s->stacka--;
    s->b[s->stackb] = s->a[s->stacka];
    s->a[s->stacka] = 0;
    s->stackb++;
    printf("pb\n");
}