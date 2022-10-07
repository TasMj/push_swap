/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_hundread_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:41:27 by tmejri            #+#    #+#             */
/*   Updated: 2022/10/07 15:17:07 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// fonction qui pb tous les autres nombres jusqu'a ce qu'il n'en reste plus que 5 ds stack A
void    stack_to_5(t_list **list_a, t_list **list_b)
{
    int size_a;
    
    size_a = ft_lstsize((*list_a));
    while (size_a > 5)
    {
        pb(list_b, list_a);
        write(1, "pb\n", 3);
        size_a--;
    }
}

// trouver la mediane dans la stack actuelle
int find_mediane(t_list **list)
{
    int size;
    int mediane;

    size = ft_lstsize(*list);
	mediane = size / 2;
    (*list) = (*list)->premier;
    while (mediane > 0)
    {
        (*list) = (*list)->next;
        mediane--;
    }
    return ((*list)->index);
}

// bool qui renvoie 1 si le nb fait partie de la premiere partie
//                  2 si deuxieme partie
int up_or_down(t_list **list)
{
    int mediane;

    mediane = find_mediane(list);
    if ((*list)->index < mediane)
        return (1);
    else
        return (2);
}

//  EN FONCTION DE LA TAILLE DE LA STACK A

// si ce bool renvoie 1 : si   (a faire pour les 5 premier avec cette premiere partie)
//                     1) x < prem elt de la stack a on ne change rien
//                     2) x > on cherche entre quel nb et quel nb il est compris et on 
//                              ra x (l'indice du nb - 1) ou il doit se trouver
//                              sa
//                              rra x meme nb qu au dessus
// si ce bool renvoie 2 : 
//                     2) x < on cherche entre quel nb et quel nb il est compris et on 
//                              rra x (l'indice du nb - 1) ou il doit se trouver
//                              sa
//                              ra x meme nb qu au dessus
void    sort_in_stack_a(t_list **list_a, t_list **list_b)
{
    int t_index;
    int stock_index;

    t_index = 0;
    stock_index = 0;
    (*list_b) = (*list_b)->premier;
    if (up_or_down(list_a) == 1)
    {
        if ((*list_b)->index < (*list_a)->index)
        {
            pb(list_b, list_a);
            write (1, "pb\n", 3);
        }
        else
        {
            while ((*list_a)->index != mediane) //a voir
            {
                (*list_a) = (*list_a)->next;
                stock_index++;
            }
            t_index = stock_index;
            while (stock_index > 0)
            {
                ra(list_a);
                write(1, "ra\n", 3);
                stock_index--;
            }
            sa(list_a);
            write(1, "sa\n", 3);
            while (t_index > 0)
            {
                rra(list_a);
                write(1, "rra\n", 3);
                t_index--;
            }

            
        }
    }
    else if (up_or_down(list_a) == 2)
    {
        
    }
}


int main(int argc, char **argv)
{
    t_list  **list_a;
    t_list  **list_b;
    int    *tab;

    list_a = attribution_arg(argc,argv);
    tab = tab_to_sort(list_a);
	tab = tab_sorted(tab, argc);
	list_b = NULL;
	index_tab(list_a, tab);
	list_b = seperate_by_mediane(list_a, list_b);
    stack_to_5(list_a, list_b);
    sort_for_5(list_a, list_b);
    printf("\n\nstack a\n\n");
    ft_print(list_a);
    printf("\n\nstack b\n\n");
    ft_print(list_b);
}

