/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 02:12:07 by tas               #+#    #+#             */
/*   Updated: 2022/08/22 04:19:47 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap a et b si a > b, sinon renvoie la liste de départ
t_list  **sort_for_2(t_list **list)
{
    t_list  *nxt;

    nxt = (*list)->next;
    if ((*list)->content > nxt->content)
    {
        sa(list);
        write(1, "sa\n", 3);
    }
    return (list);
}

