/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:49:44 by tas               #+#    #+#             */
/*   Updated: 2022/07/29 14:57:29 by tmejri           ###   ########.fr       */
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
    swap(list_stack_a);
    return (list_stack_a);
}

#include <stdio.h>

int main(int argc, char **argv)
{
    t_list  *ma_list;
    t_list  *adress;

    adress = &ma_list;
    ma_list = attribution_arg(argc, argv);
    ma_list = sa(ma_list);
    while (ma_list)
    {
        printf("%d\n", ma_list->content);
    }
    return (adress);
}



// // swap les 2 premiers elts du haut de la stack B
// void    sb(int a, int b)

// // swap les 2 premiers elts du haut des stacks A et B
// void    ss()

// ***** OU ALORS ******

// void    swap(t_list stack) // marche pour A et B

