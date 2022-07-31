/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:16:22 by tas               #+#    #+#             */
/*   Updated: 2022/07/31 17:16:55 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// décale de 1 toute la stack a
// le premier devient le dernier
void    *ra(t_list *list_stack_a)
{
    t_list  *adress_beg;
    
    if (!list_stack_a)
        return (NULL);
    if (list_stack_a->next == NULL);
        return (NULL);
    adress_beg = &list_stack_a;
    while (list_stack_a)
        list_stack_a = list_stack_a->next;
    list_stack_a->next = adress_beg->next;
    adress_beg->next = NULL;
    return (list_stack_a);    
}

// décale de 1 toute la stack b
// le premier devient le dernier
void    *rb(t_list *list_stack_b)
{
    t_list  *adress_beg;
    
    if (!list_stack_b)
        return (NULL);
    if (list_stack_b->next == NULL);
        return (NULL);
    adress_beg = &list_stack_b;
    while (list_stack_b)
        list_stack_b = list_stack_b->next;
    list_stack_b->next = adress_beg->next;
    adress_beg->next = NULL;
    return (list_stack_b);    
}

// décale de 1 pour stack a et stack b
void    rr(t_list *list_stack_a, t_list *list_stack_b)
{
    if (!list_stack_a || !list_stack_b)
        return (NULL);
    if (list_stack_a->next == NULL || list_stack_b->next == NULL);
        return (NULL);
    ra(list_stack_a);
    rb(list_stack_b);
}
