/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:49:44 by tas               #+#    #+#             */
/*   Updated: 2022/08/02 12:23:23 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_list **list)
{
    t_list  *tmp;
    t_list  *tmp2;

    tmp = ft_lstnew((*list)->content); //on stock le premier nombre ds une tmp   
	(*list) = (*list)->next;
    tmp2 = ft_lstnew((*list)->content); // on stock le 2eme nb dans tmp2
    (*list)->content = tmp->content; // on donne au 2eme elt de la liste la valeur de tmp (1er elt)
    (*list) = (*list)->premier; //retour au debut de la liste (enfin je crois)
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

// swap les 2 premiers elts du haut de la stack B
void    *sb(t_list **list_stack_b)
{
    if (!list_stack_b)
        return (NULL);
    if ((*list_stack_b)->next == NULL)
        return (NULL);
    swap(list_stack_b);
    return (list_stack_b);
}

// // swap les 2 premiers elts du haut des stacks A et B
void    ss(t_list **list_stack_a, t_list **list_stack_b)
{
    // if (!list_stack_a || !list_stack_b)
    //     return (NULL);
    // if ((*list_stack_a)->next == NULL || (*list_stack_b)->next == NULL)
    //     return (NULL);
    sa(list_stack_a);
    sb(list_stack_b);
}

#include <stdio.h>

int main(int argc, char **argv)
{
    t_list  **ma_list;
    

    ma_list = attribution_arg(argc, argv);
    printf("\n*************************\n");
    sa(ma_list);
    for (int i = 0; i < 3; i++)
	{
		printf("content: %d\n", (*ma_list)->content);
		(*ma_list) = (*ma_list)->next;
	}

    return (0);
}

// int main(int argc, char **argv)
// {
//     t_list  **ma_list;
//     t_list  **ma_list2;
    

//     ma_list = attribution_arg(argc, argv);
//     ma_list2 = attribution_arg(argc, argv);
//     // for (int i = 0; i < 3; i++)
// 	// {
// 	// 	printf("content: %d\n", (*ma_list)->content);
// 	// 	(*ma_list) = (*ma_list)->next;
// 	// }
//     printf("*************************\n");
//     ss(ma_list, ma_list2);
//     for (int i = 0; i < 3; i++)
// 	{
// 		printf("content: %d   %d\n", (*ma_list)->content, (*ma_list2)->content);
// 		(*ma_list) = (*ma_list)->next;
// 		(*ma_list2) = (*ma_list2)->next;
// 	}

//     return (0);
// }
