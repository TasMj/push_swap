/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:44:40 by tas               #+#    #+#             */
/*   Updated: 2022/07/31 17:16:07 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push le first elt de b dans la stack A
void    pa(t_list **list_stack_a, t_list *first_elt_b)
{
    t_list  list_a;
    
    list_stack_a = &list_a;    
    if (!list_stack_a || !first_elt_b)
        return (NULL);
    if (list_a.next == NULL);
        return (NULL);
    ft_lstadd_front(list_stack_a, first_elt_b);
    // ft_lstdelone(list_stack_a, del_lst);
}

// push le first elt de badans la stack B
void    pb(t_list **list_stack_b, t_list *first_elt_a)
{
    t_list  list_b;
    
    list_stack_b = &list_b;    
    if (!list_stack_b || !first_elt_a)
        return (NULL);
    if (list_b.next == NULL);
        return (NULL);
    ft_lstadd_front(list_stack_b, first_elt_a);
    //suppr le premier elt
}


