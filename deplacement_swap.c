/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:49:44 by tas               #+#    #+#             */
/*   Updated: 2022/07/31 17:14:22 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//fonction pour swap des content de 2 listes

void  swap(t_list *list)
{
    t_list  *tmp;
    t_list  *tmp2;
    void    *adress;
    
    adress = &list;
    tmp = ft_lstnew(list->content); //on stock le premier nombre ds une tmp   
	list = list->next;
    tmp2 = ft_lstnew(list->content); // on stock le 2eme nb dans tmp2
    list->content = tmp->content; // on donne au 2eme elt de la liste la valeur de tmp (1er elt)
    list = adress; //retour au debut de la liste (enfin je crois)
    list->content = tmp2->content; // on donne au 1er elt de la liste la valeur de tmp2 (2er elt)
	list = list->next;
}

// swap les 2 premiers elts du haut de la stack A
void    *sa(t_list *list_stack_a)
{
    if (!list_stack_a)
        return (NULL);
    if (list_stack_a->next == NULL);
        return (NULL);
    swap(list_stack_a);
    return (list_stack_a);
}

// swap les 2 premiers elts du haut de la stack B
void    *sb(t_list *list_stack_b)
{
    if (!list_stack_b)
        return (NULL);
    if (list_stack_b->next == NULL);
        return (NULL);
    swap(list_stack_b);
    return (list_stack_b);
}

// // swap les 2 premiers elts du haut des stacks A et B
void    ss(t_list *list_stack_a, t_list *list_stack_b)
{
    if (!list_stack_a || !list_stack_b)
        return (NULL);
    if (list_stack_a->next == NULL || list_stack_b->next == NULL);
        return (NULL);
    sa(list_stack_a);
    sb(list_stack_b);
}

#include <stdio.h>

int main(int argc, char **argv)
{
    t_list  **ma_list;
    void    *list;
    // t_list  *list;

    list = &ma_list;
    printf("%p\n", ma_list);
    ma_list = attribution_arg(argc, argv);
    // sa(ma_list);
    // while (ma_list)
    // {
    //     printf("%d\n", ma_list->content);
    //     ma_list = ma_list->next;
    // }
    // // printf("%p\n", *ma_list);
    printf("%p\n", ma_list);
    return (0);
}
