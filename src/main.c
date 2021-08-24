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

void    free_all(t_lst *s, t_stack *r)
{
    t_lst    *x;

    s = lstlast(s);
    x = NULL;
    while (s != NULL)
    {
        if (s->prev != NULL)
            x = s->prev;
        else
            x = NULL;
        free (s);
        s = NULL;
        s = x;
    }
    free(r->tl);
    r->tl = NULL;
    free(r->a);
    r->a = NULL;
    free(r->b);
    r->b = NULL;
    free(r);
    r = NULL;
}

int     ft_push_swap(int num, char **argv)
{
    t_lst *s;
    t_stack *r;

    s = lstnew();
    r = malloc(sizeof(t_stack));
   
    r->pa = 0;
    r->pb = 0;
    r->sa = 0;
    r->sb = 0;
    r->ss = 0;
    r->ra = 0;
    r->rb = 0;
    r->rr = 0;
    r->rra = 0;
    r->rrb = 0;
    r->rrr = 0;

    if (ft_recup(num, argv, s, r) == -1)
        return (-1);
    order(r->tl, r->lena, r->a);
    ft_algo(s, r);
    free_all(s, r);
    return (0);
}

int     main(int argc, char **argv)
{
    if (argc  < 2)
    {
        printf("ERROR ARG");
        return (0);
    }
    else
        ft_push_swap(argc, argv);
    return (0);
}
