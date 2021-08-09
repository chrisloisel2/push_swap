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

int    speed_push(t_stack *s)
{
    int i;

    i = 0;

    if ((i > 0) || (ft_check_order(s) != 1))
        return (0);
    return (1);
}

void    ft_smart_push(t_stack *s)
{
    int i;
    int milieu;

    i = s->stacka - 1;
    milieu = ft_milieu(s, 'a');
    while (s->stacka > ((i + 1) / 2) && speed_push(s))
    {
        while (s->a[s->stacka - 1] <= milieu && speed_push(s))
            pb(s);
        while (s->a[0] <= milieu && speed_push(s))
        {
            rra(s);
            pb(s);
        }
        while (s->a[s->stacka - 1] > milieu && s->stacka > ((i + 1) / 2) && speed_push(s))
            ra(s);
    }
}
