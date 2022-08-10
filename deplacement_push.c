/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:44:40 by tas               #+#    #+#             */
/*   Updated: 2022/08/10 13:16:06 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push le first elt de b dans la stack A
// B ---> A
void    pa(t_list **list_stack_a, t_list **list_stack_b)
{
    if (list_stack_b)
    {
        ft_lstadd_front(list_stack_a, ft_lstnew((*list_stack_b)->content));
        *list_stack_b = (*list_stack_b)->next;
    }
}

// // push le first elt de a dans la stack B
// A ---> B
void    pb(t_list **list_stack_b, t_list **list_stack_a)
{
    if (list_stack_a)
    {
        ft_lstadd_front(list_stack_b, ft_lstnew((*list_stack_a)->content));
        *list_stack_a = (*list_stack_a)->next;
    }
}
