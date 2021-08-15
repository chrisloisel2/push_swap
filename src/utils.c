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

int    sa(t_stack *r)
{
    int i;
    int indexa;
    int indexb;
    
    if (r->lena < 2)
        return (1);
    indexa = r->lena - 1;
    indexb = r->lena - 2;
    i =  r->a[indexb];
     r->a[indexb] =  r->a[indexa];
     r->a[indexa] = i;
     r->coup++;
    printf("sa\n");
    return (1);
}

int    sb(t_stack *r)
{ 
    int i;
    int indexa;
    int indexb;
    
    if (r->lenb < 2)
        return (1);
    indexa = r->lenb - 1;
    indexb = r->lenb - 2;
    i =  r->b[indexb];
    r->b[indexb] =  r->b[indexa];
    r->b[indexa] = i;
    r->coup++;
    printf("sb\n");
    return (1);
}

int    ss(t_stack *r)
{
    int i;
    int indexa;
    int indexb;
    
    if (r->lena < 2 || r->lenb < 2)
        return (1);
    indexa = r->lena - 1;
    indexb = r->lena - 2;
    i =  r->a[indexb];
     r->a[indexb] =  r->a[indexa];
     r->a[indexa] = i;
    indexa = r->lenb - 1;
    indexb = r->lenb - 2;
    i =  r->b[indexb];
     r->b[indexb] =  r->b[indexa];
     r->b[indexa] = i;
    printf("ss\n");
    return (1);
}

int    pa(t_lst *s, t_stack *r)
{
    if (r->lenb < 1)
        return (1);
     r->a[r->lena] =  r->b[r->lenb - 1];
     r->b[r->lenb - 1] = 0;
    r->lena++;
    r->lenb--;
    s->move--;
    r->coup++;
    printf("pa\n");
    return (1);
}

int    pb(t_lst *s, t_stack *r)
{
    if (r->lena < 1)
        return (1);
     r->b[r->lenb] =  r->a[r->lena - 1];
     r->a[r->lena - 1] = 0;
    r->lenb++;
    r->lena--;
    s->move++;
    r->coup++;
    printf("pb\n");
    return (1);
}