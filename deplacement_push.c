/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:44:40 by tas               #+#    #+#             */
/*   Updated: 2022/08/05 18:09:28 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push le first elt de b dans la stack A
// void    *pa(t_list **list_stack_a, t_list **list_stack_b)
// {
//     if (!list_stack_a || !list_stack_b)
//         return (NULL);
//     if ((*list_stack_b)->next == NULL)
//         return (NULL);
//     ft_lstadd_front(list_stack_a, (*list_stack_b));
//     return (list_stack_a);
//     // ft_lstdelone(list_stack_a, del_lst);
// }

// // push le first elt de a dans la stack B
// A ---> B
void    pb(t_list **list_stack_b, t_list **list_stack_a)
{
    // if (!list_stack_b || !list_stack_a)
    //     return (NULL);
//    t_list  *tmp;
    
    if (list_stack_a)
    {
        //tmp = *list_stack_a;
        
        ft_lstadd_front(list_stack_b, ft_lstnew((*list_stack_a)->content));
        *list_stack_a = (*list_stack_a)->next;
    }
    // (*list_stack_a) = (*list_stack_a)->next;
    // ft_lstadd_front(list_stack_b, (*list_stack_a)->premier);
    // (*list_stack_a)->premier = (*list_stack_a)->next;
}

#include <stdio.h>

int main(int argc, char **argv)
{
    t_list  **a;
    t_list  **b;
  
    b = malloc(sizeof(t_list));
    t_list *tmp;
  
    a = attribution_arg(argc, argv);
    tmp = *a;
    printf("*****stack A avant push*****\n");
    while (*a)
    {
 	    printf("content: %d\n", (*a)->content);
 	    (*a) = (*a)->next;
	}
    printf("\n");
    printf("*****Stack B avant push*****\n");
    while (*b)
    {
        printf("content: %d\n", (*b)->content);
        *b = (*b)->next;
    }
    printf("\n");
    printf("*****stack A apres push*****\n");
    *a = tmp;
    pb(b, a);
    while (*a)
    {
 	    printf("content: %d\n", (*a)->content);
 	    (*a) = (*a)->next;
	}
    printf("\n");
    printf("*****Stack B apres push*****\n");
    while (*b)
    {
        printf("content: %d\n", (*b)->content);
        *b = (*b)->next;
    }
    return (0);
}
