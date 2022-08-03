/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:44:40 by tas               #+#    #+#             */
/*   Updated: 2022/08/02 12:46:17 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push le first elt de b dans la stack A
void    *pa(t_list **list_stack_a, t_list **list_stack_b)
{
    if (!list_stack_a || !list_stack_b)
        return (NULL);
    if ((*list_stack_b)->next == NULL)
        return (NULL);
    ft_lstadd_front(list_stack_a, (*list_stack_b));
    return (list_stack_a);
    // ft_lstdelone(list_stack_a, del_lst);
}

// // push le first elt de badans la stack B
// void    pb(t_list **list_stack_b, t_list *first_elt_a)
// {
//     t_list  list_b;
    
//     list_stack_b = &list_b;    
//     if (!list_stack_b || !first_elt_a)
//         return (NULL);
//     if (list_b.next == NULL)
//         return (NULL);
//     ft_lstadd_front(list_stack_b, first_elt_a);
//     //suppr le premier elt
// }

#include <stdio.h>

int main()
{
    t_list  **ma_list;
    t_list  **ma_list2;
    
    ma_list = malloc(sizeof(t_list));
    ma_list2 = malloc(sizeof(t_list));
    
    (*ma_list) = (*ma_list)->premier;
    (*ma_list) = (*ma_list)->next;
    (*ma_list)->content = 2;
    (*ma_list) = (*ma_list)->next;
    (*ma_list)->content = 3;
    
    (*ma_list2)->content = 4;
    (*ma_list2) = (*ma_list2)->next;
    (*ma_list2)->content = 5;
    (*ma_list2) = (*ma_list2)->next;
    (*ma_list2)->content = 6;
    
    // ma_list = attribution_arg(argc, argv);
    printf("\n*************************\n");
    pa(ma_list, ma_list2);
    for (int i = 0; i < 3; i++)
	{
		printf("content: %d\n   %d\n", (*ma_list)->content, (*ma_list2)->content);
		(*ma_list) = (*ma_list)->next;
		(*ma_list2) = (*ma_list2)->next;
	}

    return (0);
}
