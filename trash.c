    /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:06:24 by tmejri            #+#    #+#             */
/*   Updated: 2022/08/06 19:39:00 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    *ft_print(t_list **list)
{
    while (*list)
    {
        printf("content: %d\n", (*list)->content);
        (*list) = (*list)->next;
    }
    return (list);
}

void    *ft_print_all(t_list **list)
{
    while (*list)
    {
        printf("content: %d\n", (*list)->content);
        printf("ADD: %p\n", (*list));
        printf("add_prem: %p\n", (*list)->premier);
        printf("add_next: %p\n\n", (*list)->next);
        (*list) = (*list)->next;
    }
    return (list);
}

//MAIN PUSH


// int main(int argc, char **argv)
// {
//     t_list  **a;
//     t_list  **b;
  
//     b = malloc(sizeof(t_list));
//     t_list *tmp;
  
//     a = attribution_arg(argc, argv);
//     tmp = *a;
//     printf("*****stack A avant push*****\n");
//     a = ft_print(a);
//     printf("\n");
//     printf("*****Stack B avant push*****\n");
//     printf("\n");
//     b = ft_print(b);
//     printf("*****stack A apres push*****\n");
//     *a = tmp;
//     pa(b, a);
//     pa(b, a);
//     a = ft_print(a);
//     printf("\n");
//     printf("*****Stack B apres push*****\n");
//     b = ft_print(b);
//     return (0);
// }

// MAIN ROTATE

// int main(int argc, char **argv)
// {
//     t_list  **a;
//     t_list  *tmp;

//     a = attribution_arg(argc, argv);
//     tmp = *a;
//     printf("*****Stack A avant rotate*****\n\n");
//     a = ft_print(a);
//     printf("\n*****stack A apres rotate*****\n\n");
//     *a = tmp;
//     rb(a);
//     a = ft_print_all(a);
//     return (0);
// }


// MAIN RRR

// int main(int argc, char **argv)
// {
    // t_list  **a;
    // // t_list  *tmp;

    // a = attribution_arg(argc, argv);
    // tmp = *a;
    // printf("*****Stack A avant rotate*****\n\n");
    // a = ft_print(a);
    // printf("\n*****stack A apres rotate*****\n\n");
    // *a = tmp;
    // rrb(a);
    // a = ft_print(a);
    // return (0);
// }