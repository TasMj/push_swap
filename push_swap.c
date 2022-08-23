/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:28:11 by tmejri            #+#    #+#             */
/*   Updated: 2022/08/22 04:21:13 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// //recupere la liste d'int (stack a) prealablement faite pour la trier
void *push_swap(int argc, char **argv)
{
    t_list  **list;
    
    if (check_int(argc, argv) != 0)
        write(2, "Error\n", 6);
    else
    {
        list = attribution_arg(argc, argv);
        if (check_doublon(list) != 0)
            write(2, "Error\n", 6);
        if (argc < 3)
        {
            list = sort_for_2(list); // voir pq sa ne s'affiche pas
            printf("d");
        }
        // if (argc < 4)
        // {
            
        // }
        // if (argc < 5)
        // {
            
        // }
        // if (argc < 100)
        // {
            
        // }
        // if (argc > 500)
        // {
            
        // }
    }
    return (0);
}


// int main(int argc, char **argv)
// {
//     push_swap(argc, argv);
// }




// #include <stdlib.h>
// int main ()
// {

// }