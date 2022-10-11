/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:16:22 by tas               #+#    #+#             */
/*   Updated: 2022/10/11 15:04:07 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* décale de 1 toute la stack a
le premier elt devient le dernier */
t_list    **ra(t_list **list_stack_a)
{
    t_list  *tmp;
    t_list  *last;
    int stock_last;

    stock_last = (*list_stack_a)->index;
    last = ft_lstnew((*list_stack_a)->content);
    (*list_stack_a) = (*list_stack_a)->next;
    (*list_stack_a)->premier = (*list_stack_a);
    tmp = (*list_stack_a);
    last->premier = tmp;
    last->index = stock_last;
    while ((*list_stack_a)->next != NULL)
    {
        (*list_stack_a)->premier = tmp;
        (*list_stack_a) = (*list_stack_a)->next;
    }
    (*list_stack_a)->premier = tmp;
    (*list_stack_a)->next = last;
    (*list_stack_a) = (*list_stack_a)->premier;
	write(1, "ra\n", 3);
    return (list_stack_a);
}

/* décale de 1 toute la stack b
le premier elt devient le dernier */
t_list    **rb(t_list **list_stack_b)
{
    t_list  *tmp;
    t_list  *last;
    int stock_last;

    stock_last = (*list_stack_b)->index;
    last = ft_lstnew((*list_stack_b)->content);
    (*list_stack_b) = (*list_stack_b)->next;
    (*list_stack_b)->premier = (*list_stack_b);
    tmp = (*list_stack_b);
    last->premier = tmp;    
    last->index = stock_last;
    while ((*list_stack_b)->next != NULL)
    {
        (*list_stack_b)->premier = tmp;
        (*list_stack_b) = (*list_stack_b)->next;
    }
    (*list_stack_b)->premier = tmp;
    (*list_stack_b)->next = last;
    (*list_stack_b) = (*list_stack_b)->premier;
	write(1, "rb\n", 3);
    return (list_stack_b);
}

/* décale de 1 les elts des stacks a et stack b 
les premiers deviennent les derniers */
void    rr(t_list **list_stack_a, t_list **list_stack_b)
{
    ra(list_stack_a);
    rb(list_stack_b);
	write(1, "rr\n", 3);
}
