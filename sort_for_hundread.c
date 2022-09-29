/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_hundread.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:20:18 by tmejri            #+#    #+#             */
/*   Updated: 2022/09/29 18:17:43 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

// //trouver le nb le plus long de la liste pour savoir cb de fois on va diviser
// // faire attention au signe moins
// int find_biggest(t_list **list)
// {
//     int c;
//     int stockage;
    
//     while ((*list)->next != NULL)
//     {
//         if ((*list)->content > (*list)->next->content)
//             stockage = (*list)->content;
//         else
//             stockage = (*list)->next->content;
//         (*list) = (*list)->next;
//     }
//     c = size_nb(stockage);
//     return (c);
// }



// 43          
// 809876      9
// 45          5
// 567         4

// PA          PB

// ra ra 



// //regrouper les nb ayant le meme nb de chiffre ensemble

// //les diviser en groupe de 10 et les trier


// 453
// 52
// 5
// 5596
// 0
// 75

// 453 52 5 5596 0 75
// 75 453 52 5 5596 0        
// 5596                    453 75 0 5 52
// 5596                    52 453 75 0 5


// rra 
// stocker rra
// if content plus petit on pb sinon ra
// rra pa si plus grand aue content



// DANS L ALGO 
// faire une bouce de n, n etant le nombre de chiffre du nb le pls long - 1


// pa pb ra