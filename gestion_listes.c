/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_listes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 11:18:23 by tas               #+#    #+#             */
/*   Updated: 2022/07/28 14:37:11 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// donner chacun des arguments au content d'une liste
void    *attribution_arg(int argc, char *argv[])
{
    int     i;
    int     nb;
    t_list  *start;
    t_list  **list_stack_a;

    list_stack_a = malloc(sizeof(t_list) * argc);
    if (!list_stack_a)
        return (NULL);    
    i = 2;
    nb = ft_atoi(argv[1]);
    start = ft_lstnew(nb);
    ft_lstadd_back(list_stack_a, start);
    while (argc > 2)
    {
        free (start);
        nb = ft_atoi(argv[i]);
        printf("%d\n", nb);
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
    list = attribution_arg(argc, argv);
    printf("%p\n", list);
    return (0);
}
