/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 02:12:07 by tas               #+#    #+#             */
/*   Updated: 2022/08/23 16:18:50 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap a et b si a > b, sinon renvoie la liste de départ
t_list  **sort_for_2(t_list **list)
{
    (*list) = (*list)->premier;
    if ((*list)->content > (*list)->next->content)
    {
        sa(list);
        write(1, "sa\n", 3);
    }
    return (list);
}

