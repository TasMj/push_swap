/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:28:11 by tmejri            #+#    #+#             */
/*   Updated: 2022/08/23 17:20:45 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// //recupere la liste d'int (stack a) prealablement faite pour la trier
void *push_swap(int argc, char **argv)
{
    t_list  **list;
    
    if (check_int(argc, argv) != 0)
    {
        write(2, "Error\n", 6);
        return (NULL);
    }
    else
    {
        list = attribution_arg(argc, argv);
        if (check_doublon(list) != 0)
        {
            write(2, "Error\n", 6);
            return (NULL);
        }
        if (argc < 4)
        {
            list = sort_for_2(list);
        }
        else if (argc < 100)
        {
            // list = ft_bubble_sort(list);
            list = ft_radix(list);
        }
        else if (argc > 100)
        {
            list = ft_radix(list);
        }
    }
    return (list);
}


int main(int argc, char **argv)
{
    push_swap(argc, argv);
}




// #include <stdlib.h>
// int main ()
// {

// }