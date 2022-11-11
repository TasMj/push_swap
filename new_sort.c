/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:09:56 by tmejri            #+#    #+#             */
/*   Updated: 2022/11/11 18:08:53 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* return le premier indice du block */
int block(int nb_of_block, int size_one_block)
{
    if (nb_of_block == 1)
        return (0);
    else if (nb_of_block == 2)
        return (size_one_block);
    else if (nb_of_block == 3)
        return (2 * size_one_block);
    else if (nb_of_block == 4)
        return (3 *size_one_block);
    else if (nb_of_block == 5)
        return (4 * size_one_block);
    else
        return (0);
}

// return 1 si l'indice est compris ds le block 0 sinon
int is_in_block(t_list **list, int num_of_block, int size_one_block)
{
    int min;
    int max;

    min = block(num_of_block, size_one_block);
    max = min + size_one_block - 1;
    if ((*list)->index >= min && (*list)->index <= max)
        return (1);
    else
        return (0);
}

/* return la position d'en haut du premier elt du block rencontre */
int du_haut(t_list **list, int position, int size_one_block)
{
    int c;
    t_list *tmp;

    c = 0;
    tmp = *list;
    while (*list)
    {
        if (is_in_block(list, position, size_one_block) == 1)
        {
            *list = tmp;
            return (c);
        }
        else
        {
            c++;
            (*list) = (*list)->next;
        }
    }
    return (0); //return autre car 0 peut etre une valeur de c
}

/* return l'indice de l'elm a l'indice position */
int ft_end(t_list **list, int position)
{
    while (position)
    {
	    (*list) = (*list)->next;
        position--;
    }
    return ((*list)->index);
}

/* return la position d'en bas du premier elt du block rencontre */
int du_bas(t_list **list, int size_one_block)
{
    int     c;
    int     index_last;
    int     size_list;
    t_list  *tmp;

    c = 0;
    tmp = *list;
    size_list = ft_lstsize(*list) - 1;
    while (*list)
    {
        index_last = ft_end(list, size_list);
        // printf("LAST INDEX: %d\n", index_last);
        if (is_in_block(list, index_last, size_one_block) == 1)
        {
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
    // *list = tmp; 
    return (c);
}

