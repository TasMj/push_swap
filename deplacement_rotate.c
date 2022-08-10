/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:16:22 by tas               #+#    #+#             */
/*   Updated: 2022/08/10 13:15:29 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// décale de 1 toute la stack a
// le premier devient le dernier
t_list    **ra(t_list **list_stack_a)
{
    t_list  *tmp;
    t_list  *last;

    last = ft_lstnew((*list_stack_a)->content);
    (*list_stack_a) = (*list_stack_a)->next;
    (*list_stack_a)->premier = (*list_stack_a);
    tmp = (*list_stack_a);
    last->premier = tmp;    
    while ((*list_stack_a)->next != NULL)
    {
        (*list_stack_a)->premier = tmp;
        (*list_stack_a) = (*list_stack_a)->next;
    }
    (*list_stack_a)->premier = tmp;
    (*list_stack_a)->next = last;
    (*list_stack_a) = (*list_stack_a)->premier;
    return (list_stack_a);
}
// décale de 1 toute la stack b
// le premier devient le dernier
t_list    **rb(t_list **list_stack_b)
{
    t_list  *tmp;
    t_list  *last;

    last = ft_lstnew((*list_stack_b)->content);
    (*list_stack_b) = (*list_stack_b)->next;
    (*list_stack_b)->premier = (*list_stack_b);
    tmp = (*list_stack_b);
    last->premier = tmp;    
    while ((*list_stack_b)->next != NULL)
    {
        (*list_stack_b)->premier = tmp;
        (*list_stack_b) = (*list_stack_b)->next;
    }
    (*list_stack_b)->premier = tmp;
    (*list_stack_b)->next = last;
    (*list_stack_b) = (*list_stack_b)->premier;
    return (list_stack_b);
}

// // décale de 1 pour stack a et stack b
// void    rr(t_list *list_stack_a, t_list *list_stack_b)
// {
//     if (!list_stack_a || !list_stack_b)
//         return (NULL);
//     if (list_stack_a->next == NULL || list_stack_b->next == NULL);
//         return (NULL);
//     ra(list_stack_a);
//     rb(list_stack_b);
// }

#include <stdio.h>

int main(int argc, char **argv)
{
    t_list  **a;
    t_list  *tmp;

    a = attribution_arg(argc, argv);
    tmp = *a;
    printf("*****Stack A avant rotate*****\n\n");
    a = ft_print(a);
    printf("\n*****stack A apres rotate*****\n\n");
    *a = tmp;
    rb(a);
    a = ft_print_all(a);
    return (0);
}

