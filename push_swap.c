/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:28:11 by tmejri            #+#    #+#             */
/*   Updated: 2022/09/29 17:28:01 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// //recupere la liste d'int (stack a) prealablement faite pour la trier
void push_swap(int argc, char **argv)
{
    t_list  **list;
    t_list  **list_b;
    
    list_b = malloc(sizeof(t_list));
    if (check_int(argc, argv) != 0)
    {
        write(2, "Error\n", 6);
        free (list_b);
        return;
    }
    else
    {
        list = attribution_arg(argc, argv);
        if (check_doublon(list) != 0)
        {
            write(2, "Error\n", 6);
        }
        else if (argc < 4)
           sort_for_2(list);
        else if (argc < 5)
            sort_for_3(list);
        else if (argc < 7) 
            sort_for_5(list, list_b);
        // else if (argc < 101)
        // {
        //     list = ft_bubble_sort(list);
        // }
        // else if (argc > 100)
        //     list = ft_radix(list);
    }
}

// int main(int argc, char **argv)
// {
    // push_swap(argc, argv);
// }
