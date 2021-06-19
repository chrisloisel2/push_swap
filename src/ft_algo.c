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

int     look_for_order(t_stack *s)
{
    int i;

    i = 0;
    if (s->stackb != 0)
        return (1);
    while ((s->a[i] > s->a[i + 1]) && i < s->stacka)
        i++;
    if (i == s->stacka)
        return (0);
    return (1);
}

void    ft_look_organise(t_stack *s)
{
    printf("\n alog %d", s->stacka);
}

int     ft_organizer(t_stack *s)
{
    printf("\n alog %d", s->stacka);
    return (0);
}

void    ft_algo(t_stack *s)
{
    printf("\n alog %d", s->stacka);
//    while (look_for_order(s))
  //  {
    //    ft_organizer(s);
   // }
}