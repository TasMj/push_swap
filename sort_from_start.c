/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_from_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tas <tas@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:25:13 by tas               #+#    #+#             */
/*   Updated: 2022/11/25 11:35:35 by tas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_start_top(t_list **list)
{
    int c;
    int size;    
    t_list  *tmp;

    c = 0;
    tmp = *list;
    size = ft_lstsize(*list) / 2;
    while(size)
    {
        if ((*list)->index == 0)
        {
            *list = tmp;
            return (c);
        }
        else
        {
            (*list) = (*list)->next;
            c++;
            size--;
        }
    }
    *list = tmp;
    return (-1);
}

int find_start_down(t_list **list)
{
    int c;
    int size_a;
    int size_block_down;
    int save_size_block_down;
    t_list  *tmp;

    c = 0;
    tmp = *list;
    size_a = ft_lstsize(*list) / 2;
    size_block_down = middle_size(list);
    save_size_block_down = size_block_down;
    while (size_a)
    {
        (*list) = (*list)->next;
		size_a--;
    }
    while(size_block_down)
    {
        if ((*list)->index == 0)
        {
            *list = tmp;
            return (save_size_block_down - c);
        }
        else
        {
            (*list) = (*list)->next;
            c++;
            size_block_down--;
        }
    }
    return (-1);
}

void    order(t_list **list)
{
    int top;
    int down;

    top = find_start_top(list);
	down = find_start_down(list);
    if ((top < down && top != -1) || down == -1)
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
