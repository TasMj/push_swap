/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_listes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 11:18:23 by tas               #+#    #+#             */
/*   Updated: 2022/08/03 16:35:31 by tmejri           ###   ########.fr       */
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
	int		size_char;
    t_list  *ptr;
    t_list  *start;
    t_list  **list_stack_a;

    list_stack_a = malloc(sizeof(t_list) * argc);
    if (!list_stack_a)
		return (NULL);
	i = 0;
    stockage = argv[1];
	size_char = ft_strlen(stockage);
    nb = 0;
    while (stockage[i])
    {
        nb = ft_atoi(stockage);
        printf("%d\n", nb);
        start = ft_lstnew(nb);
        ft_lstadd_back(list_stack_a, start);
        if (ft_strlen(stockage + i) == size_char)
        {
            start->premier = start;
            ptr = start->premier;
        }
        else
            start->premier = ptr;
        printf("add prem : %p\n", start->premier);
        i = size_nb(nb) + 1;
        stockage = ft_resize(stockage, i);
        i = 0;
    }
    return (list_stack_a);
}

// donner chacun des arguments au content d'une liste
void    *attribution_arg(int argc, char **argv)
{
    int     i;
    int     nb;
    t_list  *ptr;
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
        printf("%d\n", nb);
        ft_lstadd_back(list_stack_a, start);
        start->premier = start;
        ptr = start->premier;
        printf("\nadresse du premier : %p\n\n", (*list_stack_a)->premier);
        while (argc > 2)
        {
            nb = ft_atoi(argv[i]);
            printf("%d\n", nb);
            start = ft_lstnew(nb);
            start->premier = ptr;
            ft_lstadd_back(list_stack_a, start);
            i++;
            argc--;
        }
    }
    return (list_stack_a);
}

// #include <stdio.h>
// int main(int argc, char **argv)
// {
//     t_list  *list;
//     list = attribution_arg(argc, argv);
//     printf("%p\n", list);
//     return (0);
// }
