/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:09:56 by tmejri            #+#    #+#             */
/*   Updated: 2022/10/26 15:00:16 by tmejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// return le nb de block
int	size_block(t_list **list_a)
{
    int	size_list;
	
    size_list = ft_lstsize(*list_a);
    if (size_list <= 100)
		return (size_list / 5);
    else
		return (size_list / 10);
}

/* return le premier indice du block */
int block(int nb_of_block)
{
    if (nb_of_block == 1)
        return (0);
    else if (nb_of_block == 2)
        return (19);
    else if (nb_of_block == 3)
        return (39);
    else if (nb_of_block == 4)
        return (59);
    else if (nb_of_block == 5)
        return (79);
    else
        return (0);

}

// return 1 si l'indice est compris ds le block 0 sinon
int is_in_block(t_list **list, int nb_of_block)
{
    int min;
    int max;

    min = block(nb_of_block);
    max = min + 19;
    if ((*list)->index >= min && (*list)->index <= max)
        return (1);
    else
        return (0);
}

/* return la position d'en haut du premier elt du block rencontre */
int du_haut(t_list **list, int position)
{
    int c;
    t_list *tmp;

    c = 0;
    tmp = *list;
    while (*list)
    {
        if (is_in_block(list, position))
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
    return (0);
}

int ft_end(t_list **list, int position)
{
	while (*list && position)
	{
		(*list) = (*list)->next;
        position--;
	}
	return ((*list)->index);
}

/* return la position d'en bas du premier elt du block rencontre */
int du_bas(t_list **list, int position_from_top)
{
    int     c;
    int     index_last;
    t_list  *tmp;

    c = 0;
    tmp = *list;
    while (*list)
    {
        index_last = ft_end(list, position_from_top); 
        if (is_in_block(list, index_last) == 1)
        {
            *list = tmp;   
            return (c);
        }
        else
        {
            c++;
            position_from_top--;
            (*list) = (*list)->next;
        }
    }
    return (0);
}

