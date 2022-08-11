/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement_rotate2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:20:54 by tas               #+#    #+#             */
/*   Updated: 2022/08/11 12:50:52 by tmejri           ###   ########.fr       */
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
    pa(b, a);
    pa(b, a);
    rrr(b, a);
    a = ft_print(a);
    printf("\n");
    printf("*****Stack B apres push*****\n");
    b = ft_print(b);
    return (0);
}