/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement_rotate2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:20:54 by tas               #+#    #+#             */
/*   Updated: 2022/08/11 12:52:27 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// décale de 1 toute la stack a
// le dernier elt devient le premier
t_list    **rra(t_list **list_stack_a)
{
    t_list  *last;
    t_list  *first;
    t_list  *tmp;

    first = malloc(sizeof(t_list));
    first = (*list_stack_a);
    last = malloc(sizeof(t_list));
    last = ft_lstlast(*list_stack_a);
    tmp = last;
    last->premier = tmp;
    first->premier = tmp;
    last->next = first;
    while ((*list_stack_a)->next != last)
    {
        (*list_stack_a)->premier = tmp;
        (*list_stack_a) = (*list_stack_a)->next;
    }
    
    (*list_stack_a)->next = NULL;
    (*list_stack_a) = last;
    return (list_stack_a);
}

// // décale de 1 toute la stack b
// // le dernier elt devient le premier
t_list    **rrb(t_list **list_stack_b)
{
    t_list  *last;
    t_list  *first;
    t_list  *tmp;

    first = malloc(sizeof(t_list));
    first = (*list_stack_b);
    last = malloc(sizeof(t_list));
    last = ft_lstlast(*list_stack_b);
    tmp = last;
    last->premier = tmp;
    first->premier = tmp;
    last->next = first;
    while ((*list_stack_b)->next != last)
    {
        (*list_stack_b)->premier = tmp;
        (*list_stack_b) = (*list_stack_b)->next;
    }
    
    (*list_stack_b)->next = NULL;
    (*list_stack_b) = last;
    return (list_stack_b);
}

// // décale de 1 toutes les stack a & b
// // le dernier elt devient le premier
void    rrr(t_list **list_stack_a, t_list **list_stack_b)
{
    rra(list_stack_a);
    rrb(list_stack_b);
}
