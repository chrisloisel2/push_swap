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

void    sa(t_lst *s)
{
    int i;
    int indexa;
    int indexb;
    
    if (s->lena < 2)
        return ;
    indexa = s->lena - 1;
    indexb = s->lena - 2;
    i = s->a[indexb];
    s->a[indexb] = s->a[indexa];
    s->a[indexa] = i;
    printf("sa\n");
}

void    sb(t_lst *s)
{ 
    int i;
    int indexa;
    int indexb;
    
    if (s->lenb < 2)
        return ;
    indexa = s->lenb - 1;
    indexb = s->lenb - 2;
    i = s->b[indexb];
    s->b[indexb] = s->b[indexa];
    s->b[indexa] = i;
    printf("sb\n");
}

void    ss(t_lst *s)
{
    int i;
    int indexa;
    int indexb;
    
    if (s->lena < 2 || s->lenb < 2)
        return ;
    indexa = s->lena - 1;
    indexb = s->lena - 2;
    i = s->a[indexb];
    s->a[indexb] = s->a[indexa];
    s->a[indexa] = i;
    indexa = s->lenb - 1;
    indexb = s->lenb - 2;
    i = s->b[indexb];
    s->b[indexb] = s->b[indexa];
    s->b[indexa] = i;
    printf("ss\n");

}

void    pa(t_lst *s)
{
    if (s->lenb < 1)
        return ;
    s->a[s->lena] = s->b[s->lenb - 1];
    s->b[s->lenb - 1] = 0;
    s->lena++;
    s->lenb--;
    printf("pa\n");
}

void    pb(t_lst *s)
{
    if (s->lena < 1)
        return ;
    s->b[s->lenb] = s->a[s->lena - 1];
    s->a[s->lena - 1] = 0;
    s->lenb++;
    s->lena--;
    printf("pb\n");
}