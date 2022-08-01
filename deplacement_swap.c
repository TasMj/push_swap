/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:49:44 by tas               #+#    #+#             */
/*   Updated: 2022/08/01 16:57:08 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//fonction pour swap des content de 2 listes
// 
// void ft_swap(int *a, int *b)
// {
    // int *c;
    // 
    // c = a;
    // a = b;
    // b = c;
// }
// 

void swap(t_list **list)
{
    t_list  *tmp;
    t_list  *tmp2;
    t_list  **start;
    // ft_swap(list->content, list->next->content)
    start = list;
    tmp = ft_lstnew((*list)->content); //on stock le premier nombre ds une tmp   
	(*list) = (*list)->next;
    tmp2 = ft_lstnew((*list)->content); // on stock le 2eme nb dans tmp2
    (*list)->content = tmp->content; // on donne au 2eme elt de la liste la valeur de tmp (1er elt)
    (*list) = (*start); //retour au debut de la liste (enfin je crois)
    (*list)->content = tmp2->content; // on donne au 1er elt de la liste la valeur de tmp2 (2er elt)
}

// swap les 2 premiers elts du haut de la stack A
void    *sa(t_list **list_stack_a)
{
    if (!list_stack_a)
        return (NULL);
    if ((*list_stack_a)->next == NULL)
        return (NULL);
    swap(list_stack_a);
    return (list_stack_a);
}

// // swap les 2 premiers elts du haut de la stack B
// void    *sb(t_list *list_stack_b)
// {
//     if (!list_stack_b)
//         return (NULL);
//     if (list_stack_b->next == NULL);
//         return (NULL);
//     swap(list_stack_b);
//     return (list_stack_b);
// }

// // // swap les 2 premiers elts du haut des stacks A et B
// void    ss(t_list *list_stack_a, t_list *list_stack_b)
// {
//     if (!list_stack_a || !list_stack_b)
//         return (NULL);
//     if (list_stack_a->next == NULL || list_stack_b->next == NULL);
//         return (NULL);
//     sa(list_stack_a);
//     sb(list_stack_b);
// }

// #include <stdio.h>

// int main(int argc, char **argv)
// {
//     t_list  **ma_list;
//     t_list  **adress;
//     int i;

//     i = 3;
//     adress = ma_list;
//     ma_list = attribution_arg(argc, argv);
//     printf("%p\n\n\n", ma_list);
  
//     (*ma_list) = (*adress); 
//     sa(ma_list);
//     printf("%d\n", (*ma_list)->content);
    
//     while (i <= 0)
//     {
//         (*ma_list) = (*ma_list)->next;
//         printf("%d\n", (*ma_list)->content);
//         i--;
//     }
//     printf("%p\n", ma_list);
//     return (0);
// }
