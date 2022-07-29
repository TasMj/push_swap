/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:49:44 by tas               #+#    #+#             */
/*   Updated: 2022/07/29 13:22:27 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//fonction pour swap des content de 2 listes

void    *swap(t_list *list)
{
    t_list *tmp;

    tmp = malloc(sizeof(t_list));
    if (!tmp)
        return (0);
	list = list->next;
       
    tmp->content = list->content;

        
        list_stack_a = list_stack_a->next;
        tmp2->content = copy_content(list_stack_a);
}

// swap les 2 premiers elts du haut de la stack A
void    sa()
{
    
}









// // swap les 2 premiers elts du haut de la stack B
// void    sb(int a, int b)

// // swap les 2 premiers elts du haut des stacks A et B
// void    ss()

// ***** OU ALORS ******

// void    swap(t_list stack) // marche pour A et B

