/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sort2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:09:56 by tmejri            #+#    #+#             */
/*   Updated: 2022/11/15 15:28:21 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* return la position d'en haut du premier elt du block rencontre */
// int du_haut(t_list **list, int numero_du_block, int size_one_block, int *b)
// {
    // int c;
    // t_list    *tmp;
// 
    // c = 0;
    // tmp = *list;
    // while (*list)
    // {
// 
    // while (!(is_in_block(*list, numero_du_block, size_one_block) == 1))
    // {
        // c++;
        // (*list) = (*list)->next;
    // }
    // if (is_in_block(*list, numero_du_block, size_one_block) == 1)
        // (*b) = (*list)->index;
    // }
    // *list = tmp;
    // return (c); //return autre car 0 peut etre une valeur de c
// }

int du_haut(t_list **list, int numero_du_block, int size_one_block, int *b)
{
    int c;
    t_list *tmp;

    c = 0;
    tmp = *list;
    while (*list)
    {
        if (is_in_block(*list, numero_du_block, size_one_block) == 1)
        {
            (*b) = (*list)->index;
            *list = tmp;
            return (c);
        }
        else
        {
            c++;
            (*list) = (*list)->next;
        }
    }
    return (-1); //return autre car 0 peut etre une valeur de c
}

/* return l'indice de l'elm a l'indice position */
void    ft_end(t_list **list, int size_list)
{
    while (size_list > 0)
    {
	    (*list) = (*list)->next;
        size_list--;
    }
}

/* return la position d'en bas du premier elt du block rencontre */
int du_bas(t_list **list, int numero_du_block, int size_one_block, int *a)
{
    int     c;
    int     size_list;
    t_list  *tmp;

    c = 0;
    tmp = *list;
    size_list = ft_lstsize(*list) - 1;
    while (*list)
    {
        ft_end(list, size_list);
        // printf("------------ %d\n", (*list)->index);
        if (is_in_block(*list, numero_du_block, size_one_block) == 1)
        {
            (*a) = (*list)->index;
            *list = tmp;
            return (c);
        }
        else
        {
            c++;
            size_list--;
            *list = tmp;
        }
    }
    *list = tmp;
    return (-1);
}
