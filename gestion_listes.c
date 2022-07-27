/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_listes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 11:18:23 by tas               #+#    #+#             */
/*   Updated: 2022/07/25 17:33:06 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// donner chacun des arguments au content d'une liste
void    *attribution_arg(int argc, char *argv[])
{
    int     i;
    void    *nb;
    t_list  *start;
    t_list  **list_stack_a;

    printf("ca\n");
    list_stack_a = malloc(sizeof(t_list) * argc);
    if (!list_stack_a)
        return (NULL);    
    printf("rentre\n");
    i = 2;
    nb = argv[1];
    printf("ici\n");
    start = ft_lstnew(nb);
    printf("aussi\n");
    ft_lstadd_back(list_stack_a, start);
    printf("mais\n");
    while (argc > 1)
    {
        printf("wsh\n");
        ft_lstdelone(start, );
        printf("queeeeeeeeeeeeel\n");
        nb = argv[i];
        start = ft_lstnew(nb);
        ft_lstadd_back(list_stack_a, start);
        i++;
        argc--;
    }
    return (list_stack_a);
}

#include <stdio.h>
int main(int argc, char **argv)
{
    t_list  *list;
    printf("1\n");
    list = attribution_arg(argc, argv);
    printf("2\n");
    while (list)
    {
        printf("3\n");
        printf("%p\n", list->content);
        list = list->next;       
    }
    return (0);
}
