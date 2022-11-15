/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:09:56 by tmejri            #+#    #+#             */
/*   Updated: 2022/11/14 15:52:18 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* return le premier indice du block */
int block(int numero_du_block, int size_one_block)
{
    if (numero_du_block == 1)
        return (0);
    else if (numero_du_block == 2)
        return (size_one_block);
    else if (numero_du_block == 3)
        return (2 * size_one_block);
    else if (numero_du_block == 4)
        return (3 *size_one_block);
    else if (numero_du_block == 5)
        return (4 * size_one_block);
    else
        return (0);
}

// return 1 si l'indice est compris ds le block 0 sinon
int is_in_block(t_list *list, int numero_du_block, int size_one_block)
{
    int min;
    int max;

    min = block(numero_du_block, size_one_block);
    max = min + size_one_block - 1;
    // printf("%d <= x <= %d\n", min, max);
    if (list->index >= min && list->index <= max)
        return (1);
    else
        return (0);
}

/* return la position d'en haut du premier elt du block rencontre */
int du_haut(t_list **list, int numero_du_block, int size_one_block, int *b)
{
    int c;
    t_list *tmp;

    c = 0;
    tmp = *list;
    printf("num du block: %d\n", numero_du_block);
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
    return (c); //return autre car 0 peut etre une valeur de c
}

/* return l'indice de l'elm a l'indice position */
void    ft_end(t_list **list, int size_list)
{
    while (size_list > 1)
    {
	    (*list) = (*list)->next;
        size_list--;
    }
    // return (*list);
}

/* return la position d'en bas du premier elt du block rencontre */
int du_bas(t_list **list, int size_one_block, int numero_du_block, int *a)
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
        printf("------------ %d\n", (*list)->index);
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
    return (c);
}
