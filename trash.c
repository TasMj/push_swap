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
