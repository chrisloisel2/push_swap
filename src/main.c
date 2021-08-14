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

int     ft_push_swap(int num, char **argv)
{
    t_lst *s;
    t_stack *r;

    s = lstnew();
    r = malloc(sizeof(t_stack));
    if (ft_recup(num, argv, s, r) == -1)
        return (-1);
    order(s->tl, r->lena, r->a);
    ft_algo(s, r);
    free(r->a);
    free(r->b);
    free(s->tl);
    free(s);
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
