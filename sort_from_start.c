/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_from_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:25:13 by tas               #+#    #+#             */
/*   Updated: 2022/11/24 23:57:12 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_start_top(t_list **list)
{
    int c;
    t_list  *tmp;

    c = 0;
    tmp = *list;
    while((*list)->index != 0)
    {
        (*list) = (*list)->next;
        c++;
    }
    *list = tmp;
    return (c);
}

int find_start_down(t_list **list)
{
    int c;
    int size;
    int size_block_down;
    t_list  *tmp;

    tmp = *list;
    size = middle_size(list);
	size_block_down = size;
    while (size)
    {
        (*list) = (*list)->next;
		size--;
    }
    c = find_start_top(list);
    *list = tmp;
    return (size_block_down - c);
}

void    order(t_list **list)
{
    int top;
    int down;
    int size;

	size = ft_lstsize(*list);
    top = find_start_top(list);
	if (size % 2 == 0)
		down = find_start_down(list);
	else
		down = find_start_down(list) - 1;
    if (top < down)
    {
        while (top > 0)
        {
            ra(list);
            top--;
        }
    }
    else
    {
        while (down > 0)
        {
            rra(list);
            down--;
        }
    }
}
