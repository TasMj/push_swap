/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:44:40 by tas               #+#    #+#             */
/*   Updated: 2022/08/06 19:41:14 by tas              ###   ########.fr       */
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
    a = ft_print(a);
    printf("\n");
    printf("*****Stack B avant push*****\n");
    printf("\n");
    b = ft_print(b);
    printf("*****stack A apres push*****\n");
    *a = tmp;
    pa(b, a);
    pa(b, a);
    a = ft_print(a);
    printf("\n");
    printf("*****Stack B apres push*****\n");
    b = ft_print(b);
    return (0);
}
