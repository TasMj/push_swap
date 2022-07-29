/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_listes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 11:18:23 by tas               #+#    #+#             */
/*   Updated: 2022/07/28 15:46:37 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// Dans le cas où argc = 2 (ex: "1 2 3")
// découpage de l'argv et attribution aux contents de la liste
void    *decomposer_arg(int argc, char **argv)
{
    char    *stockage;
    int     nb;
    int     i;
    t_list  *start;
    t_list  **list_stack_a;

    list_stack_a = malloc(sizeof(t_list) * argc);
    if (!list_stack_a)
        return (NULL);
    i = 0;    
    stockage = argv[1];
    nb = 0;
    while (stockage[i])
    {
        nb = ft_atoi(stockage);
        i = size_nb(nb) + 1;
        start = ft_lstnew(nb);
        ft_lstadd_back(list_stack_a, start);
        stockage = ft_resize(stockage, i);
        free (start);
    }
    return (list_stack_a);
}

// donner chacun des arguments au content d'une liste
void    *attribution_arg(int argc, char *argv[])
{
    int     i;
    int     nb;
    t_list  *start;
    t_list  **list_stack_a;

    if (argc == 2)
    {
        decomposer_arg(argc, argv);
    }
    else
    {
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
            start = ft_lstnew(nb);
            ft_lstadd_back(list_stack_a, start);
            i++;
            argc--;
        }
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
