/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_listes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 11:18:23 by tas               #+#    #+#             */
/*   Updated: 2022/10/05 16:25:46 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Dans le cas où argc = 2 (ex: "1 2 3")
// découpage de l'argv et attribution aux contents de la liste
t_list  **decomposer_arg(int argc, char **argv)
{
    char    **stockage;
    int     nb;
    int     i;
    t_list  *ptr;
    t_list  *start;
    t_list  **list_stack_a;

    list_stack_a = malloc(sizeof(t_list) * argc);
    if (!list_stack_a)
		return (NULL);
	i = 1;
    stockage = ft_split(argv[1], ' ');
    nb = ft_atoi(stockage[0]);
    start = ft_lstnew(nb);
    ft_lstadd_back(list_stack_a, start);
    start->premier = start;
    ptr = start->premier;
    while (stockage[i])
    {
        nb = ft_atoi(stockage[i]);
        start = ft_lstnew(nb);
        start->premier = ptr;
        ft_lstadd_back(list_stack_a, start);
        i++;
    }
    return (list_stack_a);
}

// donner chacun des arguments au content d'une liste
t_list  **attribution_arg(int argc, char **argv)
{
    int     i;
    int     nb;
    t_list  *ptr;
    t_list  *start;
    t_list  **list_stack_a;

    if (argc == 2)
        list_stack_a = decomposer_arg(argc, argv);
    else
    {
        list_stack_a = malloc(sizeof(t_list) * argc);
        if (!list_stack_a)
            return (NULL);
        i = 2;
        nb = ft_atoi(argv[1]);
        start = ft_lstnew(nb);
        ft_lstadd_back(list_stack_a, start);
        start->premier = start;
        ptr = start->premier;
        while (argc > 2)
        {
            nb = ft_atoi(argv[i]);
            start = ft_lstnew(nb);
            start->premier = ptr;
            ft_lstadd_back(list_stack_a, start);
            i++;
            argc--;
        }
    }
    return (list_stack_a);
}

