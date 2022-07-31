/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement_rotate2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:20:54 by tas               #+#    #+#             */
/*   Updated: 2022/07/31 17:37:54 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// décale de 1 toute la stack a
// le dernier elt devient le premier
void    *rra(t_list *list_stack_a)
{
    t_list  *adress_beg;
    int     nb_elt;
    
    if (!list_stack_a)
        return (NULL);
    if (list_stack_a->next == NULL);
        return (NULL);
    adress_beg = &list_stack_a;
    nb_elt = ft_lstsize(list_stack_a);
    while (list_stack_a)
        list_stack_a = list_stack_a->next;
    list_stack_a->next = adress_beg->next;
    list_stack_a = adress_beg;
    while (nb_elt >= 1)
    {
        list_stack_a = list_stack_a->next;
        nb_elt--;
    } 
    list_stack_a->next = NULL;
    return (list_stack_a);    
}

// décale de 1 toute la stack b
// le dernier elt devient le premier
void    *rrb(t_list *list_stack_b)
{
    t_list  *adress_beg;
    int     nb_elt;
    
    if (!list_stack_b)
        return (NULL);
    if (list_stack_b->next == NULL);
        return (NULL);
    adress_beg = &list_stack_b;
    nb_elt = ft_lstsize(list_stack_b);
    while (list_stack_b)
        list_stack_b = list_stack_b->next;
    list_stack_b->next = adress_beg->next;
    list_stack_b = adress_beg;
    while (nb_elt >= 1)
    {
        list_stack_b = list_stack_b->next;
        nb_elt--;
    } 
    list_stack_b->next = NULL;
    return (list_stack_b);    
}

// décale de 1 toutes les stack a & b
// le dernier elt devient le premier
void    rrr(t_list *list_stack_a, t_list *list_stack_b)
{
    if (!list_stack_a || !list_stack_b)
        return (NULL);
    if (list_stack_a->next == NULL || list_stack_b->next == NULL);
        return (NULL);
    rra(list_stack_a);
    rrb(list_stack_b);
}
