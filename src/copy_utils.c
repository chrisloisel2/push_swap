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

void    sa_order(t_stack *s)
{
    int i;
    int indexa;
    int indexb;
    
    if (s->stacka < 2)
        return ;
    indexa = s->stacka - 1;
    indexb = s->stacka - 2;
    i = s->orda[indexb];
    s->orda[indexb] = s->orda[indexa];
    s->orda[indexa] = i;
}

void    sb_order(t_stack *s)
{ 
    int i;
    int indexa;
    int indexb;
    
    if (s->stackb < 2)
        return ;
    indexa = s->stackb - 1;
    indexb = s->stackb - 2;
    i = s->ordb[indexb];
    s->ordb[indexb] = s->ordb[indexa];
    s->ordb[indexa] = i;
}

void    ss_order(t_stack *s)
{
    int i;
    int indexa;
    int indexb;
    
 
    indexa = s->stacka - 1;
    indexb = s->stacka - 2;
    i = s->orda[indexb];
    s->orda[indexb] = s->orda[indexa];
    s->orda[indexa] = i;
    indexa = s->stackb - 1;
    indexb = s->stackb - 2;
    i = s->ordb[indexb];
    s->ordb[indexb] = s->ordb[indexa];
    s->ordb[indexa] = i;

}

void    pa_order(t_stack *s)
{
    s->orda[s->stacka] = s->ordb[s->stackb];
    s->ordb[s->stackb] = 0;
}

void    pb_order(t_stack *s)
{
    s->ordb[s->stackb - 1] = s->orda[s->stacka];
    s->orda[s->stacka] = 0;
}